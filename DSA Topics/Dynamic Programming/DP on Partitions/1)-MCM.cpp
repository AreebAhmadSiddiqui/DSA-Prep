#include <bits/stdc++.h> 

int f(int i,int j,vector<int> &arr,vector<vector<int>> &dp){
    
    if(i==j) return 0; // minimum case i.e only one matrix
    
    if(dp[i][j]!=-1) return dp[i][j];
    int mini=1e9;
    for(int k=i;k<j;k++){ // partition at i,i+1,... till j-1
        int steps=arr[i-1]*arr[k]*arr[j]+f(i,k,arr,dp)+f(k+1,j,arr,dp);
        mini=min(mini,steps);
    }
    
    return dp[i][j]=mini;
}
int tabulation(vector<int> &arr, int N){
    vector<vector<int>> dp(N,vector<int> (N,0));
    
    // Base Case
    for(int i=0;i<N;i++){
        dp[i][i]=0;
    }
    for(int i=N-1;i>=1;i--){
//         for(int j=1;j<=N-1;j--){ // But i less than j therefore it is wrong
        
        for(int j=i+1;j<=N-1;j++){ // Coreect
            int mini=1e9;
             for(int k=i;k<j;k++){ // partition at i,i+1,... till j-1
                 int steps=arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j];
                 mini=min(mini,steps);
             }       
            dp[i][j]=mini;
        }
    }
    
    return dp[1][N-1];
}
int matrixMultiplication(vector<int> &arr, int N)
{
//     vector<vector<int>> dp(N+1,vector<int> (N+1,-1));
    
//     return f(1,N-1,arr,dp);
    
    return tabulation(arr,N);
}