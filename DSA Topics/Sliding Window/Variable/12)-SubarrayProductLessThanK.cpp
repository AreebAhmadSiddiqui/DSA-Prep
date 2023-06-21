// I think the trickiest part is why the number of newly introduced subarrays is j - i + 1.
// Say now we have {1,2,3} and add {4} into it. Apparently, the new subarray introduced here are:
// {1,2,3,4}, {2,3,4}, {3,4}, {4}, which is the number of elements in the new list.
// If we also remove some at the left, say we we remove 1, then subarrays are:
// {2,3,4}, {3,4}, {4}. It is easy to get the result is j - i + 1.

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        // if(k==0) return k;
        
        int pro=1;
        int cnt=0;
        int j=0;
        int i=0;
        while(j<nums.size()){
            
            // DO stuff
            pro*=nums[j];
            // if(pro<k)//  waliline bhi likh sakte lekin ganda laga rah  tha to ek baar kar diya
            while(i<=j && pro>=k){
                pro/=nums[i];
                i++;
            }
            
            cnt+=j-i+1; // jab bhi bhi koi banda add karte ho to utne length ke sub array ban jate hai proof upar hai
            
            j++;
        }
        return cnt;
    }
};