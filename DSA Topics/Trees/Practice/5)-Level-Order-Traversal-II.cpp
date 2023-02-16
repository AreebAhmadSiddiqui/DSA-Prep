class Solution {
public:
//     vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
//         if(root==NULL) return {};
//         vector<vector<int>> lvl;
//         queue<TreeNode*> q;
//         q.push(root);
        
//         while(!q.empty()){
            
//             vector<int> temp;
//             int size=q.size();
//             for(int i=0;i<size;i++){
                
//                 TreeNode* node=q.front();
//                 q.pop();
                
//                 temp.push_back(node->val);
                
//                 if(node->left) q.push(node->left);
//                 if(node->right) q.push(node->right);
//             }
//             lvl.push_back(temp);
//         }
        
//         reverse(lvl.begin(),lvl.end());
//         return lvl;
//     }
    
     vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        if(root==NULL) return {};
        
        queue<TreeNode*> q;
        q.push(root);
        int lvl=0;
        while(!q.empty()){
        
            int size=q.size();
            for(int i=0;i<size;i++){
                
                TreeNode* node=q.front();
                q.pop();
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            lvl++;
        }
        
        vector<vector<int>> lvlOrder(lvl);
        q.push(root);
         while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){

                TreeNode* node=q.front();
                q.pop();

                lvlOrder[lvl-1].push_back(node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            lvl--;
        }
        return lvlOrder;
    }
};