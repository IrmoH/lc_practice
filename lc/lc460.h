#include <unordered_map>
#include <climits>

using namespace std;

struct Node {
    Node(int key, int value) {
        key_ = key;
        value_ = value;
        freq_ = 1;
    }

    Node *next_;
    Node *prior_;
    int key_;
    int value_;
    int freq_;
};

//循环双向链表
class DoubleLinkedList {
public:
    DoubleLinkedList() {
        head_ = new Node(-1, -1);
        head_->next_ = head_;
        head_->prior_ = head_;
        size_ = 0;
    }

    void addFirst(Node *node) {
        node->next_ = head_->next_;
        head_->next_->prior_ = node;
        head_->next_ = node;
        node->prior_ = head_;
        size_++;
    }

    Node *removeLast() {
        auto node = head_->prior_;
        node->prior_->next_ = head_;
        head_->prior_ = node->prior_;
        size_--;
        return node;
    }

    void remove(Node *node) {
        node->prior_->next_ = node->next_;
        node->next_->prior_ = node->prior_;
        size_--;
    }

    int size() {
        return size_;
    }

private:
    int size_;
    Node *head_;
};


class LFUCache {
public:
    LFUCache(int capacity) {
        capacity_ = capacity;
        min_freq_ = 0;
    }

    int get(int key) {
        if (cache_.find(key) == cache_.end()) {
            return -1;
        }
        auto node = cache_[key];
        removeNodeFromFreqMap(node);
        node->freq_++;
        addNodeToFreqMap(node);
        return node->value_;
    }

    void put(int key, int value) {
        if (cache_.find(key) == cache_.end()) {
            Node *node = new Node(key, value);
            if (cache_.size() == capacity_) {
                auto remove = freq_map_[min_freq_]->removeLast();
                cache_.erase(remove->key_);
            }
            cache_[key] = node;
            addNodeToFreqMap(node);
            min_freq_ = 1;
        } else {
            auto node = cache_[key];
            node->value_ = value;
            removeNodeFromFreqMap(node);
            node->freq_++;
            addNodeToFreqMap(node);
        }
    }

private:
    int capacity_;
    int min_freq_;
    unordered_map<int, Node *> cache_;
    unordered_map<int, DoubleLinkedList *> freq_map_;

    void addNodeToFreqMap(Node *node) {
        if (freq_map_.find(node->freq_) == freq_map_.end()) {
            freq_map_[node->freq_] = new DoubleLinkedList();
        }
        freq_map_[node->freq_]->addFirst(node);
    }

    void removeNodeFromFreqMap(Node *node) {
        auto list = freq_map_[node->freq_];
        list->remove(node);
        if (min_freq_ == node->freq_ && list->size() == 0) {
            min_freq_ = node->freq_ + 1;
        }
    }
};
//LFU： 双哈希表+双向链表
