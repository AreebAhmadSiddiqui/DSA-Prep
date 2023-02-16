
class Solution {
private:
    TreeNode* first;
    TreeNode* second;
    TreeNode* third;
    TreeNode* prev;
public:
    
    // Brute 
    
    // Do an inorder and keep track of the non valid elements there can be two cases adjacent elements swapped or adjacent not swapped keep track of these non valid elements and at last swap them
    
//     1 2 3 4 5 6 correct order
        
//         a) 1 2 4 3 5 6  // adjacent swapped
//         b) 1 2 6 4 5 3  // non adjacent swapped this is why we store three values
    
    // But we need to store inorder so O(n) space would be used
    // But do you really need to store inorder I dont think so just use prev node and solve
    void checkForValidity(TreeNode* curr){
        
        if(prev==NULL){
            prev=curr;
            return;
        }
        
        if(prev->val>=curr->val){ // invalid
            if(first==NULL){ // first time
                first=prev;
                second=curr;
            }
            else{
                third=curr;
            }
        }
        
    }
    void inorder(TreeNode* root){
        
        if(root==NULL) return;
        
        inorder(root->left);
        
        // cout<<prev->val<<" "<<root->val<<"\n";
        checkForValidity(root);
        prev=root;
        
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        
        inorder(root);
        
        if(third==NULL){ // adjacent swapped
            swap(first->val,second->val);
        }
        else{ 
            swap(first->val,third->val);
        }
    }
};



class Solution {
private:
    TreeNode* prev;
    TreeNode* first;
    TreeNode* second;
    TreeNode* third;
private:
    void checkValid(TreeNode* root){            
        if(prev!=NULL && prev->val>root->val){
            if(first==NULL){
                  first=prev;
                  second=root;
            }
            else{
            third=root;
            }
         }
         prev=root;
    }
public:
    void recoverTree(TreeNode* root) {
          while(root!=NULL){
              if(root->left!=NULL){
                  auto temp=root->left;
                  while(temp->right!=NULL && temp->right!=root){
                      temp=temp->right;
                  }
                  if(!temp->right){
                      temp->right=root;
                      root=root->left;
                  }
                  else
                  {
                      temp->right=NULL;
                      checkValid(root);
                      root=root->right;
                  }
              }
              else{
                   checkValid(root);
                   root=root->right;
              }
          }
        if(first && third) swap(first->val,third->val); // two invalid
        else swap(first->val,second->val); // adjacent swap
    }
};