956. Tallest Billboard

You are installing a billboard and want it to have the largest height. The billboard will have two steel supports, one on each side. Each steel support must be an equal height.

You are given a collection of rods that can be welded together. For example, if you have rods of lengths 1, 2, and 3, you can weld them together to make a support of length 6.

Return the largest possible height of your billboard installation. If you cannot support the billboard, return 0.
    
    
class Solution {
private:
    int help(int i,int n,int diff,vector<int> &nums,vector<vector<int>> &dp){
        if(i==n){
            return diff==0 ? 0 : -1e9;
        }
        
        if(dp[i][diff+5000]!=-1) return dp[i][diff+5000];
        
        int notPick=help(i+1,n,diff,nums,dp);
        int pick1=nums[i]+help(i+1,n,diff-nums[i],nums,dp);
        int pick2=nums[i]+help(i+1,n,diff+nums[i],nums,dp);
        
        return dp[i][diff+5000]=max(notPick,max(pick1,pick2));
    }
public:
    int tallestBillboard(vector<int>& rods) {
         
        int n=rods.size();
        vector<vector<int>> dp(n+1,vector<int> (10001,-1));
        return help(0,n,0,rods,dp)/2;
    }
};