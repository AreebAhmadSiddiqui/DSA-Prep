Next Greater Node In Linked List

You are given the head of a linked list with n nodes.

For each node in the list, find the value of the next greater node. That is, for each node, find the value of the first node that is next to it and has a strictly larger value than it.

Return an integer array answer where answer[i] is the value of the next greater node of the ith node (1-indexed). If the ith node does not have a next greater node, set answer[i] = 0.
    
class Solution {
public:
    
    // Two Pass
//     vector<int> nextLargerNodes(ListNode* head) {
        
//         int n=0;
//         // For getting n
//         ListNode* temp=head;
//         while(temp){
//             n++;
//             temp=temp->next;
//         }
        
  
//         vector<int> ans(n,0);
//         int idx=0;
//         stack<pair<ListNode*,int>> st; // {val and indx}
//         while(head!=NULL){
            
//             while(!st.empty() && st.top().first->val<head->val){
//                 ans[st.top().second]=head->val;
//                 st.pop();
//             }
//             st.push({head,idx});
//             idx++;
//             head=head->next;
//         }
        
//         return ans;
//     }
    
    // One Pass
    
    // Vector dummy array type bana dena aur kya
    vector<int> nextLargerNodes(ListNode* head) {
  
        vector<int> ans;
        int idx=0;
        stack<pair<ListNode*,int>> st; // {val and indx}
        while(head!=NULL){
            
            ans.push_back(0); // isses index bante jaenge aur tum peeche wala tabhi acces karoge jab koi band tumhare age bada ho isliye kabhi index out of bound bhi ni aega
            while(!st.empty() && st.top().first->val<head->val){
                ans[st.top().second]=head->val;
                st.pop();
            }
            st.push({head,idx});
            idx++;
            head=head->next;
        }
        
        return ans;
    }
};