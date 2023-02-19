Count Good Nodes in Binary Tree

Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.
    
a) Har path pe max variable lete jao aur check kar lo mujhse bada na ho bas agar bada hai to left+right otherwise mujhe bhi add kar lo
b) max hi kyun abe agar root ki val ab tak ke max se bhi badi hogi tab to pakka good node hai na isliye

class Solution {
private:
    int help(TreeNode* root,int maxTillNow){
        if(root==NULL) return 0;
        
        int left=help(root->left,max(maxTillNow,root->val));
        int right=help(root->right,max(maxTillNow,root->val));
        
        return maxTillNow<=root->val ? left+right+1 : left+right; // plus 1 matlab main bhi us path ka part hun jsimein mujhse bada koi ni hai
    }
public:
    int goodNodes(TreeNode* root) {
        return help(root,INT_MIN);
    }
};