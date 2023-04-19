// 1372. Longest ZigZag Path in a Binary Tree

// You are given the root of a binary tree.

// A ZigZag path for a binary tree is defined as follow:

// Choose any node in the binary tree and a direction (right or left).
// If the current direction is right, move to the right child of the current node; otherwise, move to the left child.
// Change the direction from right to left or from left to right.
// Repeat the second and third steps until you can't move in the tree.
// Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).

// Return the longest ZigZag path contained in that tree.
    

class Solution {
private:
    int help(TreeNode* root,int &ans,int prevDir){
        if(root==NULL) return 0;
        
        int left=help(root->left,ans,0);
        int right=help(root->right,ans,1);
        
        // max to tumhe har node ke liye lena because wo path kahin se bhi ja sakta hai
        // lekin jab tum return karoge to dir dekh ke karna agar dir 0 hai matlab pichle left wala tha isliye return right+1 else left+1
        // Main pahele ans main dir ka use kar raha tha 
        // To wo baad mein samjh aya ki galat kyunki ham jis node pe khade hai wahan se bhi tu shuru kar sakte path
        ans=max(ans,max(left,right));
        
        return prevDir==0 ? right+1 : left+1;
    }
public:
    int longestZigZag(TreeNode* root) {
        int ans=0;
        // prevDir 0 -> left
        //     1 -> right
        
        // -1 matlab kuch dono mein se koi ni
        // iski zarurat padi ni because ham hamesha ans mein left aur right ki value dekh rahe usse iska koi lena dena ni except for root node lekin whaan bhi pehle answer mein store ho raha uske baad ye return ho raha
        help(root,ans,-1);
        
        return ans;
    }
};