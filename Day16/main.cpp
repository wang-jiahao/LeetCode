#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
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

void inorder(TreeNode *root, vector<int> &in_order_root) {
    if (!root) { return; }
    inorder(root->left, in_order_root);
    in_order_root.push_back(root->val);
    inorder(root->right, in_order_root);
}

vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
    vector<int> in_order_root1;
    vector<int> in_order_root2;
    vector<int> result;
    inorder(root1, in_order_root1);
    inorder(root2, in_order_root2);
    int i = 0;
    int j = 0;
    while (i < in_order_root1.size() && j < in_order_root2.size()) {
        if (in_order_root1[i] <= in_order_root2[j]) {
            result.push_back(in_order_root1[i]);
            ++i;
        } else {
            result.push_back(in_order_root2[j]);
            ++j;
        }
    }
    while (i < in_order_root1.size()) {
        result.push_back(in_order_root1[i]);
        i++;
    }
    while (j < in_order_root2.size()) {
        result.push_back(in_order_root2[j]);
        j++;
    }
    return result;
}

void convert(TreeNode *root, vector<int> in_order, int &k, int &sum) {
    if (!root) { return; }
    convert(root->left, in_order, k, sum);
    if (k > 0) { sum -= in_order[k - 1]; }
    root->val = sum;
    k++;
    convert(root->right, in_order, k, sum);
}

TreeNode *convertBST(TreeNode *root) {
    vector<int> in_order;
    inorder(root, in_order);
    int k = 0;
    int sum = accumulate(in_order.begin(), in_order.end(), 0);
    convert(root, in_order, k, sum);
    return root;
}


int main() {
    TreeNode *left1 = new TreeNode(1);
    TreeNode *right1 = new TreeNode(4);
    TreeNode *root1 = new TreeNode(2, left1, right1);
    TreeNode *left2 = new TreeNode(0);
    TreeNode *right2 = new TreeNode(3);
    TreeNode *root2 = new TreeNode(1, left2, right2);
    auto result = getAllElements(root1, root2);
    copy(result.begin(), result.end(), ostream_iterator<int>(cout, " "));

    return 0;
}
