#pragma clang diagnostic push
#pragma ide diagnostic ignored "NullDereference"
#pragma ide diagnostic ignored "google-explicit-constructor"
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode *make_list(vector<int> &&vec) {
    auto head = new ListNode();
    auto next = head;
    for (auto item: vec) {
        next->next = new ListNode(item);
        next = next->next;
    }
    return head;
}
#pragma clang diagnostic pop