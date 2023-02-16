Count Number of Subsequences

Given a positive array, find the number of subsequences having product smaller than or equal to K.


#include <bits/stdc++.h> 
int mod=1000000007;
// int help(int i,int p,vector < int > & a, int n,vector<vector<int>> &dp){
//     if(i==n) return p>=1;

//     if(dp[i][p]!=-1) return dp[i][p];
//     int pick=help(i+1,p/a[i],a,n,dp);
//     int notPick=help(i+1,p,a,n,dp);

//     return dp[i][p]=(pick%mod+notPick%mod)%mod;

// }

// int tabulation(vector<int> &a, int n, int p) {


//     vector<vector<int>> dp(n+1,vector<int> (p+1,0));

//     // Base Case
    
//     for(int i=1;i<=p;i++) dp[n][i]=1;

//     for(int i=n-1;i>=0;i--){
//         for(int pp=1;pp<=p;pp++){

//             int pick=dp[i+1][pp/a[i]];
//             int notPick=dp[i+1][pp];

//             dp[i][pp]=(pick%mod+notPick%mod)%mod;
//         }
//     }

//     return dp[0][p];

// }

// int spaceOptimisation(vector<int> &a, int n, int p) {


//     vector<int> prev(p+1,0),curr(p+1,0);

//     // Base Case
    
//     for(int i=1;i<=p;i++) prev[i]=1;

//     for(int i=n-1;i>=0;i--){
//         for(int pp=1;pp<=p;pp++){

//             int pick=prev[pp/a[i]];
//             int notPick=prev[pp];

//             curr[pp]=(pick%mod+notPick%mod)%mod;
//         }
//         prev=curr;
//     }

//     return prev[p];

// }

int spaceOptimisationII(vector<int> &a, int n, int p) {


    vector<int> prev(p+1,0),curr(p+1,0);

    // Base Case
    
    for(int i=1;i<=p;i++) prev[i]=1;

    for(int i=n-1;i>=0;i--){
        for(int pp=p;pp>=0;pp--){

            int pick=prev[pp/a[i]];
            int notPick=prev[pp];

            prev[pp]=(pick%mod+notPick%mod)%mod;
        }
    }

    return prev[p];

}
int countSubsequences(vector < int > & a, int n, int p) {
    
    
    // vector<vector<int>> dp(n,vector<int> (p+1,-1));
    // return help(0,p,a,n,dp)-1; // Ek jab empty subsequence aega wo wala

    // return tabulation(a,n,p)-1; // Ek jab empty subsequence aega wo wala
    // return spaceOptimisation(a,n,p)-1; // Ek jab empty subsequence aega wo wala
    return spaceOptimisationII(a,n,p)-1; // Ek jab empty subsequence aega wo wala

}