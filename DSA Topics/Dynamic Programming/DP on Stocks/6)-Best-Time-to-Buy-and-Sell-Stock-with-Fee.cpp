class Solution {
private:
    int help(int i,int hasSold,vector<int> &prices,vector<vector<int>> &dp,int fee){
        // Base Case
        if(i==0){
            // definitely need to buy id soldAlready
            return hasSold ? -prices[0]-fee : 0;
        }
        
        if(dp[i][hasSold]!=-1) return dp[i][hasSold];
        
        int profit=0;
        if(hasSold==1){// it means I can buy or dontBuy
            int buy= -prices[i]+help(i-1,0,prices,dp,fee)-fee;
            int notBuy= -0+help(i-1,1,prices,dp,fee);
            profit=max(buy,notBuy);
        }else{ // I can sell or not sell
            int sell=prices[i]+help(i-1,1,prices,dp,fee);
            int notSell=0+help(i-1,0,prices,dp,fee);
            profit=max(sell,notSell);
        }
        
        return dp[i][hasSold]=profit;
    }
    int tabulation(vector<int> &prices,int fee){
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int> (2,0));
        
        // Base Case
        dp[0][0]=0;
        dp[0][1]=-prices[0]-fee;
        
        for(int i=1;i<n;i++){
            int profit=0;
        // if(soldAlready==1)// it means I can buy or dontBuy
            int buy= -prices[i]+dp[i-1][0]-fee;
            int notBuy= -0+dp[i-1][1];
            profit=max(buy,notBuy);
            dp[i][1]=profit;        


        // }else{ // I can sell or not sell
            int sell=prices[i]+dp[i-1][1];
            int notSell=0+dp[i-1][0];
            profit=max(sell,notSell);
            dp[i][0]=profit;
        }
        
        return dp[n-1][0];
    }
      int spaceOptimised(vector<int> &prices,int fee){
        int n=prices.size();
        vector<int> prev(2,0),curr(2,0);
        
        // Base Case
        prev[0]=0;
        prev[1]=-prices[0]-fee;
        
        for(int i=1;i<n;i++){
            int profit=0;
        
            // it means I can buy or dontBuy
            int buy= -prices[i]+prev[0]-fee;
            int notBuy= -0+prev[1];
            profit=max(buy,notBuy);
            curr[1]=profit;        


            // I can sell or not sell
            int sell=prices[i]+prev[1];
            int notSell=0+prev[0];
            profit=max(sell,notSell);
            curr[0]=profit;
            
            prev=curr;
        }
        
        return prev[0];
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        // vector<vector<int>> dp(prices.size(),vector<int> (2,-1));
        // int n=prices.size();
        // return help(n-1,0,prices,dp,fee); //{i,j,hasSold,prices,dp}
        
         // return tabulation(prices,fee);
        return spaceOptimised(prices,fee);
    }
};