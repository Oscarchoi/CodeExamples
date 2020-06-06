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
  bool isSymmetric(TreeNode *root) {
    if (root == nullptr)
      return true;

    if (root->left != nullptr && root->right != nullptr) {
      return isSymmetric(root->left, root->right);
    } else if (root->left != nullptr || root->right != nullptr) {
      return false;
    } else {
      return true;
    }
  }

  bool isSymmetric(TreeNode *lhs, TreeNode *rhs) {
    if (lhs == nullptr && rhs == nullptr)
      return true;
    if (lhs == nullptr || rhs == nullptr)
      return false;
    return (lhs->val == rhs->val) && (isSymmetric(lhs->left, rhs->right)) &&
           (isSymmetric(lhs->right, rhs->left));
  }
};