#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {
    }

    ListNode(int x) : val(x), next(nullptr) {
    }

    ListNode(int x, ListNode *next) : val(x), next(next) {
    }
};

class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {
        if (!head) { return nullptr; }
        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head;
    }
};

int main() {
    Solution s;
    ListNode *head = new ListNode(1);
    ListNode *second = new ListNode(2);
    head->next = second;
    for (auto i = head; i != nullptr; i = i->next) {
        cout << i->val << " ";
    }
    auto n = s.removeElements(head, 2);
    for (auto i = n; i != nullptr; i = i->next) {
        cout << i->val << " ";
    }

    return 0;
}
