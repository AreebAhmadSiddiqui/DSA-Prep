K Radius Subarray Averages

You are given a 0-indexed array nums of n integers, and an integer k.

The k-radius average for a subarray of nums centered at some index i with the radius k is the average of all elements in nums between the indices i - k and i + k (inclusive). If there are less than k elements before or after the index i, then the k-radius average is -1.

Build and return an array avgs of length n where avgs[i] is the k-radius average for the subarray centered at index i.

The average of x elements is the sum of the x elements divided by x, using integer division. The integer division truncates toward zero, which means losing its fractional part.

For example, the average of four elements 2, 3, 1, and 5 is (2 + 3 + 1 + 5) / 4 = 11 / 4 = 2.75, which truncates to 2.



class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
     
        // Window size would be 2*k+1
        // Aur har window size ke center pe average dal do
        int windowSize=2*k+1;
        int n=nums.size();
        vector<int> ans(n,-1); // initialise it with -1 so that we need not to deal with boundary conditions of window size in future
        int i=0;
        int j=0;
        long long sum=0;
        while(j<n){
            
            // Do stuff
            sum+=nums[j]; // overflow hua tha isliye ll le liya
            
            if(j-i+1==windowSize){ // window reached
                
                // Calculation
                
                int centreIndex=i+windowSize/2;
                
                ans[centreIndex]=sum/windowSize;
                
                // Shrink the window
                sum-=nums[i];
                i++;
            }
            j++;
        }
        return ans;
    }
};