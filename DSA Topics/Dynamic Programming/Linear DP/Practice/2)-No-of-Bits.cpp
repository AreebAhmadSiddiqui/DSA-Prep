// O(nlogn)

// class Solution {
// private:
//     int getCntOnes(int n){
//         int cnt=0;
//         while(n!=0){
//             cnt+=n&1;
//             n>>=1;
//         }
//         return cnt;
//     }
// public:
//     vector<int> countBits(int n) {
        
//         int start=0;
        
//         vector<int> ans;
//         while(start<=n){
            
//             int cntOnes=getCntOnes(start);
//             ans.push_back(cntOnes);
//             start++;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    
    // Observation for any even number is the same as its n/2 th guy and for odd n/2th guy + 1
    vector<int> countBits(int n) {
    
        vector<int> ans;
        int same=1;
        
        ans.push_back(0);
        int start=1;    
        while(start<=n){
            if(start%2==0){
                ans.push_back(ans[start/2]);
            }else{
                ans.push_back(ans[start/2]+1);
            }
            start++;
        }
        
        return ans;
    }
};