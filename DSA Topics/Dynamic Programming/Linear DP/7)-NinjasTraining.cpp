#include<bits/stdc++.h>

// Memoization
int help(int i,int prev,vector<vector<int>> &points,vector<vector<int>> &dp){
    if(i==0) {
        int maxi=INT_MIN;
        for(int j=0;j<3;j++){
            if(j!=prev){
                maxi=max(maxi,points[i][j]);
            }
        }
        return maxi;
    }
    
    if(dp[i][prev]!=-1) return dp[i][prev];
    int maxPoints=0;
    for(int k=0;k<3;k++){
        if(k!=prev){
            maxPoints=max(maxPoints,points[i][k]+help(i-1,k,points,dp));
        }
    }
    
    return dp[i][prev]=maxPoints;
}
int tabulation(int n, vector<vector<int>> &points){
    vector<vector<int>> dp(n,vector<int> (4,0));
    
    // Base Case
    dp[0][0]= max(points[0][1],points[0][2]);
    dp[0][1]= max(points[0][0],points[0][2]);
    dp[0][2]= max(points[0][0],points[0][1]);
    dp[0][3]= max(points[0][0],max(points[0][1],points[0][2]));
    
    for(int i=1;i<n;i++){
        for(int prev=0;prev<4;prev++){
            int maxPoints=0;
            for(int k=0;k<3;k++){
                if(k!=prev){
                    maxPoints=max(maxPoints,points[i][k]+dp[i-1][k]);
                }
            }
            dp[i][prev]=maxPoints;
        }
    }
    
    return dp[n-1][3];
}

int spaceOptimisation(int n, vector<vector<int>> &points){
    vector<int> prev(4,0),curr(4,0);
    
    // Base Case
    prev[0]= max(points[0][1],points[0][2]);
    prev[1]= max(points[0][0],points[0][2]);
    prev[2]= max(points[0][0],points[0][1]);
    prev[3]= max(points[0][0],max(points[0][1],points[0][2]));
    
    for(int i=1;i<n;i++){
        for(int j=0;j<4;j++){
            int maxPoints=0;
            for(int k=0;k<3;k++){
                if(k!=j){
                    maxPoints=max(maxPoints,points[i][k]+prev[k]);
                }
            }
            curr[j]=maxPoints;
        }
        prev=curr;
    }
    
    return prev[3];
}


int ninjaTraining(int n, vector<vector<int>> &points)
{
//     vector<vector<int>> dp(n,vector<int> (4,-1));
//     return help(n-1,3,points,dp); // i chose prev as 3 because pehle -1 le raha tha to dikkat aegi na
//     islye 3 index le lo kyunki wo hai hi ni
    
//     return tabulation(n,points);
    
    return spaceOptimisation(n,points);
}

