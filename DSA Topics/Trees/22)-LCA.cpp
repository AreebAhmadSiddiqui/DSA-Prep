STEPS

a) Maine socha ki dekho agar mere left mein koi node return hua hai iska matlab ek node mil gaya aur agar mere right mein bhi ek node return hua hai to iska matlab lca hun main kyunki agar dono se taraf se node return honge tabhi lca honga main

b) Doosra agar koi node null hai to jo null na ho use return kar do

c) ek case thora tha doubt lekin wo anjane mein cover ho gaya jab ek hi subtree mein ho dono bande
d) to uske liye bhi simply return kar do agar koi bhi node mile agar wo banda isi subtree mein hua tab to yahi answer hoga aur agar na bhi hua to upar kahin se return hoke aega to wahan answer ban jaega isliye koi dikkat ni

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(root==NULL) return NULL;
       
       if(root->val==p->val || root->val==q->val){
           return root;
       }
       
       TreeNode* leftNode=lowestCommonAncestor(root->left,p,q);
       TreeNode* rightNode=lowestCommonAncestor(root->right,p,q);
       
       if(leftNode!=NULL && rightNode!=NULL){ // we got our answer
           return root;
       }
       
       return leftNode!=NULL ? leftNode : rightNode; // otherwise return that answer which is not null
    }
};