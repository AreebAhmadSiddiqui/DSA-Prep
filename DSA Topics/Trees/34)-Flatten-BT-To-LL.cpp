class Solution
{
    
    // O(N) O(N)
    public:
    Node* prev=NULL;
    void flatten(Node *root)
    {
        if(root==NULL) return;
        
        flatten(root->right);  // ye dekho right right jao taki jab wapis ao to recursion hi help se last wala pehel ho jae aru ant mein first wala
        flatten(root->left);
        
        root->right=prev;
        root->left=NULL;
        prev=root;
    }
    
    
    // O(N) O(1)
    public:
    void flatten(Node *root)
    {
       Node* curr=root;
       
       // Go to the left subtree and connect its right most element to curr right and switch the node left and right
       while(curr!=NULL){
           Node* temp=curr->left;
           if(temp){
               while(temp->right){
                   temp=temp->right;
               }
               temp->right=curr->right;
               curr->right=curr->left;
               curr->left=NULL;
               curr=curr->right;
           }
           else{
               curr=curr->right;
           }
       }
    }
};