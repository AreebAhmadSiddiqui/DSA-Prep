Delete Leaves With a Given Value

Given a binary tree root and an integer target, delete all the leaf nodes with value target.

Note that once you delete a leaf node with value target, if its parent node becomes a leaf node and has the value target, it should also be deleted (you need to continue doing that until you cannot).
    
DFS karo aur agar leaf hai node to delte kar do
    
    Ye wala mera solution
// class Solution {
// private:
//     bool isLeaf(TreeNode* root){
//         return !root->left && !root->right;
//     }
// public:
//     TreeNode* removeLeafNodes(TreeNode* root, int target) {
        
//         if(root==NULL) return NULL;
        
//         if(isLeaf(root)){
//             if(root->val==target) return NULL;
//             else return root;
//         }
        
//         TreeNode* left=removeLeafNodes(root->left,target);
//         TreeNode* right=removeLeafNodes(root->right,target);
        
//         if(left==NULL || right==NULL){ 
//             if(left==NULL) root->left=NULL;
//             if(right==NULL) root->right=NULL;
            
//             if(left==NULL && right==NULL){
//                 if(root->val==target) return NULL;
//             }
            
//         }
        
//         return root;
//     }
// };


Ye clean solution
class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        
        if(root==NULL) return NULL;
        
        TreeNode* left=removeLeafNodes(root->left,target);
        TreeNode* right=removeLeafNodes(root->right,target);
        
        root->left=left; //agar left se null aya matlab ya to delte hua hoga ya to null hoga pehle se hi
        root->right=right; //agar right se null aya matlab ya to delte hua hoga ya to null hoga pehle se hi
        
        return left==NULL && right==NULL && root->val==target ? NULL : root;
    }
};