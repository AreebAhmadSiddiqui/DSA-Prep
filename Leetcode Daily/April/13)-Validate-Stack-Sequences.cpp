Validate Stack Sequences

Given two integer arrays pushed and popped each with distinct values, return true if this could have been the result of a sequence of push and pop operations on an initially empty stack, or false otherwise.
    
Approach

a) Tu pehle dal de elemenst aur jaise hi koi popped ki value st.top() jaise ho jae to pop karna shuru kardo kyunki agar ni kiya to age to stack mein top pe ni rahega na


class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int n=pushed.size();
        int j=0;
        for(int i=0;i<n;i++){
            st.push(pushed[i]);
            
            while(!st.empty() && j<n && st.top()==popped[j]){
                j++;
                st.pop();
            }
        }
        
        return st.empty();
    }
};