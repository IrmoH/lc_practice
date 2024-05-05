struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode *make_list(vector<int> &&vec) {
    ListNode *head = new ListNode();
    auto next = head;
    for (auto item: vec) {
        next->next = new ListNode(item);
        next = next->next;
    }
    return head;
}