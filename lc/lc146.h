#include <unordered_map>
#include <list>

using namespace std;

struct Node {
    Node(int key, int value) {
        key_ = key;
        value_ = value;
    }

    Node *next_;
    Node *prior_;
    int key_;
    int value_;
};

class DoubleLinkedList {
public:
    DoubleLinkedList() {
        head_ = new Node(-1, -1);
        head_->next_ = head_;
        head_->prior_ = head_;
    }

    void addFirst(Node *node) {
        head_->next_->prior_ = node;
        node->next_ = head_->next_;
        head_->next_ = node;
        node->prior_ = head_;
    }

    Node *removeLast() {
        auto last = head_->prior_;
        last->prior_->next_ = head_;
        head_->prior_ = last->prior_;
        return last;
    }

    void remove(Node *node) {
        node->prior_->next_ = node->next_;
        node->next_->prior_ = node->prior_;
    }

private:
    Node *head_;
};


class LRUCache {
public:
    LRUCache(int capacity) {
        list_ = new DoubleLinkedList();
        capacity_ = capacity;
    }

    int get(int key) {
        if (cache_.find(key) == cache_.end()) {
            return -1;
        }
        auto node = cache_[key];
        list_->remove(node);
        list_->addFirst(node);
        return node->value_;
    }

    void put(int key, int value) {
        if (cache_.find(key) == cache_.end()) {
            auto node = new Node(key, value);
            if (cache_.size() == capacity_) {
                auto remove = list_->removeLast();
                cache_.erase(remove->key_);
            }
            list_->addFirst(node);
            cache_[key] = node;
        } else {
            auto node = cache_[key];
            node->value_ = value;
            list_->remove(node);
            list_->addFirst(node);
        }
    }

private:
    unordered_map<int, Node *> cache_;
    DoubleLinkedList *list_;
    int capacity_;
};
//LRU：哈希表+双向链表
