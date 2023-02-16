class Solution {
private:
     int help(int i,int hasSold,int txnsSoFar,vector<int> &prices,vector<vector<vector<int>>> &dp){
        
         // Base Case
        if(i==0) return hasSold ? -prices[i] : 0;
        
        if(dp[i][txnsSoFar][hasSold]!=-1) return dp[i][txnsSoFar][hasSold];
        
        int profit=0;
        if(hasSold==1){// it means I can buy or dontBuy
            int buy=0;
            if(txnsSoFar>0){ // if there are still txns left then do this
                buy= -prices[i]+help(i-1,0,txnsSoFar-1,prices,dp);
            }
            int notBuy= -0+help(i-1,1,txnsSoFar,prices,dp);
            profit=max(buy,notBuy);
        }else{ // I can sell or not sell
            int sell=0;
            if(txnsSoFar>0){ // if max txn no reached then only start this txn
                sell=prices[i]+help(i-1,1,txnsSoFar,prices,dp);
            }
            int notSell=0+help(i-1,0,txnsSoFar,prices,dp);
            profit=max(sell,notSell);
        }
        
        return dp[i][txnsSoFar][hasSold]=profit;
    }
    int tabulation(vector<int> &prices){
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (3, vector<int> (2,0)));
        
        // Base Case
        for(int txnsSoFar=0;txnsSoFar<=2;txnsSoFar++){
            dp[0][txnsSoFar][0]=0;
            dp[0][txnsSoFar][1]=-prices[0];
        }
        
        for(int i=1;i<n;i++){
            for(int txnsSoFar=0;txnsSoFar<=2;txnsSoFar++){
                for(int hasSold=0;hasSold<=1;hasSold++){
                    int profit=0;
                    if(hasSold==1){// it means I can buy or dontBuy
                        int buy=0;
                        if(txnsSoFar>0){ // if there are still txns left then do this
                            buy= -prices[i]+dp[i-1][txnsSoFar-1][0];
                        }
                        int notBuy= -0+dp[i-1][txnsSoFar][1];
                        profit=max(buy,notBuy);
                    }else{ // I can sell or not sell
                        int sell=0;
                        if(txnsSoFar>0){ // if max txn no reached then only start this txn
                            sell=prices[i]+dp[i-1][txnsSoFar][1];
                        }
                        int notSell=0+dp[i-1][txnsSoFar][0];
                        profit=max(sell,notSell);
                    }

                    dp[i][txnsSoFar][hasSold]=profit;
                }
            }
        }
        
        return dp[n-1][2][0];
    }
    int spaceOptimised(vector<int> &prices){
        int n=prices.size();
        vector<vector<int>> prev(3, vector<int> (2,0)),curr(3, vector<int> (2,0));
        
        // Base Case
        for(int txnsSoFar=0;txnsSoFar<=2;txnsSoFar++){
            prev[txnsSoFar][0]=0;
            prev[txnsSoFar][1]=-prices[0];
        }
        
        for(int i=1;i<n;i++){
            for(int txnsSoFar=0;txnsSoFar<=2;txnsSoFar++){
                for(int hasSold=0;hasSold<=1;hasSold++){
                    int profit=0;
                    if(hasSold==1){// it means I can buy or dontBuy
                        int buy=0;
                        if(txnsSoFar>0){ // if there are still txns left then do this
                            buy= -prices[i]+prev[txnsSoFar-1][0];
                        }
                        int notBuy= -0+prev[txnsSoFar][1];
                        profit=max(buy,notBuy);
                    }else{ // I can sell or not sell
                        int sell=0;
                        if(txnsSoFar>0){ // if max txn no reached then only start this txn
                            sell=prices[i]+prev[txnsSoFar][1];
                        }
                        int notSell=0+prev[txnsSoFar][0];
                        profit=max(sell,notSell);
                    }

                    curr[txnsSoFar][hasSold]=profit;
                }
            }
            prev=curr;
        }
        
        return prev[2][0];
    }
public:
    int maxProfit(vector<int>& prices) {
        // vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>> (3, vector<int> (2,-1)));
        // int n=prices.size();
        // return help(n-1,0,2,prices,dp); //{i,j,hasSold,prices,dp}
        
        // return tabulation(prices);
        return spaceOptimised(prices);
    }
};