class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        Node* ans;
        while(root!=NULL){
            // Successor
            if(root->data<=x->data){ 
                root=root->right;
            }
            else {//if(root->data>x->data){ // just bada chahite to dekhlo kahin peeche na ho
                ans=root;
                root=root->left;
            } 

            // Predecessor
            if(root->data<=x->data){ 
                root=root->right;
            }
            else { // just bada chahite to dekhlo kahin peeche na ho
                ans=root;
                root=root->left;
            } 
        }
        return ans;
    }
};