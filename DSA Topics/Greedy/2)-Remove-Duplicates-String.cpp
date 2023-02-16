Steps

a) Hamlog monotonic stack implement karenge aur dekhenge ki character increasing order mein hai ki ni agar hai to dal do warna pop karo agar wo chracter age kahi present hai to kyunki age present ni hoga to delete karoge to wo ans mein ni aega
b) aur ek cheez aur hai repeat bhi ho sakta tumhara answer to visited rakh lo taaki agar koi visited wala ae to seedhe continue kar do
c) Agar na samjh ae to watch tech dose's video
class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        vector<int> visited(26,0);
        vector<int> freq(26,0);
        stack<char> st;
        
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }
        
        for(int i=0;i<s.size();i++){
            
            // If this is already in my answer then don't add it again
            if(visited[s[i]-'a']==1) {
                freq[s[i]-'a']--;
                continue;
            }
            
            // while the stack is not empty and the top character is present ahead and is greater than my current character so for increasing order I need to remove it
            while(!st.empty() && freq[st.top()-'a']>0 && st.top()>=s[i]){
                    visited[st.top()-'a']=0;
                    st.pop();
            }
                
            st.push(s[i]);
            freq[s[i]-'a']--;
            visited[s[i]-'a']=1;    
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