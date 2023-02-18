You can do LCS and then (a.size()+b.size()-2*lcs)

Delete Operation for Two Strings
 
Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.

 
class Solution {
private:
//     int help(int i,int j,string &word1,string &word2,vector<vector<int>> &dp){
//         if(i==0 && j==0) return 0;
//         if(i==0) return j;
//         if(j==0) return i;
        
//         if(dp[i][j]!=-1) return dp[i][j];
        
//         int same=1e9,notSame=1e9;
//         if(word1[i-1]==word2[j-1]) same=0+help(i-1,j-1,word1,word2,dp);
//         else{
//             // Three Options
//             // Delete from word1
//             int op1=1+help(i-1,j,word1,word2,dp);
//             // Delete from word2
//             int op2=1+help(i,j-1,word1,word2,dp);
//             // Delete from both
//             int op3=1+1+help(i-1,j-1,word1,word2,dp);
            
//             notSame=min(op1,min(op2,op3));
//         }
        
//         return dp[i][j]=min(same,notSame);
//     }
//     int tabulation(string &word1,string &word2){
//         int n=word1.size(),m=word2.size();
        
//         vector<vector<int>> dp(n+1,vector<int> (m+1,1e9));
        
//         // Base Case
//         dp[0][0]=0;
//         for(int j=1;j<=m;j++) dp[0][j]=j;
//         for(int i=1;i<=n;i++) dp[i][0]=i;
        
//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=m;j++){
//                 int same=1e9,notSame=1e9;
//                 if(word1[i-1]==word2[j-1]) same=0+dp[i-1][j-1];
//                 else{
//                     // Three Options
//                     // Delete from word1
//                     int op1=1+dp[i-1][j];
//                     // Delete from word2
//                     int op2=1+dp[i][j-1];
//                     // Delete from both
//                     int op3=1+1+dp[i-1][j-1];

//                     notSame=min(op1,min(op2,op3));
//                 }

//                 dp[i][j]=min(same,notSame);
//             }
//         }
        
//         return dp[n][m];
//     }
    int spaceOptimisation(string &word1,string &word2){
        int n=word1.size(),m=word2.size();
        
        vector<int> prev(m+1,1e9),curr(m+1,1e9);
        
        // Base Case
        prev[0]=0;
        for(int j=1;j<=m;j++) prev[j]=j;
        curr[0]=0;
        
        for(int i=1;i<=n;i++){
            curr[0]=i;
            for(int j=1;j<=m;j++){
                int same=1e9,notSame=1e9;
                if(word1[i-1]==word2[j-1]) same=0+prev[j-1];
                else{
                    // Three Options
                    // Delete from word1
                    int op1=1+prev[j];
                    // Delete from word2
                    int op2=1+curr[j-1];
                    // Delete from both
                    int op3=1+1+prev[j-1];

                    notSame=min(op1,min(op2,op3));
                }

                curr[j]=min(same,notSame);
            }
            prev=curr;
        }
        
        return prev[m];
    }
public:
    int minDistance(string word1, string word2) {
//         int n=word1.size(),m=word2.size();
        
//         vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        
//         return help(n,m,word1,word2,dp);
        
        // return tabulation(word1,word2);
        return spaceOptimisation(word1,word2);
    }
};