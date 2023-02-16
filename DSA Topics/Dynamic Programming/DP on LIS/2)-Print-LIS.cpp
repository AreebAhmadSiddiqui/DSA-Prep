int tabulation(vector<int> &nums){
    
    vector<int> dp(nums.size(),1); // as everyone would be the lis themselves
    vector<int> parent(nums.size(),0);
    
    for(int i=0;i<nums.size();i++) parent[i]=i;
    
    int maxLis=0;
    int ans=0;
    for(int i=0;i<nums.size();i++){
        for(int j=0;j<i;j++){
            if(nums[j]<nums[i] && dp[j]+1>dp[i]){
                dp[i]=dp[j]+1;
                parent[i]=j;
                maxLis=i;
            }
        }
        ans=max(ans,dp[i]);
    }
    
    
    while(parent[maxLis]!=maxLis){
        cout<<nums[maxLis]<<" ";
        maxLis=parent[maxLis];
    }
    cout<<nums[maxLis]<<'\n';
    return ans;
}
public:
    int lengthOfLIS(vector<int>& nums) {
        // int n=nums.size();
        // vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        // return help(n-1,n,nums,dp);
        
        return tabulation(nums);
    }
};