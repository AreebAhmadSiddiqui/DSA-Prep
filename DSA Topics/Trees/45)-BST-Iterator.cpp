

O(1) O(N)
class BSTIterator {
    vector<int> inOrder;
    int ind;
public:
    BSTIterator(TreeNode* root) {
        
        stack<TreeNode*> st;
        while(root!=NULL || !st.empty()){
            if(root==NULL){
                root=st.top();
                st.pop();
                inOrder.push_back(root->val);
                root=root->right;
            }
            else{
                st.push(root);
                root=root->left;
            }
        }
        
        ind=0;
    }
    
    int next() {
        return inOrder[ind++];
    }
    
    bool hasNext() {
        return ind<inOrder.size();
    }
};


// ~O(1) O(H)  see all in all you will go to n nodes and if there are n calls n/n ~ 1 its why O(1) average
class BSTIterator {
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        
        while(root!=NULL){
            st.push(root);
            root=root->left;
        }
    }
    
    int next() {
        TreeNode* node=st.top();
        st.pop();
        
        int ans=node->val;
        if(node->right){
            node=node->right;
            while(node){
                st.push(node);
                node=node->left;
            }
        }
        
        return ans;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

FOR BST II create a doubly linked list and for each node store its prev and next pointers