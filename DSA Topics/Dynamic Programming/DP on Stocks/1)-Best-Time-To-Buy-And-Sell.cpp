class Solution {
public:
    // O(n) O(1)
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int maxi=0;
        
        for(int i=prices.size()-1;i>=0;i--){
            
            maxi=max(maxi,prices[i]);
            ans=max(ans,maxi-prices[i]);
        }
        
        return ans;
    }
};


// DP Solution
class Solution {
private:
    int help(int i,int j,vector<int> &prices,vector<vector<int>> &dp){
        if(i==0 || j==0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int sell=help(i-1,j,prices,dp); // I decide to sell it here
        int notSell=help(i-1,j-1,prices,dp);
        
        return dp[i][j]=max(prices[j-1]-prices[i-1],max(sell,notSell));
    }
    int tabulation()
public:
    // O(n) O(1)
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1,vector<int> (prices.size()+1,-1));
        return help(prices.size(),prices.size(),prices,dp);
    }
};