#include <iostream>

#include "list_node.h"

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        auto q = head->next;
        auto prev = head;
        prev->next = nullptr;
        while (q != nullptr) {
            auto next = q->next;
            q->next = prev;

            prev = q;
            q = next;
        }
        return prev;
    }
};
