
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        
        // O(logN) O(logN)
//         if(root==NULL) return NULL;
        
//         if(val==root->val){
//             return root;
//         }
//         else if(val<root->val){
//             return searchBST(root->left,val);
//         }
        
//         return searchBST(root->right,val);
        
        // O(logN) O(1)
        while(root!=NULL){
            if(root->val==val){
                return root;
            }
            else if(val<root->val){
                root=root->left;
            }
            else root=root->right;
        }
        
        return root;
    }
};