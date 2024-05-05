#include <iostream>
#include "list_node.h"

using namespace std;

class Solution {
public:
    Solution(ListNode *head) {
        head_ = head;
        auto p = head;
        while (p != nullptr) {
            p = p->next;
            size_++;
        }
    }

    int getRandom() {
        int r = rand() % size_;
        ListNode *p = head_;
        while (r-- > 0) {
            p = p->next;
        }
        return p->val;
    }

private:
    int size_{0};
    ListNode *head_;
};
