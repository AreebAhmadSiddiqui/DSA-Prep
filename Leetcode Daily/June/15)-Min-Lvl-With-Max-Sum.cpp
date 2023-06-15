1161. Maximum Level Sum of a Binary Tree

Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

Return the smallest level x such that the sum of all the values of nodes at level x is maximal.

Approach

a) Simple BFS

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        
        int maxi=root->val;
        int ans=1;
        int lvl=1;
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(!q.empty()){
            int size=q.size();
            int sum=0;
            for(int i=0;i<size;i++){
                auto node=q.front();
                q.pop();
                sum+=node->val;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            if(sum>maxi){
                maxi=sum;
                ans=lvl;
            }
            lvl++;
        }
        return ans;
    }
};