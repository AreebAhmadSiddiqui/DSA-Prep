
Merge k Sorted Lists

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.
    
    
// O(n*(Total No of nodes)) O(1)

// PQ mein bhi dal sakte sab aur fir ek ek karke pop karo aur nayi list bana do

// O(klog(total # of nodes)) O(total # no of Nodes)

class Solution {
private:
    ListNode* mergeThisList(ListNode* prevHead,ListNode* currHead){
        
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        
        while(prevHead && currHead){
            if(prevHead->val<currHead->val){
                temp->next=prevHead;
                temp=prevHead;
                prevHead=prevHead->next;
            }else{
                temp->next=currHead;
                temp=currHead;
                currHead=currHead->next;
            }
        }
        
        if(prevHead) temp->next=prevHead;
        if(currHead) temp->next=currHead;
        
        return dummy->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode* prevHead=NULL;
        
        int n=lists.size();
        for(int i=0;i<n;i++){
            ListNode* currHead=lists[i];
            
            ListNode* newHead=mergeThisList(prevHead,currHead);
            
            prevHead=newHead;
        }
        
        return prevHead;
    }
};