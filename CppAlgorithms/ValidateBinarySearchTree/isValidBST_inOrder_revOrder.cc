/* Definition for a binary tree node. */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  bool isValidBST(TreeNode* root) {
    if(!root) return true;      
    int l, r=l=root->val;      
    if(root->left && !revOrder(root->left,l)) return  false;
    if(root->right && !inOrder(root->right,r)) return false;
    return true;
  }    

  bool inOrder(TreeNode* node, int& prev){
    if(node->left && !inOrder(node->left,prev)) return false;
    if(node->val <= prev) return false;
    prev = node->val;
    if(node->right && !inOrder(node->right,prev)) return false;     
    return true;
  }
  
  bool revOrder(TreeNode* node, int& prev){
    if(node->right && !revOrder(node->right,prev)) return false;
    if(node->val >= prev) return false;
    prev = node->val;
    if(node->left && !revOrder(node->left,prev)) return false;     
    return true;
  }
};