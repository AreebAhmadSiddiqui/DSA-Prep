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
    int help(TreeNode* root){
        if(root==NULL) return 0;
        
        int leftHeight=help(root->left);
        int rightHeight=help(root->right);
        
        // if any time leftHeight or rightHeight == -1 it means not balanced return -1
        if(leftHeight==-1 || rightHeight==-1) return -1;
    
        // check for balanced case
        
        if(abs(leftHeight-rightHeight) > 1) return -1;
        
        return max(leftHeight,rightHeight)+1;
    }
public:
    bool isBalanced(TreeNode* root) {
        return help(root)!=-1;
    }
};