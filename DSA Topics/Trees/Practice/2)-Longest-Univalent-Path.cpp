Longest Univalue Path

Given the root of a binary tree, return the length of the longest path, where each node in the path has the same value. This path may or may not pass through the root.

The length of the path between two nodes is represented by the number of edges between them.

 class Solution {
int help(TreeNode* root,int &ans){
    if(root==NULL) return 0;
    
    int left=help(root->left,ans);
    int right=help(root->right,ans);
    
    left  = root->left && root->left->val==root->val ? left+1 : 0;
    right = root->right && root->right->val==root->val ? right+1 : 0;
    
    ans=max(ans,left+right);
    
    return max(left,right);
}
public:
    int longestUnivaluePath(TreeNode* root) {
        
        int ans=0;
        help(root,ans);
        return ans;
    }
}