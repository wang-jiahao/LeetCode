#include <iostream>
#include <vector>
#include <unordered_map>
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
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> freq_map;
        for (int num: nums) {
            freq_map[num]++;
        }
        vector<vector<int> > bucket(nums.size() + 1);
        for (auto &[key,freq]: freq_map) {
            bucket[freq].push_back(key);
        }
        vector<int> top;
        for (int i = nums.size(); i > 0; --i) {
            for (auto j: bucket[i]) {
                top.push_back(j);
                if (top.size() == k) { break; }
            }
            if (top.size() == k) { break; }
        }
        return top;
    }

    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
        if (!root1) { return root2; }
        if (!root2) { return root1; }
        root1->val = root1->val + root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};

int main() {
    return 0;
}
