class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {            
      vector<vector<int>> res;      
      if(!root) return res;
      
      queue<pair<int,TreeNode*>> q;      
      q.push({0,root});      
      while(!q.empty()){
        auto p = q.front();
        q.pop();
        if(res.size()==p.first) res.push_back({p.second->val});
        else res[p.first].push_back(p.second->val);
        if(p.second->left) q.push({p.first+1,p.second->left});
        if(p.second->right) q.push({p.first+1, p.second->right});        
      }
      return res;
    }
};
