#include <bits/stdc++.h> 

// long long mod=1000000007;
// int help(int i,int j,int isTrue,string &a,vector<vector<vector<long long>>> &dp){
//     if(i>j) return 0;
//     if(i==j){
//         if(isTrue==1) return a[i]=='T';
//         else return a[i]=='F';
//     }
//     if(dp[i][j][isTrue]!=-1) return dp[i][j][isTrue]; 
//     long long ways=0;
//     for(int ind=i+1;ind<=j-1;ind+=2){
        
//         long long lT=help(i,ind-1,1,a,dp);
//         long long lF=help(i,ind-1,0,a,dp);
//         long long rT=help(ind+1,j,1,a,dp);
//         long long rF=help(ind+1,j,0,a,dp);
        
//         if(a[ind]=='&'){
//             if(isTrue){
//                 ways=(ways+(lT*rT)%mod)%mod;
//             }
//             else{
//                 ways=(ways+(lT*rF)%mod+(lF*rT)%mod+(lF*rF)%mod)%mod;
//             }
//         }
//         else if(a[ind]=='|'){
//             if(isTrue==0){
//                 ways=(ways+(lF*rF)%mod)%mod;
//             }
//             else{
//                 ways=(ways+(lT*rF)%mod+(lF*rT)%mod+(lT*rT)%mod)%mod;
//             }
//         }
//         else{
//             if(isTrue){
//                 ways=(ways+(lF*rT)%mod+(lT*rF))%mod;
//             }
//             else{
//                 ways=(ways+(lT*rT)%mod+(lF*rF)%mod)%mod;
//             }
//         }
//     }
//     return dp[i][j][isTrue]=ways;
// }
// int evaluateExp(string & exp) {
//     int n=exp.size();
//     vector<vector<vector<long long>>> dp(n,vector<vector<long long>> (n,vector<long long> (2,-1)));
//     return help(0,n-1,1,exp,dp);
// }


// long long mod=1000000007;
// int help(int i,int j,int isTrue,string &a,vector<vector<vector<long long>>> &dp){
//     if(i>j) return 0;
//     if(i==j){
//         if(isTrue==1) return a[i]=='T';
//         else return a[i]=='F';
//     }
//     if(dp[i][j][isTrue]!=-1) return dp[i][j][isTrue]; 
//     long long ways=0;
//     for(int ind=i+1;ind<=j-1;ind+=2){
        
//         long long lT=help(i,ind-1,1,a,dp);
//         long long lF=help(i,ind-1,0,a,dp);
//         long long rT=help(ind+1,j,1,a,dp);
//         long long rF=help(ind+1,j,0,a,dp);
        
//         if(a[ind]=='&'){
//             if(isTrue){
//                 ways=(ways+(lT*rT)%mod)%mod;
//             }
//             else{
//                 ways=(ways+(lT*rF)%mod+(lF*rT)%mod+(lF*rF)%mod)%mod;
//             }
//         }
//         else if(a[ind]=='|'){
//             if(isTrue==0){
//                 ways=(ways+(lF*rF)%mod)%mod;
//             }
//             else{
//                 ways=(ways+(lT*rF)%mod+(lF*rT)%mod+(lT*rT)%mod)%mod;
//             }
//         }
//         else{
//             if(isTrue){
//                 ways=(ways+(lF*rT)%mod+(lT*rF))%mod;
//             }
//             else{
//                 ways=(ways+(lT*rT)%mod+(lF*rF)%mod)%mod;
//             }
//         }
//     }
//     return dp[i][j][isTrue]=ways;
// }
// int evaluateExp(string & exp) {
//     int n=exp.size();
//     vector<vector<vector<long long>>> dp(n,vector<vector<long long>> (n,vector<long long> (2,-1)));
//     return help(0,n-1,1,exp,dp);
// }

long long mod=1000000007;
int evaluateExp(string & a) {
    int n=a.size();
    vector<vector<vector<long long>>> dp(n,vector<vector<long long>> (n,vector<long long> (2, 0)));
    
    // Base Case
    for(int i=0;i<n;i++){
        dp[i][i][0] = a[i]=='F';
        dp[i][i][1] = a[i]=='T';
    }
    
    for(int i=n-1;i>=0;i--){
        for(int j=i+1;j<n;j++){
            for(int isTrue=0;isTrue<=1;isTrue++){
                long long ways=0;
                for(int ind=i+1;ind<=j-1;ind+=2){
                    long long lT=dp[i][ind-1][1];
                    long long lF=dp[i][ind-1][0];
                    long long rT=dp[ind+1][j][1];
                    long long rF=dp[ind+1][j][0];

                    if(a[ind]=='&'){
                        if(isTrue){
                            ways=(ways+(lT*rT)%mod)%mod;
                        }
                        else{
                            ways=(ways+(lT*rF)%mod+(lF*rT)%mod+(lF*rF)%mod)%mod;
                        }
                    }
                    else if(a[ind]=='|'){
                        if(isTrue==0){
                            ways=(ways+(lF*rF)%mod)%mod;
                        }
                        else{
                            ways=(ways+(lT*rF)%mod+(lF*rT)%mod+(lT*rT)%mod)%mod;
                        }
                    }
                    else{
                        if(isTrue){
                            ways=(ways+(lF*rT)%mod+(lT*rF))%mod;
                        }
                        else{
                            ways=(ways+(lT*rT)%mod+(lF*rF)%mod)%mod;
                        }
                    }
                }
                dp[i][j][isTrue]=ways;
            }
        }
    }
    return dp[0][n-1][1];
}