class Solution {
private:
//     int help(int i,int j,int n,string &s,string &t,vector<vector<int>> &dp){
//         if(i==n || j==n) return 0;
        
//         if(dp[i][j]!=-1) return dp[i][j];
        
//         int ans=0;
//         if(s[i]==t[j]){
//             ans=1+help(i+1,j+1,n,s,t,dp);
//         }else{
//             ans=max(help(i+1,j,n,s,t,dp),help(i,j+1,n,s,t,dp));
//         }
//         return dp[i][j]=ans;
//     }
//     int tabulation(string &s){
        
//         string temp=s;
//         reverse(temp.begin(),temp.end());
//         int n=s.size();
//         vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        
//         // Base case (done Already)
        
//         for(int i=n-1;i>=0;i--){
//             for(int j=n-1;j>=0;j--){
                
//                 int ans=0;
//                 if(s[i]==temp[j]){
//                     ans=1+dp[i+1][j+1];
//                 }else{
//                     ans=max(dp[i+1][j],dp[i][j+1]);
//                 }
//                 dp[i][j]=ans;
//             }
//         }
//         return dp[0][0];
//     }
    int spaceOptimisation(string &s){
        
        string temp=s;
        reverse(temp.begin(),temp.end());
        int n=s.size();
        vector<int> prev(n+1,0),curr(n+1,0);
        
        // Base case (done Already)
        
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                
                int ans=0;
                if(s[i]==temp[j]){
                    ans=1+prev[j+1];
                }else{
                    ans=max(prev[j],curr[j+1]);
                }
                curr[j]=ans;
            }
            prev=curr;
        }
        return prev[0];
    }
public:
    int longestPalindromeSubseq(string s) {
     
//         string temp=s;
//         reverse(temp.begin(),temp.end());
        
//         int n=s.size();
//         vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
//         return help(0,0,n,s,temp,dp);
        // return tabulation(s);
        return spaceOptimisation(s);
    }
};