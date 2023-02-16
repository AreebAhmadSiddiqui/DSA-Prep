Path Sum II

Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.

class Solution {
private:
    bool isLeaf(TreeNode* root){
        return root->left==NULL && root->right==NULL;
    }
    void help(TreeNode* root,int targetSum,vector<vector<int>> &ans,vector<int> &ds){
        
        if(root==NULL) return;

        ds.push_back(root->val);
        
        if(isLeaf(root)){
            if(targetSum==root->val) ans.push_back(ds);
        }
        
        help(root->left,targetSum-root->val,ans,ds);
        help(root->right,targetSum-root->val,ans,ds);
        ds.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>> ans;
        vector<int> ds;
        help(root,targetSum,ans,ds);
        return ans;
    }
};