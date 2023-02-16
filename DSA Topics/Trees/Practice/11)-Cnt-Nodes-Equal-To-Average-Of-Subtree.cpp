Count Nodes Equal to Average of Subtree

Given the root of a binary tree, return the number of nodes where the value of the node is equal to the average of the values in its subtree.

Note:

The average of n elements is the sum of the n elements divided by n and rounded down to the nearest integer.
A subtree of root is a tree consisting of root and all of its descendants.
    

Hame n chahiye aur sum chahiye to maine alag alag nikala tha aur map mein store kiya tha lekin tum yahi cheez single pass mein bhi to kar sakte ho

pair return karke kyunki sum mein bhi tumhe neeche ke sum chahiye aur cntNode mein bhi to pair return kara do

pehli baar mein pair return wala question dekha maza aya
    
class Solution {
private:
//     int getCntSubTree(TreeNode* root,unordered_map<TreeNode*,int> &mp){
//         if(root==NULL) return 0;
        
//         int left=getCntSubTree(root->left,mp);
//         int right=getCntSubTree(root->right,mp);
        
//         mp[root]=left+right+1;
        
//         return mp[root];
//     }
//     int getAverage(TreeNode* root,int &ans,unordered_map<TreeNode*,int> &mp){
//         if(root==NULL) return 0;
        
//         int leftSum=getAverage(root->left,ans,mp);
//         int rightSum=getAverage(root->right,ans,mp);
        
//         int sum=leftSum+rightSum+root->val;
//         int n=mp[root];
        
//         if(root->val==sum/n) ans++;
        
//         return sum;
//     }
    
    // Mujhe do chezein chahiye to main dono ko nikal sakta hun aur return bhi to kar sakta hun pair<int,int> karke
     pair<int,int> getAverage(TreeNode* root,int &ans){
        if(root==NULL) return {0,0};
        
         // pair is {sum of subtree and no of nodes in subtree}
        auto left=getAverage(root->left,ans); 
        auto right=getAverage(root->right,ans);
        
        int leftSum=left.first;
        int leftNodeCnt=left.second;
        
        int rightSum=right.first;
        int rightNodeCnt=right.second;
        
        int sum=leftSum+rightSum+root->val;
        int n=leftNodeCnt+rightNodeCnt+1;
         
        if(root->val==sum/n) ans++;
         
        return {sum,n};
        
    }
public:
    int averageOfSubtree(TreeNode* root) {
        
        // O(nlogn+nlogn) O(n+n+n)
        // TreeNode* temp=root;
        // // For getting how many people are there in my subtree
        // unordered_map<TreeNode*,int> mp;
        // getCntSubTree(temp,mp);
        // int ans=0;
        // getAverage(root,ans,mp);
        // return ans;
        
        // O(n) O(n)
        int ans=0;
        getAverage(root,ans);
        return ans;
    }
};