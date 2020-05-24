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
  int maxDepth(TreeNode *root) {
    if (!root)
      return 0;

    int res = 0, level = 0;
    dfs(root, level, res);
    return res;
  }

  void dfs(TreeNode *node, int &level, int &res) {
    level++;
    if (level > res)
      res = level;
    if (node->left)
      dfs(node->left, level, res);
    if (node->right)
      dfs(node->right, level, res);
    level--;
  }
};