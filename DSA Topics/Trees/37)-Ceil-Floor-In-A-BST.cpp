// User function Template for C++

// Function to return the ceil of given number in BST.
int findCeil(Node* root, int input) {

    int ceil=-1,floor=-1;
    while(root!=NULL){
        if(root->data==input) {
            ceil=floor=input;
            break;
        }
        else if(input<root->data){ 
            ceil=root->data; //possible ans for ceil
            
            // check left if less is present
            root=root->left;
        }
        else{ 
            floor=root->data; //possible ans for florr
            root=root->right;
        }
    }
    
    return ceil;
}