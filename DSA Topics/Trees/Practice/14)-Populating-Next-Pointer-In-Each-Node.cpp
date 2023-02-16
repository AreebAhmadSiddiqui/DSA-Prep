Populating Next Right Pointers in Each Node

You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.
    
Pehla wala to intuitive hai

// Doosra wala samjo yahan

// a) tum level wise travel karo aur apne bacho ko connect karte jao
// b) Baki sab to sahi hai bas beech wale rah jaenge jaise 2 and 3 is example mein beech ke bande hai to 2 ka right aur 3 ka left bhi to connect hoga
// c) ek edge case aega jab sare leaf node wale case honge tab unke bache ni honge to unhe check karne ke liye isLeaf function bana dena
// d) Ye sab ham isliye kar pa rahe kyunki perfect bt hai ye agar na hota to shyad na kar pate

class Solution {
public:
    
//     // O(n) O(n)
//     Node* connect(Node* root) {
     
//         if(root==NULL) return root;
        
//         queue<Node*> q;
//         q.push(root);
        
//         Node *prev=NULL;
//         while(!q.empty()){
//             int size=q.size();
//             for(int i=0;i<size;i++){
//                 auto node=q.front();
//                 q.pop();
//                 node->next=prev;
//                 prev=node;
                
//                 // first right then left kyunki right se pointers banoge na isliye
//                 if(node->right) q.push(node->right);
//                 if(node->left) q.push(node->left);
//             }
//             prev=NULL;
//         }
//         return root;
//     }
    
    // Question asks us for O(1) space solution
    // O(n) O(1)
    bool isLeaf(Node* root){
        return !root->left && !root->right;
    }
    Node* connect(Node* root) {
     
        if(root==NULL) return root;
        Node* temp=root;
        
        while(root!=NULL){
            Node* curr=root;
            while(curr!=NULL){
                
                if(!isLeaf(curr) && curr->next!=NULL){ // iska matlab ye kahin beech ka hai to middle wale bhi connect karne hai na (except leaf nodes)
                    curr->right->next=curr->next->left;
                }
                if(curr->left!=NULL){ // agar aisa hai to curr->right bhi to hoga since har parent ke two children hai
                    curr->left->next=curr->right;
                }
                curr=curr->next;
            }
            root=root->left;
        }
        
        return temp;
    }
};