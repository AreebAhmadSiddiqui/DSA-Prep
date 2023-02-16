STEPS

a) Yahan ham kadanes algorithm laga rahe hai 
b) two cases aenge

i) [someArrayElements maxSumSubarray someArrayElements] // Our sum might be in the middle
ii) [someArrayElements  maxSumSubarray][maxSumSubarray someArrayElements] // our maxSum is circular the first one is very easy just find the maxSum using kadanes algo
// But for the second part u need to apply a trick 

ii) can be show as

[maxSubArrayPart minSum maxSubArrayPart] // it is something like this 
example

[1,2,3,-1,-2,3] so we need to find only the minimum of the array and if we subtract minSum from totalSum we would get the circular subarray sum

But there is an edge case what if all the elemnents are negative so our returned answer would be 0

There check if maxSum <0 or what if so then return maxSum simply because that would be the invidual max element and eventualy the max subarray
or otherwise return max(maxSum,totalSum-minSum);

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum=0;
        int minSum=0;
        int maxi=nums[0];
        int n=nums.size();
        int mini=nums[0];
        int totalSum=0;
        for(int i=0;i<n;i++){
            maxSum+=nums[i];
            minSum+=nums[i];
            totalSum+=nums[i];
            maxi=max(maxi,maxSum);
            mini=min(mini,minSum);
            
            if(maxSum<0) maxSum=0;
            if(minSum>=0) minSum=0;
        }
        
         return maxi > 0 ? max(maxi, totalSum - mini) : maxi;
    }
};