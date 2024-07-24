#include "list_node.h"

using namespace std;

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == nullptr) {
            return head;
        }
        int len = 1;
        ListNode *tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
            len++;
        }
        tail->next = head;

        ListNode *p = head;
        int step = 0;
        while (step < len - k % len) {
            p = p->next;
            step++;
        }
        head = p;

        while (true) {
            if (p->next == head) {
                p->next = nullptr;
                break;
            }
            p = p->next;
        }
        return head;
    }
};
