// If a subarray is divisible by K, it has to be a multiple of K

// a-b=n*k, a = running total, b = any previous subarray sum, same as original prefix sum problems.

// We want to solve for b, so using basic algebra, b=a-n*k

// We don't know what n is, so we can get rid of n by modding every element by k
// (b%k) = (a%k) - (n*k)%k

// since n*k is a multiple of k and k goes into it evenly, the result of the (n *k)%k will be 0

// therefore
// b%k = a%k

// is the same as the formula we defined earlier, a-b=n*k

// where b = running total, a = any previous subarray sum

// So we just have to see if running total mod k is equal to any previous running total mod k

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        // ~O(n*1) Worst Case O(n*n) O(k)
//         unordered_map<int,int> mp; // we are gonna store the remainders
        
//         int prefixSum=0;
//         int cnt=0;
//         for(int i=0;i<nums.size();i++){
            
//             prefixSum+=nums[i];
            
//             int remainder=prefixSum%k;
            
//             if(remainder<0) remainder+=k;
            
//             if(remainder==0) cnt++;
            
//             if(mp.find(remainder)!=mp.end()){
//                 cnt+=mp[remainder];
//             }
            
//             mp[remainder]++;
//         }
        
//         return cnt;
        
        
        // O(n) O(k)
        // Since we are storing modulos we can only store till k so no need of a map
        vector<int> rem(k,0);
        
        int prefixSum=0;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            
            prefixSum+=nums[i];
            
            int remainder=prefixSum%k;
            
            if(remainder<0) remainder+=k; // for handling negatives
            
            if(remainder==0) cnt++;
            
            cnt+=rem[remainder];
            
            rem[remainder]++;
        }
        
        return cnt;
    }
};