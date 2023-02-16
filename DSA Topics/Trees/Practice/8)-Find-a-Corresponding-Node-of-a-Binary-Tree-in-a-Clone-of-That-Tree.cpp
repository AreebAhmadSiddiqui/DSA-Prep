Find a Corresponding Node of a Binary Tree in a Clone of That Tree

Given two binary trees original and cloned and given a reference to a node target in the original tree.

The cloned tree is a copy of the original tree.

Return a reference to the same node in the cloned tree.

Note that you are not allowed to change any of the two trees or the target node and the answer must be a reference to a node in the cloned tree.

class Solution {
private:
    // Jab duplicates ni honge to aise kar sakte ho 
    
//     TreeNode* inOrder(TreeNode* root,int target){
//         if(root==NULL) return NULL;
        
//         TreeNode* left=inOrder(root->left,target);
        
//         if(root->val==target) return root;
            
//         TreeNode* right=inOrder(root->right,target);
        
//         if(left || right) return left ? left : right;
        
//         return NULL;
//     }
    
    // Jab duplicates ni honge to aise kar sakte ho 
    // Lekin agar duplicated hon to dono ko ek  saath traverse karo
     TreeNode* inOrder(TreeNode* root1,TreeNode* root2,TreeNode* target){
        if(root1==NULL) return NULL;
        
        TreeNode* left=inOrder(root1->left,root2->left,target);
        
        if(root1->val==target->val) return root2;
            
        TreeNode* right=inOrder(root2->right,root2->right,target);
        
        if(left || right) return left ? left : right;
        
        return NULL;
    }
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        return inOrder(original,cloned,target);
    }
};