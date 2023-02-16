class Solution {
public:
    
    // Find the leaf node where it would have been present if it were in the tree
    // and place it there
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        TreeNode* newNode=new TreeNode(val);
        if(root==NULL) return newNode;
        
        TreeNode* originalRoot=root;
        while(root!=NULL){
            if(root->val>val){ // bada hai to left subtree mein jao aur jahan chota hu wahan laga do
                if(root->left==NULL){
                    root->left=newNode;
                    break;
                }
                root=root->left;
            }
            else if(root->val<val){ // agar chota hai to right subtree mein jao aur jahan chota hu wahan laga do
                if(root->right==NULL)         {
                    root->right=newNode;
                    break;
                }
                root=root->right;
            }
        }
        
        return originalRoot;
    }
};