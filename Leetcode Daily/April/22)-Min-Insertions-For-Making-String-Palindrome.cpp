1312. Minimum Insertion Steps to Make a String Palindrome

Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.
    
    
class Solution {
private:
//     int lcs(int i,int j,int n,string &s,string &t,vector<vector<int>> &dp){
//         if(i==n | j==n) return 0;
        
//         if(dp[i][j]!=-1) return dp[i][j];
        
//         int ans=0;
//         if(s[i]==t[j]){
//             ans=1+lcs(i+1,j+1,n,s,t,dp);
//         }else{
//             ans=max(lcs(i,j+1,n,s,t,dp),lcs(i+1,j,n,s,t,dp));
//         }
        
//         return dp[i][j]=ans;
//     }
//     int tabulation(string &s){
        
//         int n=s.size();
//         string t=s;
//         reverse(t.begin(),t.end());
//         vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        
//         // Base Case
//         // Done Already
        
//         for(int i=n-1;i>=0;i--){
//             for(int j=n-1;j>=0;j--){
//                 int ans=0;
                
//                 if(s[i]==t[j]){
//                     ans=1+dp[i+1][j+1];
//                 }else{
//                     ans=max(dp[i][j+1],dp[i+1][j]);
//                 }
                
//                 dp[i][j]=ans;
//             }
//         }
//         return n-dp[0][0];
//     }
    int sO(string &s){
        
        int n=s.size();
        string t=s;
        reverse(t.begin(),t.end());
        vector<int> prev(n+1,0),curr(n+1,0);
        
        // Base Case
        // Done Already
        
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int ans=0;
                
                if(s[i]==t[j]){
                    ans=1+prev[j+1];
                }else{
                    ans=max(curr[j+1],prev[j]);
                }
                
                curr[j]=ans;
            }
            prev=curr;
        }
        return n-prev[0];
    }
public:
    int minInsertions(string s) {
        
        // int n=s.size();
        // string s1=s;
        // reverse(s1.begin(),s1.end());
        // vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        // return n-lcs(0,0,n,s,s1,dp);
        // return tabulation(s);
        return sO(s);
    }
};