/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
    TC -> O(N)
    Sc -> O(h)
//     void getPreOrder(TreeNode* root,vector<int> &preOrderTraversal){
//         if(root==NULL) return;
        
        
//         preOrderTraversal.push_back(root->val);
//         getPreOrder(root->left,preOrderTraversal);
//         getPreOrder(root->right,preOrderTraversal);
//     }
    public:
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preOrderTraversal;
        
        stack<TreeNode*> st;
        while(root!=NULL || !st.empty()){
            if(root==NULL){
                root=st.top();
                st.pop();
            }
            
            preOrderTraversal.push_back(root->val);
            if(root->right!=NULL){
                st.push(root->right);
            }
            root=root->left;
        }
        
        return preOrderTraversal;
    }
};