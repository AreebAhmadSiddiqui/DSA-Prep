Maximum Erasure Value

You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.

Return the maximum score you can get by erasing exactly one subarray.

An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).

 
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        // Get maximum sum with distinct characters
        // Maximum subarray without repeating characters
        
        unordered_map<int,int> mp;
        
        int i=0;
        int j=0;
        int ans=0;
        int sum=0;
        while(j<nums.size()){
            
            // Do stuff
            mp[nums[j]]++;
            sum+=nums[j];
            
            if(mp[nums[j]]==1){ // no repeat distice possible answer
                ans=max(ans,sum);    
            }else{ // repeated
                
                // Shrink the window
                while(mp[nums[j]]!=1){ // Because this guy was repeated so deleted untill it is not repeating
                    
                    mp[nums[i]]--;
                    sum-=nums[i];
                    i++;
                }
            }
            j++;
        }
        
        return ans;
    }
};