Sum of Nodes with Even-Valued Grandparent

Intuition
Let children know who their grandparent is.

Given the root of a binary tree, return the sum of values of nodes with an even-valued grandparent. If there are no nodes with an even-valued grandparent, return 0.

A grandparent of a node is the parent of its parent if it exists.
    
class Solution {
private:
//     int help(TreeNode* root,TreeNode* parent,TreeNode* grandParent){
//         if(root==NULL) return 0;
        
//         int left=help(root->left,root,parent);
//         int right=help(root->right,root,parent);
        
//         int sum=0;
//         if(grandParent && grandParent->val%2==0) sum+=root->val;
        
//         return sum+left+right;
//     }
    int help(TreeNode* root,TreeNode* parent,TreeNode* grandParent){
        if(root==NULL) return 0;
        
        int left=help(root->left,root,parent);
        int right=help(root->right,root,parent);
        
        return (grandParent && grandParent->val%2==0) ? root->val+left+right : left+right;
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        
        return help(root,NULL,NULL);
    }
};