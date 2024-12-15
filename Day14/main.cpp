#include <iostream>
#include <vector>
#include <queue>

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

bool validPath(int n, vector<vector<int> > &edges, int source, int destination) {
    if (source == destination) { return true; }
    vector<vector<int> > adjList(n);
    for (auto i: edges) {
        int u = i[0];
        int v = i[1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(source);
    visited[source] = true;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto neighbor: adjList[node]) {
            if (neighbor == destination) {
                return true;
            }
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return false;
}

void dfs(TreeNode *root, int height, int &curVal, int &curHeight) {
    if (!root) { return; }
    height++;
    dfs(root->left, height, curVal, curHeight);
    dfs(root->right, height, curVal, curHeight);
    if (height > curHeight) {
        curHeight = height;
        curVal = root->val;
    }
}

int findBottomLeftValue(TreeNode *root) {
    int result;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        if (node->right) {
            q.push(node->right);
        }
        if (node->left) {
            q.push(node->left);
        }
        result=node->val;
    }
    return result;
}

int main() {
    vector<vector<int> > edges = {{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}};
    cout << validPath(6, edges, 0, 5) << endl;
    return 0;
}
