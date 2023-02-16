Longest Subarray of 1's After Deleting One Element

Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        // Find the max subarray having 1 zero
        
        int cntZero=0;
        int i=0;
        int j=0;
        int ans=0;
        while(j<nums.size()){
            
            // Do stuff
            if(nums[j]==0) cntZero++;
            
            if(cntZero<=1){
                ans=max(ans,j-i);
            }
            if(cntZero>1){
                
                // We need to shrink our window
                while(cntZero>1){
                    cntZero-=nums[i]==0;
                    i++;
                }
            }
            j++;
        }
        return ans;
    }
};