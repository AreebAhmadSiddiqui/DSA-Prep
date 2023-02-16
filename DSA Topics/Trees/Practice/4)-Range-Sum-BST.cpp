Range Sum of BST

Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].
    
// Agar range se chota hai ya bada hai tab na jao us subtree mein to bach sakti hai kuch calls lekin worst case mein poora traverse karega
    
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        
        if(root==NULL) return 0;
        
        int nodeSum=0;
        if(root->val>=low && root->val<=high) nodeSum+=root->val;
        
        int leftTree=root->val <low ? 0 : rangeSumBST(root->left,low,high); // agar range se bahar hai to na jao jaoge fir bhi answer aega lekin kya fayda
        int rightTree=root->val > high ? 0 : rangeSumBST(root->right,low,high); // agar range se bahar hai to na jao jaoge fir bhi answer aega lekin kya fayda
        
        return nodeSum+leftTree+rightTree;
    }
};