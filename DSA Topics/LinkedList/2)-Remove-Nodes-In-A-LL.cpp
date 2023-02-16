Remove Nodes From Linked List

You are given the head of a linked list.

Remove every node which has a node with a strictly greater value anywhere to the right side of it.

Return the head of the modified linked list.
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        
        // Next Greater to the right
        stack<ListNode*> st;
        while(head!=NULL){
            while(!st.empty() && st.top()->val<head->val){
                delete st.top();
                st.pop();
            }
            st.push(head);
            head=head->next;
        }
        
        // Remaining elements would be in decreasing order
        head=NULL;
        while(!st.empty()){
            ListNode* newNode=st.top();
            st.pop();
            if(head==NULL){
                head=newNode;
            }
            else{
                newNode->next=head;
                head=newNode;
            }
        }
        
        return head;
    }
};