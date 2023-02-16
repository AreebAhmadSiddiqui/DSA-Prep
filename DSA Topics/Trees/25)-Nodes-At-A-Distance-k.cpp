STEPS

a) Parent pointer bana lo
b) aur dfs kar do parent pe, left pe aur right pe
c) visited array leke chaloge to space bhadega
d) yahan simply parent node leke chal raha agar koi child dobaar isi node pe ane ki koshish kare to use parent counter kar lega

class Solution {
private:
    void dfs(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &mp,int k,TreeNode* parent,vector<int> &ans){
            
        if(root==NULL) return;
        
        if(k==0){
            ans.push_back(root->val);
            return;
        }

        // check left
        if(root->left!=parent)
            dfs(root->left,mp,k-1,root,ans);
        
        // check right
        if(root->right!=parent)
            dfs(root->right,mp,k-1,root,ans);
        
        // check parent
        if(mp[root]!=parent){
            dfs(mp[root],mp,k-1,root,ans);
        }
            
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        // Step 1
        
        // Create Parent Pointers
        unordered_map<TreeNode*,TreeNode*> mp;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            
            if(node->left){
                q.push(node->left);
                mp[node->left]=node; // left node's parent is node
            }
            if(node->right){
                q.push(node->right);
                mp[node->right]=node;
            }
        }
        
        
        //Step 2 do a dfs including parent , left and right pointers
        
        vector<int> ans;
        
        dfs(target,mp,k,target,ans); // {target->starting node, mp, k, parent };
        
        return ans;
    }
};