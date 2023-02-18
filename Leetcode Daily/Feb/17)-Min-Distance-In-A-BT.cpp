Minimum Distance Between BST Nodes

Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree. ( BST hai to sorted hoga to min diff successive nodes ka hi hoga )

 
class Solution {
private:
    void help(TreeNode* root,int &ans,int &prev){
        if(root==NULL) return;
        
        help(root->left,ans,prev);
        
        ans=min(ans,abs(root->val-prev));
        prev=root->val; 
        
        help(root->right,ans,prev);
                
    }
public:
    int minDiffInBST(TreeNode* root) {
        int ans=1e9;
        int prev=1e9;
        help(root,ans,prev);
        return ans;
    }
};