class Solution
{
    public:
    
    TC -> O(N)
    SC-> O(n)
    vector<vector<int>> levelOrder(TreeNode* root) {
     
      if(root==NULL) return {};
      vector<vector<int>> ans;
      queue<TreeNode*> q;
      q.push(root);
      
      while(!q.empty()){
          int size=q.size();
          vector<int> level;
          for(int i=0;i<size;i++){
              TreeNode* node=q.front();
              q.pop();
              
              level.push_back(node->val);
              
              if(node->left!=NULL)  q.push(node->left);
              if(node->right!=NULL) q.push(node->right);
          }
          ans.push_back(level);
      }
      return ans;
    }
};
};