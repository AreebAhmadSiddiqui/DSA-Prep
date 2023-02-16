class Solution {
private:
    int help(int start,int end,vector<int> &nums){
        // Base Case
        
        int prev=nums[start];
        int prev2,curr;
        
        for(int i=start+1;i<=end;i++){
            
            int robThisHouse=nums[i];
            if(i-2>=start) robThisHouse+=prev2;
            int notRobThisHouse=0+prev;

            curr=max(robThisHouse,notRobThisHouse);
            
            prev2=prev;
            prev=curr;
        }
        
        return prev;
    }
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        
        if(nums.size()==1) return nums[0];
        
        // since they are circle so either you will choose the last one or not choose the last
        // either skip it or if chosen then dont pick 0th guy
        
        int skipTheLast=help(0,nums.size()-2,nums);
        
        int skipTheFirst=help(1,nums.size()-1,nums);
        
        return max(skipTheLast,skipTheFirst);
    }
};