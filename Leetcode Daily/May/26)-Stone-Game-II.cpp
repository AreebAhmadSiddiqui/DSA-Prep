1140. Stone Game II

Alice and Bob continue their games with piles of stones.  There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].  The objective of the game is to end with the most stones. 

Alice and Bob take turns, with Alice starting first.  Initially, M = 1.

On each player's turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M.  Then, we set M = max(M, X).

The game continues until all the stones have been taken.

Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get


Approach

a) Ham diff of scores le rahe hai - help kiya
b) Diff a gaya to alice ka score kya hoga (a-b we have a+b we have a= (diff+sum)/2)
    
class Solution {
private:
//     int help(int i,int M,int n,vector<int> &piles,vector<vector<int>> &dp){
//         if(i==n) return 0;
        
//         int ans=-1e9;
//         int sum=0;
        
//         if(dp[i][M]!=-1) return dp[i][M];
//         for(int j=0;j<2*M;j++){
//             if(i+j>=n) break;
//             sum+=piles[i+j];
//             ans=max(ans,sum-help(i+j+1,max(M,j+1),n,piles,dp));
//         }
//         return dp[i][M]=ans;
//     }
    int tabulation(vector<int>& piles) {
        int n=piles.size();
        int sum=0;
        for(int i=0;i<n;i++) sum+=piles[i];
        
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        
        for(int i=n-1;i>=0;i--){
            for(int M=n;M>=1;M--){
                int ans=-1e9;
                int s=0;
                for(int j=0;j<2*M;j++){
                    if(i+j>=n) break;
                    s+=piles[i+j];
                    ans=max(ans,s-dp[i+j+1][max(M,j+1)]);
                }
                dp[i][M]=ans;
            }
        }
        
        int diff=dp[0][1];
        return (sum+diff)/2;
    }
public:
    int stoneGameII(vector<int>& piles) {
//         int n=piles.size();
        
//         vector<vector<int>> dp(n,vector<int> (n+1,-1));
//         int diff=help(0,1,n,piles,dp);
//         int sum=0;
//         for(int i=0;i<n;i++) sum+=piles[i];
        
//         return (sum+diff)/2;
        
        return tabulation(piles);
    }
};