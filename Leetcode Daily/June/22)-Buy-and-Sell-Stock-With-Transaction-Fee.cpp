class Solution {
private:
//     int help(int i,int n,vector<int> &prices,int fee,int boughtAlready,vector<vector<int>> &dp){
//         if(i==n){
//             return 0;
//         }
        
//         if(dp[i][boughtAlready]!=-1) return dp[i][boughtAlready];
//         int profit=0;
//         if(boughtAlready==1){
//             int sell=+prices[i]-fee+help(i+1,n,prices,fee,0,dp);
//             int notSell=0+help(i+1,n,prices,fee,1,dp);
//             profit=max(profit,max(sell,notSell));
//         }else{
//             int buy=-prices[i]+help(i+1,n,prices,fee,1,dp);
//             int notBuy=0+help(i+1,n,prices,fee,0,dp);
//             profit=max(profit,max(buy,notBuy));
//         }
//         return dp[i][boughtAlready]=profit;
//     }
    
//     int tabulation(vector<int>& prices, int fee) {
//         int n=prices.size();
//         vector<vector<int>> dp(n+1,vector<int> (2,0));
        
//         // Base Case Done
//         for(int i=n-1;i>=0;i--){
//             int profit=0;
//             int sell=+prices[i]-fee+dp[i+1][0];
//             int notSell=0+dp[i+1][1];
//             profit=max(profit,max(sell,notSell));
//             dp[i][1]=profit;

//             profit=0;
//             int buy=-prices[i]+dp[i+1][1];
//             int notBuy=0+dp[i+1][0];
//             profit=max(profit,max(buy,notBuy));
//             dp[i][0]=profit;
//         }
//         return dp[0][0];
//     }
    
    int spaceOptimised(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<int> next(2,0),curr(2,0);
        
        // Base Case Done
        
        for(int i=n-1;i>=0;i--){
            
            curr[1]=max(0,max(prices[i]-fee+next[0],0+next[1]));
            
            curr[0]=max(0,max(-prices[i]+next[1],0+next[0]));
            
            next=curr;
        }
        return curr[0];
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        
        // int n=prices.size();
        // vector<vector<int>> dp(n,vector<int> (2,-1));
        // return help(0,prices.size(),prices,fee,0,dp);
        // return tabulation(prices,fee);
        return spaceOptimised(prices,fee);
    }
};