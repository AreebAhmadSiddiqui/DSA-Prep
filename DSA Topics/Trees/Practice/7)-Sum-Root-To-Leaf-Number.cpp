Sum Root to Leaf Numbers

Normally dfs kar do prev*10+currVal sum mein lete hue aur jab bhi leaf node pe pahuncho to ans mein add kar do
You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

A leaf node is a node with no children.

class Solution {
// private:
    bool isLeaf(TreeNode* root){
        return root->left==NULL && root->right==NULL;
    }
//     int dfs(TreeNode* root,int sum){
//         if(root==NULL) return 0;
        
//         if(isLeaf(root)) return sum*10+root->val;
        
//         int left=dfs(root->left,sum*10+root->val);
//         int right=dfs(root->right,sum*10+root->val);
        
//         return left+right;
        
//     }
public:
    int sumNumbers(TreeNode* root) {
     
        // int sum=0;
        // return dfs(root,sum);
        
        int ans=0;
        int sum=0;
        stack<pair<TreeNode*,int>> st;
        while(root || !st.empty()){
            if(root){
                sum=sum*10+root->val;
                if(isLeaf(root)) ans+=sum;
                if(root->right) st.push({root->right,sum});
                root=root->left;
            }else{
                root=st.top().first;
                sum=st.top().second;
                st.pop();
            }
        }
        return ans;
    }
};