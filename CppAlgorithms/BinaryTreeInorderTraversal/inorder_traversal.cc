#include <vector>
using namespace std;

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
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> res;
    inOrder(root, res);
    return res;
  }

  void inOrder(TreeNode *node, vector<int> &res) {
    if (!node)
      return;
    if (node->left)
      inOrder(node->left, res);
    res.push_back(node->val);
    if (node->right)
      inOrder(node->right, res);
  }
};