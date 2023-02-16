Yahan to hamne 3 se divisisle wala solve kiya hai lekin k bhi de sakte wo log
bas remainders se khelna hai and simple dp laga do sum lete jao agar pick kar rahe ho to aur remainder pass karte jao agar ant mein remainder 0 ae to matlab ye sbset sahi hai otherwise return INT_MIN
class Solution {
private:
    
    // Ismein ham log cache ni kar paenge bahut bada sum bhi ho sakta
//     int help(int i,int sum,vector<int> &nums){
        
//         if(i==nums.size()) return sum%3==0 ? sum : 0;
        
        
//         int pick=help(i+1,(sum+nums[i])%3,nums);
//         int notPick=help(i+1,sum,nums);
        
//         return max(pick,notPick);
//     }
    
    // Remainders se khel lo
//     int help(int i,int remainder,vector<int> &nums,vector<vector<int>> &dp){
        
//         if(i==nums.size()) return remainder ? -1e9 : 0;
        
//         if(dp[i][remainder]!=-1) return dp[i][remainder];
//         int pick=nums[i]+help(i+1,(remainder+nums[i])%3,nums,dp);
//         int notPick=help(i+1,remainder,nums,dp);
        
//         return dp[i][remainder]=max(pick,notPick);
//     }
    
//     int tabulation(vector<int> &nums){
//         vector<vector<int>> dp(nums.size()+1,vector<int> (3,0));
        
//         // Base Case
//         dp[nums.size()][0]=0;
//         dp[nums.size()][1]=-1e9;
//         dp[nums.size()][2]=-1e9;
        
//         for(int i=nums.size()-1;i>=0;i--){
//             for(int remainder=0;remainder<=2;remainder++){
//                 int pick=nums[i]+dp[i+1][(remainder+nums[i])%3];
//                 int notPick=dp[i+1][remainder];

//                 dp[i][remainder]=max(pick,notPick);
//             }
//         }
        
//         return dp[0][0];
//     }
     int spaceOptimisation(vector<int> &nums){
        vector<int> prev(3,0),curr(3,0);
        
        // Base Case
        prev[0]=0;
        prev[1]=-1e9;
        prev[2]=-1e9;
        
        for(int i=nums.size()-1;i>=0;i--){
            for(int remainder=0;remainder<=2;remainder++){
                int pick=nums[i]+prev[(remainder+nums[i])%3];
                int notPick=prev[remainder];

                curr[remainder]=max(pick,notPick);
            }
            prev=curr;
        }
        
        return prev[0];
    }
public:
    int maxSumDivThree(vector<int>& nums) {
        
        // vector<vector<int>> dp(nums.size()+1,vector<int> (3,-1));
        // return help(0,0,nums,dp);
        
        // return tabulation(nums);
        return spaceOptimisation(nums);
    }
};