958. Check Completeness of a Binary Tree


Given the root of a binary tree, determine if it is a complete binary tree.

In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
    
// Algorithm
    
1) Find the first Null Node
2) For a tree to be a complete BT there should not be any other non null nodes after the null node in the same lvl or beyond

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
     
        queue<TreeNode*> q;
        q.push(root);
        
        bool nullNodeFound=false;
        while(!q.empty()){
            
            auto node=q.front();
            q.pop();
            
            if(node==NULL) nullNodeFound=true;
            else{ // a non null node
                
                // if the non null node is there after a null node is found not a complete bt
                if(nullNodeFound) return false;
                
                q.push(node->left);
                q.push(node->right);
            }
        }
        
        return true;
    }
};