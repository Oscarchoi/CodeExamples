/**
 * 1457.Pseudo-Palindromic Paths in a Binary Tree
 */

#include <vector>
using namespace std;

// Definition for a binary tree node.
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
  int pseudoPalindromicPaths(TreeNode *root) {
    if (!root)
      return 0;
    vector<int> nums(10);
    dfs(root, nums);
    return res;
  }

  void dfs(TreeNode *node, vector<int> &nums) {
    nums[node->val] ^= 1;
    if (!node->left && !node->right) {
      int tmp = 0;
      for (auto i : nums)
        tmp += i;
      if (tmp < 2)
        res++;
    }

    if (node->left)
      dfs(node->left, nums);
    if (node->right)
      dfs(node->right, nums);

    nums[node->val] ^= 1;
  }

  int res = 0;
};