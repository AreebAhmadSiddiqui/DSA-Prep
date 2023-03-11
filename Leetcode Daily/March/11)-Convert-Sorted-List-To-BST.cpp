Convert Sorted List to Binary Search Tree

Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height-balanced binary search tree.
// O(NlogN) O(logN)
class Solution {
private:
    ListNode* getMidNode(ListNode* start,ListNode* end){
        ListNode* slow=start,*fast=start;
        while(fast!=end && fast->next!=end){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    TreeNode* convertBST(ListNode* start,ListNode* end){
        if(start==end) return NULL;
        
        ListNode* midNode=getMidNode(start,end);
        TreeNode* root=new TreeNode(midNode->val);
        
        
        // Create the Left Subtree
        root->left=convertBST(start,midNode);
        
        // Create the right Subtree
        root->right=convertBST(midNode->next,end);
        
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        
        return convertBST(head,NULL);
    }
};

// Ya fir tum ise sorted array mein convert kar do aur mid ko O(1) men nikal lo 

// Wo solution is O(n) O(n)