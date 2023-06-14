530. Minimum Absolute Difference in BST

Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.
    
    
class Solution {
private:
    void getMinDiff(TreeNode* root,int &ans,int &prev){
        if(root==NULL) return;
        
        getMinDiff(root->left,ans,prev);
        if(prev!=-1) ans=min(ans,root->val-prev);
        prev=root->val;
        getMinDiff(root->right,ans,prev);
        
    }
public:
    int getMinimumDifference(TreeNode* root) {
        
        int ans=1e9;
        int prev=-1;
        getMinDiff(root,ans,prev);
        
        return ans;
    }
};