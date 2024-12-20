#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
    }
};

void postorder(TreeNode *root, vector<int> &result) {
    if (!root) { return; }
    postorder(root->left, result);
    postorder(root->right, result);
    result.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode *root) {
    vector<int> result;
    postorder(root, result);
    return result;
}

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

ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {
    ListNode *head = list1;
    int dis = b - a + 2;
    a--;
    while (a--) {
        head = head->next;
    }
    auto head1 = head;
    while (dis--) {
        head = head->next;
    }
    auto head2 = list2;
    while (head2->next) {
        head2 = head2->next;
    }
    head2->next = head;
    head1->next = list2;
    return list1;
}

int main() {
    return 0;
}
