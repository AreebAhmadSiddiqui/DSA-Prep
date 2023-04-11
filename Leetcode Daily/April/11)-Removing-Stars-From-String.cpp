Removing Stars From a String

You are given a string s, which contains stars *.

In one operation, you can:

Choose a star in s.
Remove the closest non-star character to its left, as well as remove the star itself.
Return the string after all stars have been removed.


class Solution {
public:
    
    // Approach 1
//     string removeStars(string s) {
//         stack<char> st;
        
//         for(auto &ch:s){
//             if(ch=='*'){
//                 st.pop();
//             }else{
//                 st.push(ch);
//             }
//         }
        
//         string ans="";
//         while(!st.empty()){
//             ans+=st.top();
//             st.pop();
//         }
        
//         reverse(ans.begin(),ans.end());
//         return ans;
//     }
    
    // Approach 2
    string removeStars(string s) {
        string ans="";
        
        for(auto &ch:s){
            if(ch=='*') ans.pop_back();
            else ans.push_back(ch);
        }
        return ans;
    }
        
};