class Solution {
private:
//     int help(int i,int j,string &s,string &t,vector<vector<int>> &dp){
        
//         if(j==0){ // we got our string t
//             return 1;
//         }
        
//         if(i==0){// we did not get it
//             return 0;
//         }
        
//         if(dp[i][j]!=-1) return dp[i][j];
//         if(s[i-1]==t[j-1]){
//             return dp[i][j]=help(i-1,j-1,s,t,dp)+help(i-1,j,s,t,dp); // either i move both my j and i or save j so that if there is another subsequence ending with j we can take that into account as well
//         }
//         return dp[i][j]=help(i-1,j,s,t,dp);
//     }
    int tabulation(string &s,string &t){
        int mod=1e9+7;
        vector<vector<long long>> dp(s.size()+1,vector<long long> (t.size()+1,0));
        
        // Base Case
        for(int i=0;i<=s.size();i++) dp[i][0]=1;
        
        
        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=t.size();j++){
                if(s[i-1]==t[j-1]){
                   dp[i][j]= (dp[i-1][j-1]+dp[i-1][j])%mod; 
                }
                else dp[i][j]=dp[i-1][j];
            }
        }
        
        return dp[s.size()][t.size()];
    }
     int spaceOptimised(string &s,string &t){
        int mod=1e9+7;
        vector<int> prev(t.size()+1,0);
        
        // Base Case
        // for(int i=0;i<=s.size();i++) dp[i][0]=1;
        for(int j=1;j<=t.size();j++) prev[j]=0; 
         
        prev[0]=1;
        for(int i=1;i<=s.size();i++){
            for(int j=t.size();j>=1;j--){
                if(s[i-1]==t[j-1]){
                   prev[j]= (prev[j-1]+prev[j])%mod; 
                }
                else prev[j]=prev[j];
            }
        }
        
        return prev[t.size()];
    }
public:
    int numDistinct(string s, string t) {
        // vector<vector<int>> dp(s.size()+1,vector<int> (t.size()+1,-1));
        // return help(s.size(),t.size(),s,t,dp);
        
        // return tabulation(s,t);
         return spaceOptimised(s,t);
    }
};