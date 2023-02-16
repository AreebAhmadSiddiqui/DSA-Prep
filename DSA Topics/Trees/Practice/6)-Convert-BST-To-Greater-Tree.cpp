
Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.

As a reminder, a binary search tree is a tree that satisfies these constraints:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.


// First solution 

a) Inorder ko maintain karo aur jab inorder bana rahe hoge to sum bhi karlena values ka
b) Isse kya fayda because inorder is sorted in ascending order i th index pe jo node hogi uski value wahan se leke end tak se sum ke barabar hogi 
c) to sum variable le liye aur usse solve kar raha


class Solution {
private:
    int inOrder(TreeNode* root,vector<TreeNode*> &in){
        if(root==NULL) return 0;
        
        int left=inOrder(root->left,in);
        in.push_back(root);
        int right=inOrder(root->right,in);
        
        return root->val+left+right;
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        vector<TreeNode*> inorder;
        int sum=inOrder(root,inorder);
       
        for(int i=0;i<inorder.size();i++){
            auto node=inorder[i];
            int nodeVal=node->val;
            node->val=sum;
            sum-=nodeVal;
        }
        
        return root;
    }
};

Right Sum Maintain Karo lo aur answer le ao

// Yahan tum left root right jane se acha hai right root left chale jao aur ek rightSum ka variable initialise kardo jab bhi kisi root pe ana right tree process karne ke baad to uski value bhada dena aur rightSum ki value ko node.val kar dena

class Solution {
private:
    void help(TreeNode* root,int &rightSum){
        if(root==NULL) return;
        
        help(root->right,rightSum);
        root->val=root->val+rightSum;
        rightSum=root->val;
        help(root->left,rightSum);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        
        int rightSum=0;
        help(root,rightSum);
        return root;
    }
};

// Same hai iterative hai bas

// Haan Morris Traversal bhi laga sakte ho tum yahan reverse inorder wala
class Solution {
public:
    // Iterative
    TreeNode* bstToGst(TreeNode* root) {
        
        TreeNode* temp=root;
        int rightSum=0;
        stack<TreeNode*> st;
        while(root || !st.empty()){
            if(root==NULL){
                root=st.top();
                st.pop();
                
                root->val+=rightSum;
                rightSum=root->val;
                root=root->left;
            }else{
                st.push(root);
                root=root->right;
            }
        }
        return temp;
    }
};