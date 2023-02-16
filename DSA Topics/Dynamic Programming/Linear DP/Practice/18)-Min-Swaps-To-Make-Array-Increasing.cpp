Har index pe do choice hai agar wo pichle wale se bada hai to no swap
Lekin agar wo diagonally bhi bada hai to swap kar ke dekho 
aur haan swapped variable bhi rakhna padega

Minimum Swaps To Make Sequences Increasing

You are given two integer arrays of the same length nums1 and nums2. In one operation, you are allowed to swap nums1[i] with nums2[i].

For example, if nums1 = [1,2,3,8], and nums2 = [5,6,7,4], you can swap the element at i = 3 to obtain nums1 = [1,2,3,4] and nums2 = [5,6,7,8].
Return the minimum number of needed operations to make nums1 and nums2 strictly increasing. The test cases are generated so that the given input always makes it possible.

An array arr is strictly increasing if and only if arr[0] < arr[1] < arr[2] < ... < arr[arr.length - 1].
    
class Solution {
private:
//     int help(int i,int swapped,vector<int> &nums1,vector<int> &nums2,vector<vector<int>> &dp){
              
//         int prev1 = i==0 ? -1 : nums1[i-1];
//         int prev2 = i==0 ? -1 : nums2[i-1];
//         if(swapped) swap(prev1,prev2); // agar pichli wala swapped kah raha hai to swap kar do inhe fir age solve karo
        
        
//         if(i==nums1.size()-1) return !(nums1[i]>prev1 && nums2[i]>prev2);
        
//         if(dp[i][swapped]!=-1) return dp[i][swapped];
        
//         int swapp=1e9,notSwap=1e9;
        
//         if(nums1[i]>prev1 && nums2[i]>prev2){
            
//             // No Swap
//             notSwap=0+help(i+1,0,nums1,nums2,dp);
//         }
        
//         if(nums1[i]>prev2 && nums2[i]>prev1){  // swap karke dekho kahin age kam answer a jae to
            
//             // Swap
//             swapp=1+help(i+1,1,nums1,nums2,dp);
//         }
        
//         return dp[i][swapped]=min(swapp,notSwap);
//     }
//     int tabulation(vector<int>& nums1, vector<int>& nums2) {
//         vector<vector<int>> dp(nums1.size(),vector<int> (2,0));
        
//         int n=nums1.size();
        
//         // Base Case
//         dp[n-1][0]=!(nums1[n-1]>nums1[n-1-1] && nums2[n-1]>nums2[n-1-1]);
//         dp[n-1][1]=!(nums1[n-1]>nums2[n-1-1] && nums2[n-1]>nums1[n-1-1]);
        
//         for(int i=n-2;i>=0;i--){
//             for(int swapped=0;swapped<=1;swapped++){
//                 int prev1 = i==0 ? -1 : nums1[i-1];
//                 int prev2 = i==0 ? -1 : nums2[i-1];
//                 if(swapped) swap(prev1,prev2);
                
//                 int swapp=1e9,notSwap=1e9;
  
//                 if(nums1[i]>prev1 && nums2[i]>prev2){

//                     // No Swap
//                     notSwap=0+dp[i+1][0];
//                 }

//                 if(nums1[i]>prev2 && nums2[i]>prev1){ 

//                     // Swap
//                     swapp=1+dp[i+1][1];
//                 }

//                 dp[i][swapped]=min(swapp,notSwap);
//             }
//         }
        
//         return dp[0][0];
//     }
      int spaceOptimisation(vector<int>& nums1, vector<int>& nums2) {
        vector<int> prev(2,0),curr(2,0);
        
        int n=nums1.size();
        
        // Base Case
        prev[0]=!(nums1[n-1]>nums1[n-1-1] && nums2[n-1]>nums2[n-1-1]);
        prev[1]=!(nums1[n-1]>nums2[n-1-1] && nums2[n-1]>nums1[n-1-1]);
        
        for(int i=n-2;i>=0;i--){
            for(int swapped=0;swapped<=1;swapped++){
                int prev1 = i==0 ? -1 : nums1[i-1];
                int prev2 = i==0 ? -1 : nums2[i-1];
                if(swapped) swap(prev1,prev2);
                
                int swapp=1e9,notSwap=1e9;
  
                if(nums1[i]>prev1 && nums2[i]>prev2){

                    // No Swap
                    notSwap=0+prev[0];
                }

                if(nums1[i]>prev2 && nums2[i]>prev1){ 

                    // Swap
                    swapp=1+prev[1];
                }

                curr[swapped]=min(swapp,notSwap);
            }
            prev=curr;
        }
        
        return prev[0];
    }
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        // vector<vector<int>> dp(nums1.size(),vector<int> (2,-1));
        // return help(0,0,nums1,nums2,dp);
        
        // return tabulation(nums1,nums2);
        return spaceOptimisation(nums1,nums2);
    }
};