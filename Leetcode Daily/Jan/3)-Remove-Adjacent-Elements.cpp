// You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them, causing the left and the right side of the deleted substring to concatenate together.

// We repeatedly make k duplicate removals on s until we no longer can.

// Return the final string after all such duplicate removals have been made. It is guaranteed that the answer is

// Jab bhi adjacent wala kuch ae to stack based solution sochna


// EASY Wala

class Solution {
public:
    string removeDuplicates(string s) {
        
        stack<char> st;
        
        for(int i=0;i<s.size();i++){
            if(st.empty() || st.top()!=s[i]) st.push(s[i]);
            else{
                if(st.top()==s[i]){
                    st.pop();
                }
            }
        }
        
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st; // {character,cnt}
        
        // O(N+N)
        st.push({s[0],1});
        for(int i=1;i<s.size();i++){
            char ch=s[i];
            
            if(!st.empty() && ch==st.top().first){
                char topChar=st.top().first;
                int cntTopChar=st.top().second;
                
                if(cntTopChar+1==k){// i need to pop k-1 elements
                    while(!st.empty() && st.top().first==ch){
                        st.pop();
                    }
                }else{
                    st.push({ch,cntTopChar+1});
                }
            }else{
                st.push({ch,1});
            }
        }
        
        string ans="";
        while(!st.empty()){
            ans+=st.top().first;
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};