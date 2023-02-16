class Solution {
public:
    int longestSubsequence(vector<int>& nums, int difference) {
        
        // O(n*n)
//         vector<int> dp(arr.size(),1);
        
//         int maxi=0;
//         for(int i=0;i<arr.size();i++){
//             for(int j=0;j<i;j++){
//                 if(arr[i]-arr[j]==difference && dp[j]+1>dp[i]){
//                     dp[i]=dp[j]+1;
//                 }
//             }
//             maxi=max(maxi,dp[i]);
//         }
//         return maxi;
        
        
         // Main har index se poochunga ki bhai koi nums[i]-difference kya peeche exist karta hai hai agar haan to aja main bhi include ho leta hun
        
        unordered_map<int,int> dp; // {i,count} {Count of AP sequence ending at i}
        
        int ans=0;
        for(int i=0;i<nums.size();i++){
            
            int prevEle=nums[i]-difference;
            int len=1;     // initially length 1 hogi aur agar pichla number exist kartah hoga to uski value bhi add kar dena
            if(dp.find(prevEle)!=dp.end()){
                len+=dp[prevEle];
            }
            
            dp[nums[i]]=len;
            ans=max(ans,len);
        }
        
        return ans;
    }
};