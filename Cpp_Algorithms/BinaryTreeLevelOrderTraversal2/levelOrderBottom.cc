#include <algorithm>
#include <vector>
using namespace std;

/* Definition for a binary tree node. */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  vector<vector<int>> levelOrderBottom(TreeNode *root) {
    vector<vector<int>> res;
    if (!root)
      return res;

    vector<TreeNode *> current, next;
    next.push_back(root);
    while (!next.empty()) {
      current.clear();
      current.swap(next);
      vector<int> row;
      for (auto &node : current) {
        row.push_back(node->val);
        if (node->left)
          next.push_back(node->left);
        if (node->right)
          next.push_back(node->right);
      }
      res.emplace_back(std::move(row));
    }
    std::reverse(res.begin(), res.end());
    return res;
  }
};