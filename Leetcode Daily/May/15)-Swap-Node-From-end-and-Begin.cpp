1721. Swapping Nodes in a Linked List

You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).
    
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if(head==NULL) return head;
        
        // Get the kth node from front
        ListNode* node1=head;
        int x=k;
        while(--x){
            node1=node1->next;
        }
        
        // Get the kth node from front
        ListNode* slow=head,*fast=head;
        while(--k){
            fast=fast->next;
        }
        
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        
        ListNode* node2=slow;
        
        swap(node1->val,node2->val);
        
        return head;
        
    }
};