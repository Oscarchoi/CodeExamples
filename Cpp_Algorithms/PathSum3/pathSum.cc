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
  int pathSum(TreeNode *root, int sum) {
    if (!root)
      return 0;
    int res = 0;
    res += subPathSum(root, sum);
    if (root->left)
      res += pathSum(root->left, sum);
    if (root->right)
      res += pathSum(root->right, sum);
    return res;
  }

  int subPathSum(TreeNode *root, int sum) {
    int res = 0;
    if (root->val == sum)
      res++;
    if (root->left)
      res += subPathSum(root->left, sum - root->val);
    if (root->right)
      res += subPathSum(root->right, sum - root->val);
    return res;
  }
};