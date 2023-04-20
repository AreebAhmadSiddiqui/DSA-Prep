662. Maximum Width of Binary Tree

Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.
    

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        
        int maxi=0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        
        while(!q.empty()){
            
            int size=q.size();
            int first=1e9;
            int last=0;
            int adjustmentFactor=q.front().second;
            for(int i=0;i<size;i++){
                auto node=q.front().first;
                auto idx=q.front().second-adjustmentFactor; // Taki idx zero se start ho
                q.pop();
                
                if(i==0) first=idx;
                if(i==size-1) last=idx;
                if(node->left) q.push({node->left,2*1ll*idx}); // skewed tree mein bahut bada ho sakta ye number
                if(node->right) q.push({node->right,2*1ll*idx+1}); // ye wala bhi
            }
            maxi=max(maxi,last-first+1);
        }
        return maxi;
    }
};