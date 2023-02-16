/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// class BSTIterator {
//     stack<TreeNode*> nextStack,beforeStack;
// public:
//     BSTIterator(TreeNode* root) {
        
//         TreeNode* rootTemp=root;
//         while(root!=NULL){
//             nextStack.push(root);
//             root=root->left;
//         }
        
//         while(rootTemp!=NULL){
//             beforeStack.push(rootTemp);
//             rootTemp=rootTemp->right;
//         }
//     }
    
//     TreeNode* next() {
//         TreeNode* node=nextStack.top();
//         nextStack.pop();
        
//         TreeNode* ans=node;
//         if(node->right){
//             node=node->right;
//             while(node){
//                 nextStack.push(node);
//                 node=node->left;
//             }
//         }
        
//         return ans;
//     }
    
//     TreeNode* before() {
//         TreeNode* node=beforeStack.top();
//         beforeStack.pop();
        
//         TreeNode* ans=node;
//         if(node->left){
//             node=node->left;
//             while(node){
//                 beforeStack.push(node);
//                 node=node->right;
//             }
//         }
//         return ans;
//     }
    
//     bool hasNext() {
//         return !nextStack.empty();
//     }
    
//     bool hasBefore() {
//         return !beforeStack.empty();
//     }
// };


// // O(N+N) O(H+H)
// class Solution {
// public:
//     bool findTarget(TreeNode* root, int k) {
        
//         BSTIterator obj(root);
        
//         TreeNode* a=obj.next();
//         TreeNode* b=obj.before();
        
        
        
//         while(a!=b){ // a==b means same element
            
//             if(a->val+b->val==k) return true;
//             if(a->val+b->val<k){
//                 // increase smaller element
//                 a=obj.next();
//             }
//             else{
//                 //decrease bigger element
//                 b=obj.before();
//             }
//         }
        
//         return false;
//     }
// };



class BSTIterator {
    stack<TreeNode*> st;
    bool isReverse;
public:
     BSTIterator(TreeNode* root,bool v) {
        isReverse=v;
        addAll(root);
    }
    TreeNode* next() {
        TreeNode* ans=st.top();
        st.pop();
        
        if(isReverse) addAll(ans->left);
        else addAll(ans->right);
        
        return ans;
    }
    void addAll(TreeNode* temp){
       
        while(temp!=NULL){
            st.push(temp);
            if(isReverse) temp=temp->right;
            else temp=temp->left;
        }
    }
};

// Clean Code with only single stack though space and time are the same but it is good too.
// O(N+N) O(H+H)
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        
        BSTIterator l(root,false);  // for left root right
        BSTIterator r(root,true);  // for right root left
        

        // Tum next mein value bhi return kar skate ho kyunki wo sorted hogi aur duplicated ni honge to jaise hi a==b matlab same point pe ho to return false kar dena
        TreeNode* a=l.next();
        TreeNode* b=r.next();
        
        while(a!=b){ // a==b means same element
            
            if(a->val+b->val==k) return true;
            if(a->val+b->val<k){
                // increase smaller element
                a=l.next();
            }
            else{
                //decrease bigger element
                b=r.next();
            }
        }
        
        return false;
    }
};