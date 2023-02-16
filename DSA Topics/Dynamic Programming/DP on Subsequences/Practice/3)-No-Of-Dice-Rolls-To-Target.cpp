Number of Dice Rolls With Target Sum
You have n dice, and each die has k faces numbered from 1 to k.

Given three integers n, k, and target, return the number of possible ways (out of the kn total ways) to roll the dice, so the sum of the face-up numbers equals target. Since the answer may be too large, return it modulo 109 + 7.

Input: n = 1, k = 6, target = 3
Output: 1
Explanation: You throw one die with 6 faces.
There is only one way to get a sum of 3.
    
    
n ka matlab index manlo aur har index pe tum 1 se k tak kuch bhi le sakte ho bas waise hi dp bana lo

n=2 k=6
nums=[6,6] ab tumhe har i se (1-6) ke beech mein ek banda lena hai aur dekhna hai uska sum target ke barabar a raha hai ki ni agar han to sahi hai ni to doosra k leke dekho 
class Solution {
private:
    int mod=1000000007;
//     int help(int n,int target,int k,vector<vector<int>> &dp){
//         if(n==0) return target==0;
        
//         if(dp[n][target]!=-1) return dp[n][target];
        
//         int ways=0;
//         for(int j=1;j<=k;j++){
//             if(target-j>=0) ways=(ways%mod+help(n-1,target-j,k,dp)%mod)%mod;
//         }
        
//         return dp[n][target]=ways;
//     }
//     int tabulation(int n,int k,int target){
//         vector<vector<int>> dp(n+1,vector<int> (target+1,0));
        
//         // Base Case
//         dp[0][0]=1;
        
//         for(int i=1;i<=n;i++){
//             for(int tar=0;tar<=target;tar++){
                
//                 int ways=0;
//                 for(int j=1;j<=k;j++){
//                     if(tar-j>=0) ways=(ways%mod+dp[i-1][tar-j]%mod)%mod;
//                 }
//                 dp[i][tar]=ways;
//             }
//         }
//         return dp[n][target];
//     }
    int spaceOptimised(int n,int k,int target){
        vector<int> prev(target+1,0),curr(target+1,0);
        
        // Base Case
        prev[0]=1;
        
        for(int i=1;i<=n;i++){
            for(int tar=0;tar<=target;tar++){
                
                int ways=0;
                for(int j=1;j<=k;j++){
                    if(tar-j>=0) ways=(ways%mod+prev[tar-j]%mod)%mod;
                }
                curr[tar]=ways;
            }
            prev=curr;
        }
        return prev[target];
    }
    int spaceOptimisedII(int n,int k,int target){
        vector<int> prev(target+1,0);
        
        // Base Case
        prev[0]=1;
        
        for(int i=1;i<=n;i++){
            for(int tar=target;tar>=0;tar--){
                
                int ways=0;
                for(int j=1;j<=k;j++){
                    if(tar-j>=0) ways=(ways%mod+prev[tar-j]%mod)%mod; // sirf left walon pe depend kar raha
                }
                prev[tar]=ways;
            }
        }
        return prev[target];
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        
        // vector<vector<int>> dp(n+1,vector<int> (target+1,-1));
        // return help(n,target,k,dp);
        
        // return tabulation(n,k,target);
        return spaceOptimised(n,k,target);
    }
};