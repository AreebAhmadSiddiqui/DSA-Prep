STEPS

// a) rob this house and check if valid then rob dp[i-2] house rob to karna hi hai aur kuch add ka poge ki ni wo dikkat thi bas usmein error a raha tha


                                                                        /\
                                                                       /  \
                                                                      /    \
                                                                     /      \
                                                                    /        \
                                                                   /          \




class Solution {
private:
    int help(int i,vector<int> &nums,vector<int> &dp){
        if(i<0) return 0;
        
        if(i==0) return nums[0];
        
        if(dp[i]!=-1) return dp[i];
        
        int robThisHouse=nums[i]+help(i-2,nums,dp);
        int notRobThisHouse=0+help(i-1,nums,dp);
        
        return dp[i]=max(robThisHouse,notRobThisHouse);
    }
public:
    // int rob(vector<int>& nums) {
    //     vector<int> dp(nums.size(),-1);
    //     return help(nums.size()-1,nums,dp);
    // }
    
//     int rob(vector<int>& nums) {
//         vector<int> dp(nums.size(),0);
        
//         // Base Case
        
//         dp[0]=nums[0];
        
//         for(int i=1;i<nums.size();i++){
            
//             int robThisHouse=nums[i];
//             if(i-2>=0) robThisHouse+=dp[i-2];
//             int notRobThisHouse=0+dp[i-1];

//             dp[i]=max(robThisHouse,notRobThisHouse);
//         }
        
//         return dp[nums.size()-1];
//     }
    
    int rob(vector<int>& nums) {
        
        // Base Case
        
        int prev=nums[0];
        int prev2,curr;
        
        for(int i=1;i<nums.size();i++){
            
            int robThisHouse=nums[i];
            if(i-2>=0) robThisHouse+=prev2;
            int notRobThisHouse=0+prev;

            curr=max(robThisHouse,notRobThisHouse);
            
            prev2=prev;
            prev=curr;
        }
        
        return prev;
    }
};