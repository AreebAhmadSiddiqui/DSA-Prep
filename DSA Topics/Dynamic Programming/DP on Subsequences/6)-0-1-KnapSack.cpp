#include <bits/stdc++.h> 
int help(int i,vector<int> weight, vector<int> value, int maxWeight,vector<vector<int>> &dp){
    if(i==0){
        return maxWeight>=weight[0] ? value[0] : 0 ;
    }
    
    if(dp[i][maxWeight]!=-1) return dp[i][maxWeight];
    
    int notPick=0+help(i-1,weight,value,maxWeight,dp);
    int pick=0;
    if(maxWeight>=weight[i]) pick=value[i]+help(i-1,weight,value,maxWeight-weight[i],dp);
    
    return dp[i][maxWeight]= max(pick,notPick);
}
int tabulation(vector<int> weight, vector<int> value, int n, int maxWeight){
    vector<vector<int>> dp(n,vector<int> (maxWeight+1,0));    
    
    // Base Case
    
    for(int j=0;j<=maxWeight;j++){
        if(j>=weight[0]) dp[0][j]=value[0];
    }
    
    for(int i=1;i<n;i++){
        for(int wt=0;wt<=maxWeight;wt++){
            int notPick=0+dp[i-1][wt];
            int pick=0;
            if(wt>=weight[i]) pick=value[i]+dp[i-1][wt-weight[i]];

            dp[i][wt]= max(pick,notPick);
        }
    }
    
    return dp[n-1][maxWeight];
}
int spaceOptimised(vector<int> weight, vector<int> value, int n, int maxWeight){
    vector<int> prev(maxWeight+1,0),curr(maxWeight+1,0);    
    
    // Base Case
    
    for(int j=0;j<=maxWeight;j++){
        if(j>=weight[0]) prev[j]=value[0];
    }
    
    for(int i=1;i<n;i++){
        for(int wt=0;wt<=maxWeight;wt++){
            int notPick=0+prev[wt];
            int pick=0;
            if(wt>=weight[i]) pick=value[i]+prev[wt-weight[i]];

            curr[wt]= max(pick,notPick);
        }
        prev=curr;
    }
    
    return prev[maxWeight];
}
int furtherSpaceOptimised(vector<int> weight, vector<int> value, int n, int maxWeight){
    vector<int> prev(maxWeight+1,0);    
    
    // Base Case
    
    for(int j=0;j<=maxWeight;j++){
        if(j>=weight[0]) prev[j]=value[0];
    }
    
    for(int i=1;i<n;i++){
        for(int wt=maxWeight;wt>=0;wt--){
            int notPick=0+prev[wt];
            int pick=0;
            if(wt>=weight[i]) pick=value[i]+prev[wt-weight[i]];

            prev[wt]= max(pick,notPick);
        }
    }
    
    return prev[maxWeight];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
//     vector<vector<int>> dp(n,vector<int> (maxWeight+1,-1));
// 	return help(n-1,weight,value,maxWeight,dp);
    
//     return tabulation(weight,value,n,maxWeight);
//      return spaceOptimised(weight,value,n,maxWeight);
    return furtherSpaceOptimised(weight,value,n,maxWeight);
}