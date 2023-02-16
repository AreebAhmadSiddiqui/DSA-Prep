class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1); // as everyone would be the lis themselves
        
        vector<int> count(nums.size(),1);
        
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    if(dp[j]+1>dp[i]){ // if it is greater just take the previous guys cnt because if he can form x lis then you can also form x lis
                        dp[i]=dp[j]+1;
                        // inherit

                        // count ways of graph wale jaise socho
                        
                        // single path chal raha abhi tak isliye jitne mein tum a sakte utne main main
                        count[i]=count[j];
                    }
                    else if(dp[j]+1==dp[i]){ // it is equal
                        
                        // increase the count of i with j

                        // Ek path to tha hi aur ye wala path bhi a gaya to isi jod leta hun
                        count[i]+=count[j];
                    }
                }
            }
            maxi=max(maxi,dp[i]);
        }
        
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(maxi==dp[i]) cnt+=count[i];
        }
        return cnt;
    }
};