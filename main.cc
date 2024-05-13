#include <iostream>
#include <cstring>
#include <random>
#include <deque>
#include <queue>
#include <list>
#include <forward_list>
#include <execution>
#include <mutex>

#include "tool/print_everything.h"
#include "thread_pool.h"

#include "lc/lc986.h"

void process(int &x) {
    //do some calculate
}

int main() {
    int a[] = {0, 1, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> v;
    std::mutex m;
    std::for_each(std::execution::par, std::begin(a), std::end(a), [&](int i) {
        std::lock_guard<std::mutex> lock(m);
        v.push_back(i * 2 + 1); // 错误：数据竞争
    });
    print(v);
}



