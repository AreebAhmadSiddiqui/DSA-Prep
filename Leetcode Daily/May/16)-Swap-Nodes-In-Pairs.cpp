// 24. Swap Nodes in Pairs

// Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        
        ListNode* dummyNode=new ListNode(-1);
        ListNode* prev=dummyNode;
        dummyNode->next=head;
        ListNode* curr=head,*nextNode=head;
        while(curr!=NULL && curr->next!=NULL){
            nextNode=curr->next;
            curr->next=nextNode->next;
            nextNode->next=curr;
            prev->next=nextNode;
            
            prev=curr;
            curr=curr->next;
        }
        return dummyNode->next;
    }
};