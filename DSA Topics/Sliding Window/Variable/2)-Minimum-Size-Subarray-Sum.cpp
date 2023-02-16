class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n=nums.size();
        int i=0;
        int j=0;
        int sum=0;
        
        int ans=INT_MAX;
        while(j<n){
            
            // Do stuff
            sum+=nums[j];
            
            while(sum>=target){
                // calculations
                ans=min(ans,j-i+1);
                
                //shift window
                sum-=nums[i];
                i++;
            }
            j++;
        }
        
        return ans==INT_MAX ? 0 : ans;
    }
};