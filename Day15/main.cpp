#include <iostream>

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

void preorder(TreeNode *root, int &maximum, int val) {
    if (!root) { return; }
    maximum = max(maximum, abs(val - root->val));
    preorder(root->left, maximum, val);
    preorder(root->right, maximum, val);
}

int maxAncestorDiff(TreeNode *root) {
    if (!root) { return 0; }
    int maximum = 0;
    int val = root->val;
    preorder(root, maximum, val);
    return max(maximum, max(maxAncestorDiff(root->left), maxAncestorDiff(root->right)));
}

void inorder(TreeNode *root, int &k, int &result) {
    if (!root) { return; }
    inorder(root->left, k, result);
    k--;
    if (k == 0) {
        result = root->val;
        return;
    }
    inorder(root->right, k, result);
}

int kthSmallest(TreeNode *root, int k) {
    int result = root->val;
    inorder(root, k, result);
    return result;
}

int main() {
    return 0;
}
