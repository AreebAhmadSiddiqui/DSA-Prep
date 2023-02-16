class Solution {
private:
    int help(int i,int j,string &text1,string &text2,vector<vector<int>> &dp){
        if(i==0 || j==0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(text1[i-1]==text2[j-1]){
            return dp[i][j]=1+help(i-1,j-1,text1,text2,dp);
        }
        return dp[i][j]=max(help(i-1,j,text1,text2,dp),help(i,j-1,text1,text2,dp));
    }
    int tabulation(string s1,string s2){
        vector<vector<int>> dp(s1.size()+1,vector<int> (s2.size()+1,0));
        
        // Base Case
        for(int j=0;j<s2.size();j++) dp[0][j]=0;
        for(int i=0;i<s1.size();i++) dp[i][0]=0;
        
        for(int i=1;i<=s1.size();i++){
            for(int j=1;j<=s2.size();j++){
                if(s1[i-1]==s2[j-1]){
                   dp[i][j]=1+dp[i-1][j-1];
                }
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        return dp[s1.size()][s2.size()];
    }
    int spaceOptimised(string s1,string s2){
        vector<int> prev(s2.size()+1,0),curr(s2.size()+1,0);
        
       // Base Case
        for(int j=0;j<s2.size();j++) dp[0][j]=0;
        for(int i=0;i<s1.size();i++) dp[i][0]=0;
        
        for(int i=1;i<=s1.size();i++){
            for(int j=1;j<=s2.size();j++){
                if(s1[i-1]==s2[j-1]){
                   curr[j]=1+prev[j-1];
                }
                else curr[j]=max(prev[j],curr[j-1]);
            }
            prev=curr;
        }
        
        return prev[s2.size()];
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        // vector<vector<int>> dp(text1.size()+1,vector<int> (text2.size()+1,-1));
        // return help(text1.size(),text2.size(),text1,text2,dp);
        
        // return tabulation(text1,text2);
         return spaceOptimised(text1,text2);
    }
};