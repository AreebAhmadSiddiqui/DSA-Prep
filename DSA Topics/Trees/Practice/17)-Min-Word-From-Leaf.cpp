Smallest String Starting From Leaf

You are given the root of a binary tree where each node has a value in the range [0, 25] representing the letters 'a' to 'z'.

Return the lexicographically smallest string that starts at a leaf of this tree and ends at the root.

As a reminder, any shorter prefix of a string is lexicographically smaller.

For example, "ab" is lexicographically smaller than "aba".
A leaf of a node is a node that has no children.
    

class Solution {
private:
    bool isLeaf(TreeNode* root){
        return !root->left && !root->right;
    }
    
    // Sirf leaf nodes pe O(height of tree ho raha hai)
    // Otherwise O(n) hi hai
    
    // At max how many leaf nodes? 2^height
    
    // So total complexity O(n)+O(2^height*height)
    // O(n) for traversing all nodes
    // 2^height leaf nodes and for each leaf nodes reverse function so * height
    void help(TreeNode* root,string ds,string &ans){
        if(root==NULL) return ;
        
        char ch='a'+root->val;
        
        if(isLeaf(root)){
            ds+=ch;
            reverse(ds.begin(),ds.end());
            ans=min(ans,ds);
            return;
        }
        
        help(root->left,ds+ch,ans);
        help(root->right,ds+ch,ans);
        
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        
        // String Infinity ="~" . Learnt new thing !! , see ASCII table for this basically it's like INT_MAX for string
        string ans="~";
        string ds="";
        help(root,ds,ans);
        return ans;
    }
};