// Ismein hame number of combinations batane the 1 1 2 aur 1 2 1 alag combination hai to hamne kya kiya target ko rahne diya aur nums pe loop laga diya taki ye sare combinations ban jae
class Solution {
private:
    int help(vector<int> &nums,int target,vector<int> &dp){
        if(target==0) return 1;
        
        if(dp[target]!=-1) return dp[target];
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+= target>=nums[i] ? help(nums,target-nums[i],dp) : 0 ;
        }
        
        return dp[target]=ans;
    }
    int tabulation(vector<int>& nums, int target){
        vector<int> dp(target+1,0);
        
        // Base case
        dp[0]=1;
        
        for(int tar=1;tar<=target;tar++){
            long long ans=0;
            for(int i=0;i<nums.size();i++){
                ans+= tar>=nums[i] ? dp[tar-nums[i]] : 0 ;
            }
            dp[tar]=ans;
        }
        
        return dp[target];
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        
        // vector<int> dp(target+1,-1);
        // return help(nums,target,dp);
        
        return tabulation(nums,target);
    }
};