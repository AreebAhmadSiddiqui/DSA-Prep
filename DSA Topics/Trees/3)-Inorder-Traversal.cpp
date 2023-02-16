class Solution {
    // private:
//     TC-> O(n)
//     Sc-> O(h) which in worst case O(n) in skewed tree
//     void help(TreeNode* root,vector<int> &ans){
//         if(root==NULL) return;
        
//         help(root->left,ans);
//         ans.push_back(root->val);
//         help(root->right,ans);
//     }
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         help(root,ans);
//         return ans;
//     }
    
    //Iterative
    TC-> O(n)
    SC-> O(n) worst case
    public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        stack<TreeNode*> st;
        while(root!=NULL || !st.empty()){
            
            // Left subtree exhauted print the root which is at the stack top
            if(root==NULL){
                root=st.top();
                st.pop();
                ans.push_back(root->val);
                root=root->right;
            }
            else{
                st.push(root);
                root=root->left;
            }
        }
        return ans;
    }
};