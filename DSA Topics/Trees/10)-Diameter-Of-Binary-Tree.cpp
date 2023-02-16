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
    int help(TreeNode* root,int &maxi){
        if(root==NULL) return 0;
        
        int leftHeight=help(root->left,maxi);
        int rightHeight=help(root->right,maxi);
        
        maxi=max(maxi,leftHeight+rightHeight);
        
        return max(leftHeight,rightHeight)+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=INT_MIN;
        
        help(root,maxi);
        
        return maxi;
    }
};