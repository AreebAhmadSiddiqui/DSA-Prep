/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* dfs(int inStart,int inEnd,int postStart,int postEnd,vector<int> &postorder,vector<int> &inorder,unordered_map<int,int> &mp){
        
        if(postStart>postEnd || inStart>inEnd) return NULL;
        
        TreeNode* root=new TreeNode(postorder[postEnd]);
        
        int posInInorder=mp[postorder[postEnd]];
        int numbersToRight=inEnd-posInInorder;
        // Tum yahan pe leftnum se bhi nikal sakte kyunki left right root hota hai to jitne bande inorder ke left mein honge utne hi bande 1st se end tak postorder me left mein honge
        
        root->left=dfs(inStart,posInInorder-1,postStart,postEnd-numbersToRight-1,postorder,inorder,mp);
        root->right=dfs(posInInorder+1,inEnd,postEnd-numbersToRight,postEnd-1,postorder,inorder,mp);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp; // {value,indx}
        
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        
        int n=postorder.size();
        return dfs(0,n-1,0,n-1,postorder,inorder,mp);
    }
};
