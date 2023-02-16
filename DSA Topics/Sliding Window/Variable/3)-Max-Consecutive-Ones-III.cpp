Max Consecutive Ones III

Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

 
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int flipZeroes=0;
        int j=0;
        int i=0;
        int n=nums.size();
        int ans=0;
        while(j<n){
            
            // Do stuff
            if(nums[j]==0){
                flipZeroes++;
            }
            if(flipZeroes<=k){
                ans=max(ans,j-i+1);
            }
            else if(flipZeroes>k){
                 
                while(flipZeroes>k){
                    
                    flipZeroes-=nums[i]==0;
                    i++;
                }
            }
            j++;
        }
        return ans;
    }
};