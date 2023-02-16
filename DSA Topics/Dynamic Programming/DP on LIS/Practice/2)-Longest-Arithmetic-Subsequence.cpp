class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        
        // O(n*n*n)
        // Brute Force
        
//         int ans=0;
//         // Find two elements i.e given d and then solve
//         for(int i=0;i<nums.size();i++){
//             for(int j=i+1;j<nums.size();j++){
                
//                 int prevNum=nums[j];
//                 int diff=nums[j]-nums[i];
                
//                 // Now find the length of AP
//                 int len=2; // since two numbers taken
//                 for(int k=j+1;k<nums.size();k++){
//                       if(nums[k]-prevNum==diff){
//                           len++;
//                           prevNum=nums[k];
//                       }
//                 }
                
//                 ans=max(ans,len);
//             }       
//         }
//         return ans;
        
        
        // Simple LIS
        int n = nums.size(); int ret = INT_MIN;
        vector<vector<int>> dp(n, vector<int>(1001, 0));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                int diff = nums[i] - nums[j]+500; // for handling negative
                dp[i][diff] = max(2, dp[j][diff]+1); // why 2 because ye do elements to honge hi usse zyada hai to wo bhi le le
                ret = max(ret, dp[i][diff]);
            }
        }
        return ret;
    }
};