#include <vector>
#include <queue>
#include <functional>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    struct Item {
        int val;
        ListNode *p;

        //构造最小堆
        bool operator<(const Item &other) const {
            return val > other.val;
        }
    };

    priority_queue<Item> q_;

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        for (auto node: lists) {
            if (node != nullptr) {
                q_.push({node->val, node});
            }
        }
        ListNode head;
        ListNode *tail = &head;

        while (!q_.empty()) {
            //取出最小值
            auto small = q_.top();
            q_.pop();

            tail->next = small.p;
            tail = tail->next;

            if (tail->next != nullptr) {
                q_.push({tail->next->val, tail->next});
            }
        }

        return head.next;
    }
};
//合并K个升序链表：使用优先级队列