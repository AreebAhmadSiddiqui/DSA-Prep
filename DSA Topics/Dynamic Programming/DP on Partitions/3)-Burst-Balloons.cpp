class Solution {
private:
    int f(int i,int j,vector<int> &nums,vector<vector<int>> &dp){
        
        if(i>j) return 0; // no partition left,  i==j means ek balon bacha hai
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int maxi=-1e9;
        for(int k=i;k<=j;k++){
            int steps=nums[j+1]*nums[i-1]*nums[k]+f(i,k-1,nums,dp)+f(k+1,j,nums,dp);
            maxi=max(maxi,steps);
        }
        
        return dp[i][j]=maxi;
    }
    int tabulation(vector<int> &nums){
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        
        vector<vector<int>> dp(n+2,vector<int> (n+2,0));
        
        for(int i=n;i>=1;i--){
            for(int j=i;j<=n;j++){
                int maxi=-1e9;
                for(int k=i;k<=j;k++){
                    int steps=nums[j+1]*nums[i-1]*nums[k]+dp[i][k-1]+dp[k+1][j];
                    maxi=max(maxi,steps);
                }

                dp[i][j]=maxi;
            }
        }
        
        return dp[1][n];
    }
public:
    int maxCoins(vector<int>& nums) {
        
//         int n=nums.size();
//         nums.insert(nums.begin(),1);
//         nums.push_back(1);
        
//         vector<vector<int>> dp(n+2,vector<int> (n+2,-1));
//         return f(1,n,nums,dp);
        
        return tabulation(nums);
    }
};