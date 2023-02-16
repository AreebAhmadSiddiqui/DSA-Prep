// A wiggle sequence is a sequence where the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with one element and a sequence with two non-equal elements are trivially wiggle sequences.

// For example, [1, 7, 4, 9, 2, 5] is a wiggle sequence because the differences (6, -3, 5, -7, 3) alternate between positive and negative.
// In contrast, [1, 4, 7, 2, 5] and [1, 7, 4, 5, 5] are not wiggle sequences. The first is not because its first two differences are positive, and the second is not because its last difference is zero.
// A subsequence is obtained by deleting some elements (possibly zero) from the original sequence, leaving the remaining elements in their original order.

// Given an integer array nums, return the length of the longest wiggle subsequence of nums.

class Solution {
private:
//     int help(int i,int prevSign,vector<int> &nums,vector<vector<int>> &dp){
//         if(i==0) return 1;
        
//         int pick=0,notPick=0;
        
//         if(dp[i][prevSign]!=-1) return dp[i][prevSign];
        
//         if(prevSign==1 && nums[i]-nums[i-1]<0){
//             pick=1+help(i-1,0,nums,dp);
//         }else if(prevSign==0 && nums[i]-nums[i-1]>0){
//             pick=1+help(i-1,1,nums,dp);
//         }
        
//         notPick=0+help(i-1,prevSign,nums,dp);
        
//         return dp[i][prevSign]=max(pick,notPick);
//     }
//     int tabulation(vector<int> &nums){
        
//         int n=nums.size();
//         vector<vector<int>> dp(n,vector<int> (2,0));
        
//         // Base Case
//         dp[0][0]=dp[0][1]=1;
        
//         for(int i=1;i<n;i++){
//             for(int prevSign=0;prevSign<2;prevSign++){
//                 int pick=0,notPick=0;
//                 if(prevSign==1 && nums[i]-nums[i-1]<0){
//                     pick=1+dp[i-1][0];
//                 }else if(prevSign==0 && nums[i]-nums[i-1]>0){
//                     pick=1+dp[i-1][1];
//                 }

//                 notPick=0+dp[i-1][prevSign];
//                 dp[i][prevSign]=max(pick,notPick);
//             }
//         }
        
//         return max(dp[n-1][0],dp[n-1][1]);
//     }
//     int spaceOptimisation(vector<int> &nums){
        
//         int n=nums.size();
//         vector<int> prev(2,0),curr(2,0);
        
//         // Base Case
//         prev[0]=prev[1]=1;
        
//         for(int i=1;i<n;i++){
//             for(int prevSign=0;prevSign<2;prevSign++){
//                 int pick=0,notPick=0;
//                 if(prevSign==1 && nums[i]-nums[i-1]<0){
//                     cout<<prevSign<<" "<<i<<'\n';
//                     pick=1+prev[0];
//                 }else if(prevSign==0 && nums[i]-nums[i-1]>0){
//                     cout<<prevSign<<" "<<i<<'\n';
//                     pick=1+prev[1];
//                 }

//                 notPick=0+prev[prevSign];
//                 curr[prevSign]=max(pick,notPick);
//             }
//             prev=curr;
//         }
        
//         return max(prev[0],prev[1]);
//     }
    int spaceOptimisationII(vector<int> &nums){
        
        int n=nums.size();
        vector<int> prev(2,0),curr(2,0);
        
        // Base Case
        prev[0]=prev[1]=1;
        
        for(int i=1;i<n;i++){
            int pick=0,notPick=0;
            
            // prevSign==0 Case
            if(nums[i]-nums[i-1]>0){
                pick=1+prev[1];
            }
            notPick=0+prev[0];
            curr[0]=max(pick,notPick);

            
            // prevSign==1 Case
            if(nums[i]-nums[i-1]<0){
                pick=1+prev[0];
            }
            notPick=0+prev[1];
            curr[1]=max(pick,notPick);
            
            prev=curr;
        }
        
        return max(prev[0],prev[1]);
    }
public:
    int wiggleMaxLength(vector<int>& nums) {
        
//         int n=nums.size();
//         vector<vector<int>> dp(n,vector<int> (2,-1));
        
//         // {i,prevSign,nums} prevSign 1-> +ve 0 means negative
//         return max(help(n-1,1,nums,dp),help(n-1,0,nums,dp));
        
        // return tabulation(nums);
        // return spaceOptimisation(nums);
        return spaceOptimisationII(nums);
    }
};