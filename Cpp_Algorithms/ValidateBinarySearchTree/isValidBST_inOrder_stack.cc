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
    stack<TreeNode*> st;
    bool flag = true;
    int prev = 0;      
    while(!st.empty() || root){        
      while(root){
        st.push(root);
        root=root->left;
      }        
      root = st.top();
      st.pop();
      
      if(flag) flag=false;          
      else if(root->val <= prev) return false;        
      prev=root->val;        
      root = root->right;
    }
    return true;      
  }
};