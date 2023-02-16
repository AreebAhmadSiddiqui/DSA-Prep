#include <bits/stdc++.h> 
int help(int i,int j,vector<vector<int>>& triangle,int n,vector<vector<int>>& dp){
    if(i==n-1) return triangle[i][j];
      
    if(dp[i][j]!=-1) return dp[i][j];
    
    int down=help(i+1,j,triangle,n,dp);
    int diagDown=help(i+1,j+1,triangle,n,dp);
    
    return dp[i][j]=min(down,diagDown)+triangle[i][j];
}
int tabulation(vector<vector<int>>& triangle, int n){
    vector<vector<int>> dp(n,vector<int> (n,0));    
    
    // Base Case
    for(int j=0;j<n;j++){
        dp[n-1][j]=triangle[n-1][j];
    }
    
    for(int i=n-2;i>=0;i--){
        for(int j=i;j>=0;j--){
            int down=dp[i+1][j];
            int diagDown=dp[i+1][j+1];

            dp[i][j]=min(down,diagDown)+triangle[i][j];
        }
    }
    
    return dp[0][0];
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
//     vector<vector<int>> dp(n,vector<int> (n,-1));
//     return help(0,0,triangle,n,dp);
    
    return tabulation(triangle,n);
}