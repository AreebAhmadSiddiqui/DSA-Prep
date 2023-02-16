class Solution {
private:


    // Kai minute se cheezein check karni padegi 

    a) root ko alag se dalo 
    b) fir left mein jao
    c) then leafs
    d) then right kyunki dekho maine left boundary root se shuru kari aur right boundary root->right se
    lekin agar aise example hua to

    1
     \
      2    to left wala 1 2 print kare aur right wala 2 balki kaede se to ye right skewed hai to right wala hi manage kare ise
       \
        3

    isliye root ko check karna ki leaf hai ki agar ni hai to add kar lena aur leftBou ke root->left aur right ke liye root->right
    bool isLeaf(Node* root){
        return root->left==NULL && root->right==NULL;
    }
    void getLeftBoundary(Node* root,vector<int> &ans){
        
        while(root!=NULL){
            
            if(isLeaf(root)) return;
            ans.push_back(root->data);    
            if(root->left) root=root->left;
            else root=root->right;
        }
    }
    
    void getLeafNodes(Node *root,vector<int> &ans){
        if(root==NULL) return;
        
        if(isLeaf(root)){
            ans.push_back(root->data);
            return;
        }
        
        getLeafNodes(root->left,ans);
        getLeafNodes(root->right,ans);
    }
    
    void getRightBoundary(Node* root,stack<int> &st){
        
        while(root!=NULL){
            if(isLeaf(root)) return;
            st.push(root->data);    
            if(root->right) root=root->right;
            else root=root->left;
        }
    }
public:
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        
        if(root==NULL) return ans;
        stack<int> st;
        
        if(!isLeaf(root)){
            ans.push_back(root->data);
        }
        
        getLeftBoundary(root->left,ans);
        getLeafNodes(root,ans);
        getRightBoundary(root->right,st);
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};