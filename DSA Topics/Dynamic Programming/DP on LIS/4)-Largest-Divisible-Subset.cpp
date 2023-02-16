class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> dp(nums.size(),1);

        sort(nums.begin(),nums.end());
        
        int startIndex=0;
        vector<int> parent(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            parent[i]=i;
        }
        
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    parent[i]=j;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                startIndex=i;
            }
        }
        
        vector<int> ans;
        
        while(startIndex!=parent[startIndex]){
            ans.push_back(nums[startIndex]);
            startIndex=parent[startIndex];
        }
        ans.push_back(nums[startIndex]);
        
        return ans;
    }
};