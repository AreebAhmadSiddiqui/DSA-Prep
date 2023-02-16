class Solution {
private:
    int help(int i,vector<int> &dp){
        if(i<0) return 0;
        
        if(i==0) return 1;
        
        if(dp[i]!=-1) return dp[i];
        
        int oneStep=help(i-1,dp);
        int twoStep=help(i-2,dp);
        
        return dp[i]=oneStep+twoStep;
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,0);
        // return help(n,dp);
        
        // Base Case
//          dp[0]=1;
//          dp[1]=1;
        
//         for(int i=2;i<=n;i++){
//             dp[i]=dp[i-1]+dp[i-2];
//         }
        
//         return dp[n];
        
        
        // Space Optimisation
        
         int prev2=1;
         int prev1=1;
         int curr;
        
        for(int i=2;i<=n;i++){
            curr=prev1+prev2;
            prev2=prev1;
            prev1=curr;
        }
        
        return prev1;
    }
};