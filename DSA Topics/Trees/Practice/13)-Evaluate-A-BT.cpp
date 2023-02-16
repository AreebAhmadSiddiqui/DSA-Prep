// Evaluate Boolean Binary Tree

// You are given the root of a full binary tree with the following properties:

// Leaf nodes have either the value 0 or 1, where 0 represents False and 1 represents True.
// Non-leaf nodes have either the value 2 or 3, where 2 represents the boolean OR and 3 represents the boolean AND.
// The evaluation of a node is as follows:

// If the node is a leaf node, the evaluation is the value of the node, i.e. True or False.
// Otherwise, evaluate the node's two children and apply the boolean operation of its value with the children's evaluations.
// Return the boolean result of evaluating the root node.

// A full binary tree is a binary tree where each node has either 0 or 2 children.

// A leaf node is a node that has zero children.
    
Approach

a) Dekh bhai isne tujhe full bt diya hai to root jab null ho uski chinta karne ki zarurat ni 
b) Lekin na hota to pooch lena interviewer se kya return karna hai

class Solution {
private:
    bool isLeaf(TreeNode* root){
        return !root->left && !root->right;
    }
public:
    bool evaluateTree(TreeNode* root) {
        // if(root==NULL) return  // yahan doubt tha lekin full bt mein ye condition kabhi ni aegi
        
        if(isLeaf(root)){
            return root->val;
        }
         
        bool left=evaluateTree(root->left);
        bool right=evaluateTree(root->right);
        
        return root->val==2 ? left | right : left & right;
    }
};