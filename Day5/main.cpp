#include <iostream>
#include <vector>
#include <string>
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

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> paths;
        if (!root->left && !root->right) {
            paths.push_back(to_string(root->val));
            return paths;
        }
        string path_root = to_string(root->val) + "->";
        if (root->left) {
            for (auto path: binaryTreePaths(root->left)) {
                string new_path = path_root + path;
                paths.push_back(new_path);
            }
        }
        if (root->right) {
            for (auto path: binaryTreePaths(root->right)) {
                string new_path = path_root + path;
                paths.push_back(new_path);
            }
        }
        return paths;
    }

    int countNodes(TreeNode *root) {
        if (!root) {
            return 0;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

int main() {
    return 0;
}
