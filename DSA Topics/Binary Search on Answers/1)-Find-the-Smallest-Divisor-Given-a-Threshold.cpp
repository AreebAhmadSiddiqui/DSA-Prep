class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start=1; // min value
        // int end=1e9+1;
        
        // or you can take max of the array
        
//         because that max would be the greatest of the range but uske baad bhi answer aega lekin hame to minimum poocha hai na isliye
            
//         see 
            
//         1 2 3 4 agr sabko divide by 4 karoe aur sum loge to aega 4
//         1 2 3 4 agr sabko divide by 5 karoe aur sum loge tab bhi aega 4
//         1 2 3 4 agr sabko divide by 6 karoe aur sum loge tab bhi aega 4 isliye hamne minimum le liya
        for(int i=0;i<nums.size();i++){
            end=max(end,nums[i]);
        }
        
        // O(nlogm) m is max of the array
        int ans=1;
        while(start<=end){
            int mid=start+(end-start)/2;
            
            int sum=0;
            for(auto &it:nums){
                sum+=(it+mid-1)/mid; // ceil nikalna hai isliye ye formula
            }
            
            // check if there exist any smaller divisor
            if(sum<=threshold){
                ans=mid;
                end=mid-1;
            }
            else {
                start=mid+1;
            }
        }
        
        return ans;
    }
};