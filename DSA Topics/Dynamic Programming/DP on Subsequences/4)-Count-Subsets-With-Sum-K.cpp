#include <bits/stdc++.h> 
// Yahan pe zero ka jhol jhal tha to dhyan rakhna
int help(int i,vector<int> &num,int tar,vector<vector<int>> &dp){
    if(i==0){
        if(tar==0 && num[0]==0) return 2;
        if(tar==0 || num[0]==tar) return 1;
        
        return 0;
    }
    
    if(dp[i][tar]!=-1) return dp[i][tar];
    
    int pick=0;
    if(tar-num[i]>=0) pick=help(i-1,num,tar-num[i],dp);
    int notPick=help(i-1,num,tar,dp);
    
    return dp[i][tar]=pick+notPick;
}
int tabulation(vector<int> &num, int tar){

    int n = num.size();

    vector<vector<int>> dp(n,vector<int>(tar+1,0));

    if(num[0] == 0) dp[0][0] =2;  // 2 cases -pick and not pick
    else dp[0][0] = 1;  // 1 case - not pick

    if(num[0]!=0 && num[0]<=tar) dp[0][num[0]] = 1;  // 1 case -pick

    for(int ind = 1; ind<n; ind++){
        for(int target= 0; target<=tar; target++){

            int notTaken = dp[ind-1][target];

            int taken = 0;
            if(num[ind]<=target)
                taken = dp[ind-1][target-num[ind]];

            dp[ind][target]= (notTaken + taken);
        }
    }
    return dp[n-1][tar];
}
int findWays(vector<int> &num, int tar)
{
//     vector<vector<int>> dp(num.size(),vector<int> (tar+1,-1));
//     return help(num.size()-1,num,tar,dp);
    
    return tabulation(num,tar);
}