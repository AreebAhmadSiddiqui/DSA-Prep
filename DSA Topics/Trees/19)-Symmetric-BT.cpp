class Solution {
private:
    bool help(TreeNode *root1,TreeNode* root2){
        // ye uss case ko handle kar rha ki ek null hai doosra ni ya fir dono null hai
        if(root1==NULL || root2==NULL) return root1==root2;
        
        
        return root1->val==root2->val && help(root1->left,root2->right) && help(root1->right,root2->left);;
    }
public:
    bool isSymmetric(TreeNode* root) {
        return help(root->left,root->right);
    }
};