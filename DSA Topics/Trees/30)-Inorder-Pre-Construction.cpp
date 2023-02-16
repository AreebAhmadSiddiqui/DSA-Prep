class Solution {
private:
    TreeNode* dfs(int inStart,int inEnd,int preStart,int preEnd,vector<int> &preorder,vector<int> &inorder,unordered_map<int,int> &mp){
        
        if(preStart>preEnd || inStart>inEnd) return NULL;
        
        TreeNode* root=new TreeNode(preorder[preStart]);
        
        int posInInorder=mp[preorder[preStart]];
        
        root->left=dfs(inStart,posInInorder,preStart+1,preStart+1+(posInInorder-inStart-1),preorder,inorder,mp);
        root->right=dfs(posInInorder+1,inEnd,preStart+1+(posInInorder-inStart-1)+1,preEnd,preorder,inorder,mp);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp; // {value,indx}
        
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        
        int n=preorder.size();
        return dfs(0,n-1,0,n-1,preorder,inorder,mp);
    }
};