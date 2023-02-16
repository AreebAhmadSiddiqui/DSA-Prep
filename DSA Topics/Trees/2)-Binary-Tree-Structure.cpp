struct Node{
    int data;
    node* left;
    node* right;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};

main(){
   Node* root=new Node(1);

   root->left=new Node(2);
   root->right=new Node(3);   
}