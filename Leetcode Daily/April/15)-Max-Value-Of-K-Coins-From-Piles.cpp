2218. Maximum Value of K Coins From Piles

There are n piles of coins on a table. Each pile consists of a positive number of coins of assorted denominations.

In one move, you can choose any coin on top of any pile, remove it, and add it to your wallet.

Given a list piles, where piles[i] is a list of integers denoting the composition of the ith pile from top to bottom, and a positive integer k, return the maximum total value of coins you can have in your wallet if you choose exactly k coins optimally.
    

class Solution {
private:
//     int help(int i,vector<vector<int>>& piles, int k,vector<vector<int>> &dp) {
        
//         if(i==piles.size()){
//             return 0;
//         }
        
//         if(dp[i][k]!=-1) return dp[i][k];
        
//         int sum=0;
//         int ans=0;
//         int tempK=k;
//         for(int j=0;j<piles[i].size();j++){
//             if(tempK>0){
//                 tempK--;
//                 sum+=piles[i][j];
//                 ans=max(ans,sum+help(i+1,piles,tempK,dp));
//             }
//         }
//         int notPick=0+help(i+1,piles,k,dp);
        
//         return dp[i][k]=max(ans,notPick);
//     }
//     int tabulation(vector<vector<int>>& piles,int kk) {
        
//         int n=piles.size();
//         vector<vector<int>> dp(n+1,vector<int> (kk+1,0));
        
//         // Base Case done
//         for(int i=n-1;i>=0;i--){
//             for(int k=0;k<=kk;k++){
//                 int sum=0;
//                 int ans=0;
//                 int tempK=k;
//                 for(int j=0;j<piles[i].size();j++){
//                     if(tempK>0){
//                         tempK--;
//                         sum+=piles[i][j];
//                         ans=max(ans,sum+dp[i+1][tempK]);
//                     }
//                 }
//                 int notPick=0+dp[i+1][k];

//                dp[i][k]=max(ans,notPick);
//             }
//         }
//         return dp[0][kk];
//     }
    int sO(vector<vector<int>>& piles,int kk) {
        
        int n=piles.size();
        vector<int> prev(kk+1,0),curr(kk+1,0);
        
        // Base Case done
        for(int i=n-1;i>=0;i--){
            for(int k=0;k<=kk;k++){
                int sum=0;
                int ans=0;
                int tempK=k;
                for(int j=0;j<piles[i].size();j++){
                    if(tempK>0){
                        tempK--;
                        sum+=piles[i][j];
                        ans=max(ans,sum+prev[tempK]);
                    }
                }
                int notPick=0+prev[k];

                curr[k]=max(ans,notPick);
            }
            prev=curr;
        }
        return prev[kk];
    }
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        
        // int n=piles.size();
        // vector<vector<int>> dp(n,vector<int> (k+1,-1));
        // return help(0,piles,k,dp);
        // return tabulation(piles,k);
        return sO(piles,k);
    }
};