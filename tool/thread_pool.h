#pragma once
#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <atomic>
#include <condition_variable>
#include <functional>
#include <future>
#include <queue>
#include <stdexcept>
#include <thread>
#include <vector>

//线程池最大容量,应尽量设小一点
#define THREADPOOL_MAX_NUM 16
//线程池是否可以自动增长(如果需要,且不超过 THREADPOOL_MAX_NUM)
#define THREADPOOL_AUTO_GROW

//线程池,可以提交变参函数或拉姆达表达式的匿名函数执行,可以获取执行返回值
//不直接支持类成员函数, 支持类静态成员函数或全局函数, operator()函数等
class ThreadPool {
public:
    ThreadPool() = delete;

    explicit ThreadPool(unsigned short size = 4) {
        init_size_ = size;
        addThread(size);
    }

    inline ~ThreadPool() {
        run_ = false;
        task_cv_.notify_all();// 唤醒所有线程执行
        for (std::thread &thread: pool_) {
            //thread.detach(); // 让线程“自生自灭”
            if (thread.joinable())
                thread.join();// 等待任务结束， 前提：线程一定会执行完
        }
    }

public:
    // 提交一个任务
    // 调用.get()获取返回值会等待任务执行完,获取返回值
    // 有两种方法可以实现调用类成员，
    // 一种是使用   bind： .commit(std::bind(&Dog::sayHello, &dog));
    // 一种是用   mem_fn： .commit(std::mem_fn(&Dog::sayHello), this)
    template<class F, class... Args>
    auto commit(F &&f, Args &&...args) -> std::future<decltype(f(args...))> {
        if (!run_) {
            throw runtime_error("commit on ThreadPool is stopped.");
        }

        using RetType = decltype(f(args...));// typename std::result_of<F(Args...)>::type, 函数 f 的返回值类型
        // 打包成packaged_task为了可以拿到future
        auto task = std::make_shared<std::packaged_task<RetType()>>(
            std::bind(std::forward<F>(f), std::forward<Args>(args)...));// 把函数入口及参数,打包(绑定)
        std::future<RetType> future = task->get_future();               // get_future以绑定一个future
        {                                                               // 添加任务到队列
            //对当前块的语句加锁  lock_guard 是 mutex 的 stack 封装类，构造的时候 lock()，析构的时候 unlock()
            std::lock_guard<std::mutex> lock{lock_};
            tasks_.emplace([task]() {
                (*task)();
            });
        }
#ifdef THREADPOOL_AUTO_GROW
        if (idle_thread_num_ < 1 && pool_.size() < THREADPOOL_MAX_NUM) {
            addThread(1);
        }
#endif
        task_cv_.notify_one();// 唤醒一个线程执行
        return future;
    }

    //空闲线程数量
    size_t idlCount() { return idle_thread_num_; }

    //线程数量
    size_t thrCount() { return pool_.size(); }

    //添加指定数量的线程
    void addThread(unsigned short num) {
#ifdef THREADPOOL_AUTO_GROW
        if (!run_) {
            throw runtime_error("Grow on ThreadPool is stopped.");
        }
        std::unique_lock<std::mutex> lockGrow{lock_grow_};//自动增长锁
#endif
        for (; pool_.size() < THREADPOOL_MAX_NUM && num > 0; --num) {//增加线程数量,但不超过 预定义数量 THREADPOOL_MAX_NUM
            pool_.emplace_back([this] {                              //工作线程函数
                while (true) {
                    Task task;// 获取一个待执行的 task
                    {
                        // unique_lock 相比 lock_guard 的好处是：可以随时 unlock() 和 lock()
                        std::unique_lock<std::mutex> lock{lock_};
                        task_cv_.wait(lock, [this]() {// wait 直到有 task, 或需要停止
                            return !run_ || !tasks_.empty();
                        });
                        if (!run_ && tasks_.empty()) {
                            return;
                        }
                        idle_thread_num_--;
                        task = std::move(tasks_.front());// 按先进先出从队列取一个 task
                        tasks_.pop();
                    }
                    task();//执行任务
#ifdef THREADPOOL_AUTO_GROW
                    if (idle_thread_num_ > 0 && pool_.size() > init_size_) {//支持自动释放空闲线程,避免峰值过后大量空闲线程
                        return;
                    }
#endif
                    {
                        std::unique_lock<std::mutex> lock{lock_};
                        idle_thread_num_++;
                    }
                }
            });
            {
                std::unique_lock<std::mutex> lock{lock_};
                idle_thread_num_++;
            }
        }
    }

private:
    using Task = function<void()>;//定义类型
    unsigned short init_size_;    //初始化线程数量
    std::vector<thread> pool_;    //线程池
    std::queue<Task> tasks_;      //任务队列
    std::mutex lock_;             //任务队列同步锁
#ifdef THREADPOOL_AUTO_GROW
    std::mutex lock_grow_;//线程池增长同步锁
#endif
    std::condition_variable task_cv_;       //条件阻塞
    std::atomic<bool> run_{true};           //线程池是否执行
    std::atomic<size_t> idle_thread_num_{0};//空闲线程数量
};

#endif
//https://github.com/lzpong/
