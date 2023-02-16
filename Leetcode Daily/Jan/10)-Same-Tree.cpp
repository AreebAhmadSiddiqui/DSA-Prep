class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // if(p==NULL && q!=NULL || p!=NULL && q==NULL || (p!=NULL && q!=NULL && p->val!=q->val)) return false;
        // if(p==NULL && q==NULL) return true;
        
        
        // if(isSameTree(p->left,q->left) && isSameTree(p->right,q->right)) return true;
        
        // return false;

        Clean Wala

        if(p==NULL || q==NULL) return p==q; // they should be same otherwise return false;
        
        return p->val==q->val && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};