Steps

a) Yahan ham kya kare rahe hain dekho ham pehle prev ko le rahe aur fir apne ko multiply kar rahe taki age wale ke liye main prev ka kaam karun
b) Two pass mein same cheez karo dono tarf se
c) One pass mein yahi kaam ek mein hi kar do to aur acha

 Example

        After 4 iterations yahi kaam peeche se karo suffix array
        
        1   2      3        4
    ans 1   1      2        6
    1  1*1  1*1*2  1*1*2*3  1*1*2*3*4
                            prev

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        // Two Pass
        
//         // Create the left and right multiplication
        
//         vector<int> ans(nums.size(),0);
//         int temp=1;
//         for(int i=0;i<nums.size();i++){
//             ans[i]=temp;
//             temp*=nums[i];
//         }
        
//         //for right
//         temp=1;
//         for(int i=nums.size()-1;i>=0;i--){
//             ans[i]*=temp;
//             temp*=nums[i];
//         }
        
//         return ans;
        
        
        // One Pass
        
        vector<int> ans(nums.size(),1);
        int prefix=1,suffix=1;
        for(int i=0;i<nums.size();i++){
            ans[i]*=prefix;
            prefix*=nums[i];
            ans[nums.size()-i-1]*=suffix;
            suffix*=nums[nums.size()-i-1];
        }
        
        return ans;
    }
};