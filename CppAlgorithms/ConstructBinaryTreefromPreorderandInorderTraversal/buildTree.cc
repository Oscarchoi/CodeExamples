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
private:
  TreeNode *buildSubTree(vector<int> &pr, vector<int> &ir, int p, int ii,
                         int ie) {
    if (ii > ie)
      return nullptr;

    TreeNode *node = new TreeNode(pr[p]);
    if (ii == ie)
      return node;

    /* Test Case
      [1,2,3,4,5]  divided   [1][2,3,4] | [5]
      [3,2,4,1,4]   into     [3,2,4][1] | [5]

      divided  [2,3,4]
       into    [3,2,4]
    */

    int idx = (int)(find(ir.begin() + ii, ir.begin() + ie, pr[p]) - ir.begin());
    node->left = buildSubTree(pr, ir, p + 1, ii, idx - 1);
    node->right = buildSubTree(pr, ir, p + idx - ii + 1, idx + 1, ie);
    return node;
  }

public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    return buildSubTree(preorder, inorder, 0, 0, preorder.size() - 1);
  }
};