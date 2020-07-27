#include <algorithm>
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
  int rob(TreeNode *root) {
    auto tmp = helper(root);
    return max(tmp.first, tmp.second);
  }

  pair<int, int> helper(TreeNode *root) {
    if (!root)
      return {0, 0};
    auto rtmp = helper(root->right);
    auto ltmp = helper(root->left);
    // { with, without }
    return {root->val + rtmp.second + ltmp.second,
            max(rtmp.first, rtmp.second) + max(ltmp.first, ltmp.second)};
  }
};