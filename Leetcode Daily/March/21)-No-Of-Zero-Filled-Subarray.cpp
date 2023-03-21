class Solution {
public:

// First approach mein

a) Subarray ki length pata laga lo aur no of subarrays in a given length is given by n*(n+1)/2;]
b) bas wahi kara

//     long long zeroFilledSubarray(vector<int>& nums) {
//         long long ans=0;
        
//         int n=nums.size();
//         int i=0;

        //    O(n)
//         while(i<n){
            
//             if(nums[i]==0){
//                 int j=i;
//                 while(j<n && nums[j]==0) j++;
//                 int len=j-i;
//                 ans+=(len*1ll*(len+1))/2;
//                 i=j;
//             }else{
//                 i++;
//             }
//         }
//         return ans;
//     }
    
    
    // Correct hai upar wala bhi lekin ye wala aur simple hai
    
    // n*(n+1)/2 ka matlab kya hai 1+2+3+4+... n matlab jitne zero ate jae unhe add karte raho simply
    
    Ye wala simple hai
    
        long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0;
        
        int n=nums.size();
        
        // O(n)
        int cntZero=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0) cntZero++;
            else cntZero=0;
            
            // Har iteration pe add karo
            ans+=cntZero;
        }
        return ans;
    }
};