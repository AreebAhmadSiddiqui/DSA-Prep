2130. Maximum Twin Sum of a Linked List

In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.

For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the only nodes with twins for n = 4.
The twin sum is defined as the sum of a node and its twin.

Given the head of a linked list with even length, return the maximum twin sum of the linked list.
    
class Solution {
private:
    ListNode* reverse(ListNode* head){
        
        ListNode* curr=head;
        ListNode* prev=NULL;
        while(curr!=NULL){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
public:
    int pairSum(ListNode* head) {
        if(head==NULL) return 0;
        
        ListNode* slow=head,*fast=head;
        while(fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        // Reverse from slow->next;
        
        slow->next=reverse(slow->next);
        
        ListNode* temp=slow->next;
        
        int maxi=0;
        fast=head;
        while(fast!=slow->next){
            maxi=max(maxi,fast->val+temp->val);
            fast=fast->next;
            temp=temp->next;
        }
        
        slow->next=reverse(slow->next);
        
        return maxi;
    }
};