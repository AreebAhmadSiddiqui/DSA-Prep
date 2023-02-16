class Solution {
    // Recursive

private:
    bool checkBST(TreeNode* root,long long left,long long right){
        if(root==NULL) return true;
        
        //for this node to be valid bst it should be (left,right)
        
        if(root->val<=left || root->val>=right){
            return false;
        }
        
        return checkBST(root->left,left,root->val) && checkBST(root->right,root->val,right);
    }
public:

    //Iterative
    bool isValidBST(TreeNode* root) {
        // return checkBST(root,LONG_MIN,LONG_MAX);
        
        stack<TreeNode*> st;
        long long prev=LONG_MIN;
        while(root!=NULL || !st.empty()){
            
            // Left subtree exhauted print the root which is at the stack top
            if(root==NULL){
                root=st.top();
                st.pop();
                if(prev>=root->val) return false;
                
                prev=root->val;
                root=root->right;
            }
            else{
                st.push(root);
                root=root->left;
            }
        }
        return true;
    }
};