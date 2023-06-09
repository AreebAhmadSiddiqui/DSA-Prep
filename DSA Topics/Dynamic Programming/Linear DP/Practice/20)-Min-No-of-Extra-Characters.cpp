2707. Extra Characters in a String

You are given a 0-indexed string s and a dictionary of words dictionary. You have to break s into one or more non-overlapping substrings such that each substring is present in dictionary. There may be some extra characters in s which are not present in any of the substrings.

Return the minimum number of extra characters left over if you break up s optimally.
    
    

class Solution {
private:
//     int help(int i,int n,string &s,unordered_set<string> &st,vector<int> &dp){
//         if(i==n) return 0;
        
//         string temp="";
//         int ans=1e9;
//         int pick=1e9,notPick=1e9;
        
//         if(dp[i]!=-1) return dp[i];
        
//         for(int j=i;j<n;j++){
//             temp+=s[j];
//             if(st.find(temp)!=st.end()){
//                 pick=0+help(j+1,n,s,st,dp);
//             }else{
//                 notPick=j-i+1+help(j+1,n,s,st,dp);
//             }
//             ans=min(ans,min(pick,notPick));
//         }
//         return dp[i]=ans;
//     }
    
    int tabulation(string &s,vector<string> &dictionary){
        unordered_set<string> st;
        
        for(auto &it:dictionary){
            st.insert(it);
        }
        
        int n=s.size();
        vector<int> dp(n+1,0);
        
        // Base Case Done
        
        for(int i=n-1;i>=0;i--){
            
            string temp="";
            int ans=1e9;
            int pick=1e9,notPick=1e9;
            
            for(int j=i;j<n;j++){
                temp+=s[j];
                if(st.find(temp)!=st.end()){
                    pick=0+dp[j+1];
                }else{
                    notPick=j-i+1+dp[j+1];
                }
                ans=min(ans,min(pick,notPick));
            }dp[i]=ans;
        }
        return dp[0];
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
//         unordered_set<string> st;
        
//         for(auto &it:dictionary){
//             st.insert(it);
//         }
        
        
//         int n=s.size();
//         vector<int> dp(n+1,-1);
//         return help(0,n,s,st,dp);
        return tabulation(s,dictionary);
    }
};