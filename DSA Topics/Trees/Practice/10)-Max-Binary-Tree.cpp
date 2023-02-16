Maximum Binary Tree

You are given an integer array nums with no duplicates. A maximum binary tree can be built recursively from nums using the following algorithm:

Create a root node whose value is the maximum value in nums.
Recursively build the left subtree on the subarray prefix to the left of the maximum value.
Recursively build the right subtree on the subarray suffix to the right of the maximum value.
Return the maximum binary tree built from nums.
    
class Solution {
private:
    TreeNode* help(int start,int end,vector<int>& nums){
        
        if(start>end) return NULL;
        
        int maxi=0;
        int maxIdx=start;
        for(int i=start;i<=end;i++){
            if(maxi<nums[i]){
                maxi=nums[i];
                maxIdx=i;
            }
        }
        TreeNode* root=new TreeNode(maxi);
        
        root->left=help(start,maxIdx-1,nums);
        root->right=help(maxIdx+1,end,nums);
        
        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        return help(0,nums.size()-1,nums);
    }
};