#include <bits/stdc++.h> 
int help(int i,vector<int> &heights,vector<int> &dp){
    if(i<0) return 0;
    if(i==0) return 0;
    
    if(dp[i]!=-1) return dp[i];
    
    int oneSizeJump=abs(heights[i-1]-heights[i])+help(i-1,heights,dp);
    int twoSizeJump=INT_MAX;
    if(i-2>=0) twoSizeJump=abs(heights[i-2]-heights[i])+help(i-2,heights,dp);
    
    return dp[i]=min(oneSizeJump,twoSizeJump);
}
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1,-1);
    return help(n-1,heights,dp);
}

// Tabulation
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1,0);
     
    Base Case
    dp[0]=0;
    for(int i=1;i<n;i++){
        int oneSizeJump=abs(heights[i-1]-heights[i])+dp[i-1];
        int twoSizeJump=INT_MAX;
        if(i-2>=0) twoSizeJump=abs(heights[i-2]-heights[i])+dp[i-2];
        dp[i]=min(oneSizeJump,twoSizeJump);
    }
    
    return dp[n-1];
}
   
    
// Space Optimisation

int frogJump(int n, vector<int> &heights)
{
    
     int prev=0;
     int prev2,curr;
     for(int i=1;i<n;i++){
        int oneSizeJump=abs(heights[i-1]-heights[i])+prev;
        int twoSizeJump=INT_MAX;
        if(i-2>=0) twoSizeJump=abs(heights[i-2]-heights[i])+prev2;
        curr=min(oneSizeJump,twoSizeJump);
         
         prev2=prev;
         prev=curr;
    }
    
    return prev;
}