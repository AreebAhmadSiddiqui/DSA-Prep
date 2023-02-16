class Solution {
private:
    int help(int i,int amount,vector<int> &coins,vector<vector<int>> &dp){
        if(i==0){
            return amount%coins[0]==0 ? amount/coins[0] : 1e9;
        }
        
        if(dp[i][amount]!=-1) return dp[i][amount];
        
        int notPick=help(i-1,amount,coins,dp);
        int pick=INT_MAX;
        if(amount-coins[i]>=0) pick=1+help(i,amount-coins[i],coins,dp);
        
        return dp[i][amount]=min(pick,notPick);
    }
    int tabulation(vector<int>& coins, int amount){
        vector<vector<int>> dp(coins.size(),vector<int> (amount+1,0));
        
        // Base case
        
        for(int amt=0;amt<=amount;amt++){
            if(amt%coins[0]==0)
                dp[0][amt]= amt/coins[0];
            else
                dp[0][amt]= 1e9;
        }
        
        
        for(int i=1;i<coins.size();i++){
            for(int amt=0;amt<=amount;amt++){
                int notPick=dp[i-1][amt];
                int pick=INT_MAX;
                if(amt-coins[i]>=0) pick=1+dp[i][amt-coins[i]];

                dp[i][amt]=min(pick,notPick);
            }
        }
        
        return dp[coins.size()-1][amount]==1e9 ? -1 : dp[coins.size()-1][amount];
    }
    int spaceOptimised(vector<int>& coins, int amount){
        vector<int> prev(amount+1,0),curr(amount+1,0);
        
        // Base case
        
        for(int amt=0;amt<=amount;amt++){
            if(amt%coins[0]==0)
                prev[amt]= amt/coins[0];
            else
                prev[amt]= 1e9;
        }
        
        
        for(int i=1;i<coins.size();i++){
            for(int amt=0;amt<=amount;amt++){
                int notPick=prev[amt];
                int pick=INT_MAX;
                if(amt-coins[i]>=0) pick=1+curr[amt-coins[i]];

                curr[amt]=min(pick,notPick);
            }
            prev=curr;
        }
        
        return prev[amount]==1e9 ? -1 : prev[amount];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        
        
        // int ans=help(coins.size()-1,amount,coins,dp);
        // return ans==1e9 ? -1 : ans;
        
        // return tabulation(coins,amount);
          return spaceOptimised(coins,amount);
    }
};