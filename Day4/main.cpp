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
//对称二叉树，树对称当且仅当其左子树与右子树镜像对称，所以问题转为2棵树是否镜像对称
//2棵树（a，b）镜像对称当且仅当根节点val相等，a的左子树与b的右子树镜像对称，a的右子树与b的左子树镜像对称
class Solution {
public:
    bool symmetric(TreeNode *left, TreeNode *right) {
        if (!left && !right) { return true; }
        if ((!left && right) || (!right && left)) { return false; }
        return left->val == right->val && symmetric(left->left, right->right) && symmetric(left->right, right->left);
    }

    bool isSymmetric(TreeNode *root) {
        return symmetric(root->left, root->right);
    }
    //翻转二叉树
    TreeNode* invertTree(TreeNode* root) {
        if (!root){return nullptr;}
        TreeNode* n=root->left;
        root->left=invertTree(root->right);
        root->right=invertTree(n);
        return root;
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(2);
    TreeNode *node4 = new TreeNode(2);
    TreeNode *node5 = new TreeNode(2);
    node2->left = node4;
    node3->left = node5;
    root->left = node2;
    root->right = node3;
    Solution s;
    cout << s.isSymmetric(root) << endl;

    return 0;
}
