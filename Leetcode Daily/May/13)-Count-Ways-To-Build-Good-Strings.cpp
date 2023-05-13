2466. Count Ways To Build Good Strings

Given the integers zero, one, low, and high, we can construct a string by starting with an empty string, and then at each step perform either of the following:

Append the character '0' zero times.
Append the character '1' one times.
This can be performed any number of times.

A good string is a string constructed by the above process having a length between low and high (inclusive).

Return the number of different good strings that can be constructed satisfying these properties. Since the answer can be large, return it modulo 109 + 7.

Approach

a) Mujhe pehle samjh ni a raha tha ki stop kaise karun fir meine pen paper pe kiya
b) Dekho agar low aur high ke andar hai to ek way to ho hi gaya agar haan to one add kardo aur age chale jao (ya to one ko add karke ya to zero ko add karke) aur agar low < kam hai to to 0+ age chale jao (ya to one ko add karke ya to zero ko add karke)
c) Aur agar high se bhi age chala jae to return 0 kar do bas yahi karna

d) Dekho tum len> high wala check kar hi rahe ho to x>=low and x<=high check karni ki zerurat ni sirf x>=low se bhi kaam chal jaega

class Solution {
    int mod=1000000007;
private:
    
    // O(high) O(high+high)
    
//     int help(int len,int low,int high,int zero,int one,vector<int> &dp){
//         if(len>high) return 0;
        
//         if(dp[len]!=-1) return dp[len];
        
//         int cntZero=len+zero>=low && len+zero<=high ? 1 : 0;
//         int cntOne=len+one>=low && len+one<=high ? 1 : 0;
        
//         cntZero+=help(len+zero,low,high,zero,one,dp)%mod;
//         cntOne+=help(len+one,low,high,zero,one,dp)%mod;
        
//         return dp[len]=(cntZero+cntOne)%mod;
//     }
    
    // O(high) O(high)
    int tabulation(int low,int high,int zero,int one){
        vector<int> dp(high+1,0);
        
        // Base Case Done
        
        for(int len=high;len>=0;len--){
            
            int cntZero=len+zero>=low && len+zero<=high ? 1 : 0;
            int cntOne=len+one>=low && len+one<=high ? 1 : 0;

            cntZero+=len+zero>high ? 0 : dp[len+zero]%mod;
            cntOne+=len+one>high ? 0 :dp[len+one]%mod;

            dp[len]=(cntZero+cntOne)%mod;
        }
        
        return dp[0];
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        
        // vector<int> dp(high+1,-1);
        // return help(0,low,high,zero,one,dp);
        return tabulation(low,high,zero,one);
    }
};