/* Definition for a binary tree node. */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == nullptr)
      return root;
    if (root->val == p->val || root->val == q->val) {
      return root;
    }

    TreeNode *ltmp = lowestCommonAncestor(root->left, p, q);
    TreeNode *rtmp = lowestCommonAncestor(root->right, p, q);
    if (ltmp == nullptr)
      return rtmp;
    if (rtmp == nullptr)
      return ltmp;
    return root;
  }
};