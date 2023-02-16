#include<bits/stdc++.h>
using namespace std;
int help(int i,int target,vector<int> &price,vector<vector<int>> &dp){
    if(i==0){
        return (target/(i+1))*price[0];
    }
    
    if(dp[i][target]!=-1) return dp[i][target];
    int notPick=help(i-1,target,price,dp);
    int pick=0;
    if(i+1<=target) pick=price[i]+help(i,target-(i+1),price,dp);
    
    return dp[i][target]=max(pick,notPick);
}
int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n,vector<int> (n+1,-1));
	return help(n-1,n,price,dp);
}
