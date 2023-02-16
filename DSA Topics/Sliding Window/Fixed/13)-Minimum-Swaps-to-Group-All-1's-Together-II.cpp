class Solution {
public:
    int minSwaps(vector<int>& nums) {
        
//         Observations
            
//         a) You need to group 1's together basically you need to form a subarray of 1's
//         b) What could be the max size for this subarray? (cnt of ones)
//         c) Now you have the liberty to swap 0 with 1 so when doing this is the best? when you have least amount of zero in your subarray or max amt of ones in your subarray
//         d) Do a fixed sliding window of window size (cnt of ones) and minimize the num of zeroes in it;
        
        
        int cntOnes;
        for(auto &num:nums) cntOnes+=num==1;
        
        int k=cntOnes;
        int i=0;
        int j=0;
        int n=nums.size();
        int ans=n; // int max also you can initialise this is the max so maine aisa kar diya halaki itna bhi ni aega
        int cntZeroes=0;
        while(j<2*n){
            
            // Do stuff
            if(nums[j%n]==0) cntZeroes++;
            
            if(j-i+1==k){
                // Calculate
                ans=min(ans,cntZeroes);
                
                // Shrink the window
                if(nums[i%n]==0) cntZeroes--;
                i++;
            }
            j++;
        }
        return ans==n ? 0 : ans; // if ans==n means no ones are there
    }
};