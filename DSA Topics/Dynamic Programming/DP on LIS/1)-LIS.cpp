class Solution {
private:
    
// Recursive O(n*n)
int help(int i,int j,vector<int> &nums,vector<vector<int>> &dp){
    
    if(i==0){
        if(j==nums.size()) return 0;
        return nums[0]<nums[j];
    }
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    int pick=0,notPick=0;
    if(j==nums.size() || nums[i]<nums[j]) pick=1+help(i-1,i,nums,dp);
    notPick=help(i-1,j,nums,dp);
    
    return dp[i][j]=max(pick,notPick);
}
// O(n*n) O(n)
int tabulation(vector<int> &nums){
    
    vector<int> dp(nums.size(),1); // as everyone would be the lis themselves
    
    int ans=0;
    for(int i=0;i<nums.size();i++){
        for(int j=0;j<i;j++){
            if(nums[j]<nums[i] && dp[j]+1>dp[i]){
                dp[i]=dp[j]+1;
            }
        }
        ans=max(ans,dp[i]);
    }
    return ans;
}
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        return help(n-1,n,nums,dp);
    }
};