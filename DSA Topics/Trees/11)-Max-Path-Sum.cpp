class Solution {

    Steps

    a) Yahan ham max sum wala path nikal rahe aur saath hi main maxPathSum store kar rahe
    b) ek cheeck ka dhyan dena ki agar kahin se neg path sum a jae to usi na lena
    c) main logic ye hai ki mujhe left se max path wala sum de do aur right se max path wala sum de do aur main usmein jud jao fir dekho max hota hai ki ni
private:
    int help(TreeNode* root,int &maxPathSumm){
        if(root==NULL) return 0;
        
        // to handle neg max wali condition laga di
        int leftSum=max(0,help(root->left,maxPathSumm));
        // to handle neg max wali condition laga di
        int rightSum=max(0,help(root->right,maxPathSumm));
        
        // mujhe lete hue maximum kitna answer aega
        maxPathSumm=max(maxPathSumm,root->val+leftSum+rightSum);
        
        // ye to simply left ya mein jo bada path hai use le lega
        return max(leftSum,rightSum)+root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        
        int maxPathSumm=INT_MIN;
        
        help(root,maxPathSumm);
        
        return maxPathSumm;
    }
};