class Solution {
private:
//     int help(int i,int j,string &word1,string &word2,vector<vector<int>> &dp){
        
//         if(i==0 || j==0){
//             if(i==0 && j==0) return 0;
//             if(i==0){
//                 return j;
//             }
//             else{
//                 return i;
//             }
//         }
        
        
//         if(dp[i][j]!=-1) return dp[i][j];
        
//         int ans=INT_MAX;
//         if(word1[i-1]==word2[j-1]){ // they are equal no change needed
//             ans=help(i-1,j-1,word1,word2,dp);
//         }
//         else{
            
//             // 3 options
            
//             // a) Replace  i-1,j-1
//             // b) Insert   i,j-1
//             // c) Delete   i-1,j
            
//             ans=1+min(help(i-1,j-1,word1,word2,dp),min(help(i,j-1,word1,word2,dp),help(i-1,j,word1,word2,dp)));
//         }
        
//         return dp[i-1][j-1]=ans;
//     }
public:
    int minDistance(string word1, string word2) {
        
        int n=word1.size();
        int m=word2.size();
        
//         vector<vector<int>> dp(n+1,vector<int> (m+1,0));
//         // help(n,m,word1,word2,dp);
       
//         for(int j=0;j<=m;j++){
//             dp[0][j]=j;
//         }
//         for(int i=0;i<=n;i++){
//             dp[i][0]=i;
//         }
        
//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=m;j++){
//                 if(word1[i-1]==word2[j-1]){ // they are equal no change needed
//                     dp[i][j]=dp[i-1][j-1];
//                 }
//                 else{
//                     dp[i][j]=1+min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));
//                 }
//             }
//         }
//         return dp[n][m];
        
        vector<int> curr(m+1,0),prev(m+1,0);
       
        for(int j=0;j<=m;j++){
            prev[j]=j;
        }
        
        for(int i=1;i<=n;i++){
            curr[0]=i;
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){ // they are equal no change needed
                    curr[j]=prev[j-1];
                }
                else{
                    curr[j]=1+min(prev[j-1],min(curr[j-1],prev[j]));
                }
            }
            prev=curr;
        }
        return prev[m];
        
        
    }
};