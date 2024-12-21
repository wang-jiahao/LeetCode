#include <iostream>
#include <vector>

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

class Node {
public:
    int val;
    vector<Node *> children;

    Node() {
    }

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

void pre_order(Node *root, vector<int> &res) {
    if (!root) { return; }
    res.push_back(root->val);
    for (auto node: root->children) {
        pre_order(node, res);
    }
}

vector<int> preorder(Node *root) {
    vector<int> res;
    pre_order(root, res);
    return res;
}

TreeNode *sortedListToBST(ListNode *head) {
    if (!head) { return nullptr; }
    if (!(head->next)) { return new TreeNode(head->val); }
    auto h1 = head;
    int n = 1;
    while (h1->next) {
        h1 = h1->next;
        n++;
    }
    auto h2 = head;
    ListNode *prev = nullptr;
    int num = 1;
    while (true) {
        if (num == n / 2 + 1) {
            break;
        }
        prev = h2;
        h2 = h2->next;
        num++;
    }
    auto root = new TreeNode(h2->val);
    h2 = h2->next;
    prev->next = nullptr;
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(h2);

    return root;
}

int main() {
    return 0;
}
