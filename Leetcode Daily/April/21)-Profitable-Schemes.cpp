879. Profitable Schemes

There is a group of n members, and a list of various crimes they could commit. The ith crime generates a profit[i] and requires group[i] members to participate in it. If a member participates in one crime, that member can't participate in another crime.

Let's call a profitable scheme any subset of these crimes that generates at least minProfit profit, and the total number of members participating in that subset of crimes is at most n.

Return the number of schemes that can be chosen. Since the answer may be very large, return it modulo 109 + 7.

 
Approach

a) Poora Knapsack Jaisa hai bas 2 cheezein aur dhyan rakhni hai ki group mein at most n people honge
b) aur totalProfit>=minProfit hona chahiye
c) Main ek galti kar rha tha ki profit mein add kiye ja raha tha to usse 100*100 ka loop extra lag raha tha
d) mujhe to sirf profit minProfit se bada hai ki ni yahi chahiye to min wali condition laga di pick mein dekho 
e) kyunki mujhe sirf ways hi to chahiye agar profitTillNow minProfit hai to return 1 otherwise return 0
f) Baaki sab to understandable hai khud se hi


class Solution {
private:
    int mod=1000000007;
    int help(int i,int size,int n,int profitTillNow,int minProfit,vector<int> &group,vector<int> &profit,vector<vector<vector<int>>> &dp){
        
        if(i==size){
            return n>=0 && profitTillNow>=minProfit;
        }
        
        if(dp[i][n][profitTillNow]!=-1) return dp[i][n][profitTillNow];
        
        // Yahan hame sirf minProfit se matlab hai to profitTillNow ko minProfit se bada karne ka koi fayda ni wo extra iteration hi dega aur tle bhi
        int pick=n-group[i]>=0 ? help(i+1,size,n-group[i],min(minProfit,profitTillNow+profit[i]),minProfit,group,profit,dp) : 0;
        int notPick=help(i+1,size,n,profitTillNow,minProfit,group,profit,dp);
        
        return dp[i][n][profitTillNow]=(pick%mod+notPick%mod)%mod;
    }
    
    
//     int tabulation(int nn, int minProfit, vector<int>& group, vector<int>& profit) {
        
//         int size=group.size();
        
//         vector<vector<vector<int>>> dp(size+1,vector<vector<int>> (nn+1,vector<int> (minProfit+1,0)));
        
//         // Base Case
//         for(int n=0;n<=nn;n++){
//             for(int profitTillNow=0;profitTillNow<=minProfit;profitTillNow++){
//                 dp[size][n][profitTillNow]=profitTillNow>=minProfit;
//             }
//         }
        
//         for(int i=size-1;i>=0;i--){
//             for(int n=0;n<=nn;n++){
//                 for(int profitTillNow=minProfit;profitTillNow>=0;profitTillNow--){
                    
//                     int pick=n-group[i]>=0 ? dp[i+1][n-group[i]][min(minProfit,profitTillNow+profit[i])] : 0;
//                     int notPick=dp[i+1][n][profitTillNow];
                    
//                     dp[i][n][profitTillNow]=(pick%mod+notPick%mod)%mod;
//                 }
//             }
//         }
        
//         return dp[0][nn][0];
//     }
    
    int spaceOptimisation(int nn, int minProfit, vector<int>& group, vector<int>& profit) {
        
        int size=group.size();
        
        vector<vector<int>> prev(nn+1,vector<int> (minProfit+1,0)),curr(nn+1,vector<int> (minProfit+1,0));
        
        // Base Case
        for(int n=0;n<=nn;n++){
            for(int profitTillNow=0;profitTillNow<=minProfit;profitTillNow++){
                prev[n][profitTillNow]=profitTillNow>=minProfit;
            }
        }
        
        for(int i=size-1;i>=0;i--){
            for(int n=0;n<=nn;n++){
                for(int profitTillNow=minProfit;profitTillNow>=0;profitTillNow--){
                    
                    int pick=n-group[i]>=0 ? prev[n-group[i]][min(minProfit,profitTillNow+profit[i])] : 0;
                    int notPick=prev[n][profitTillNow];
                    
                    curr[n][profitTillNow]=(pick%mod+notPick%mod)%mod;
                }
            }
            prev=curr;
        }
        
        return prev[nn][0];
    }
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        
//         int size=group.size();
        
//         vector<vector<vector<int>>> dp(size,vector<vector<int>> (n+1,vector<int> (minProfit+1,-1)));
//         return help(0,size,n,0,minProfit,group,profit,dp);
        // return tabulation(n,minProfit,group,profit);
        return spaceOptimisation(n,minProfit,group,profit);
    }
};