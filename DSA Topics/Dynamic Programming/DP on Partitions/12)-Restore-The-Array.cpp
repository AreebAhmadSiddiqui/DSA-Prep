1416. Restore The Array

A program was supposed to print an array of integers. The program forgot to print whitespaces and the array is printed as a string of digits s and all we know is that all integers in the array were in the range [1, k] and there are no leading zeros in the array.

Given the string s and the integer k, return the number of the possible arrays that can be printed as s using the mentioned program. Since the answer may be very large, return it modulo 109 + 7.
    
Approach

a) Basic partition karo jab bhi i pe 0 ho iska matlab ye partition galat hai
b) Baaki sahi wale agar j==n pahunch gae to return 1 kar do
c) Rahi baad TC ki jo O(n2) lag rahi asal mein utni ni hai O(n*10) hai kyun wo 10 digit se bada number lega hi ni kyunki k at max 10^9 hai to break ho jaega
d) baaki to Normal hai Decode Ways jaisa


class Solution {
private:
    bool isPossible(long long num,int k){
        return num>=1 && num<=k;
    }
    int mod=1000000007;
//     int help(int i,int n,string &s,int k,vector<int> &dp){
        
//         if(i==n) return 1;
        
//         //if i is starting from zero then it can not be possible so just return zero
//         if(s[i]=='0') return 0;
        
        
//         if(dp[i]!=-1) return dp[i];
        
//         int ans=0;
//         long long num=0;
//         for(int j=i;j<n;j++){
//             num=num*1ll*10+(s[j]-'0');
//             if(isPossible(num,k)){
//                 ans=(ans%mod+help(j+1,n,s,k,dp)%mod)%mod;
//             }else{
//                 break;
//             }
//         }
//         return dp[i]=ans;
//     }
    
    int tabulation(string s,int k){
        int n=s.size();
        vector<int> dp(n+1,0);
        
        dp[n]=1;
        for(int i=0;i<n;i++) dp[i]=!(s[i]=='0');
        
        for(int i=n-1;i>=0;i--){
            int ans=0;
            long long num=0;
            
            // Ye banda worst case mein bhi 10 se zyada baar ni chalega because at max k=10^9 hai to usse bada matlab 10 digit se zyada to wo hote hi break ho jaega isliye
            for(int j=i;j<n;j++){
                num=num*1ll*10+(s[j]-'0');
                if(isPossible(num,k)){
                    ans=(ans%mod+dp[j+1]%mod)%mod;
                }else{
                    // Because agar ye number k se bada hai to age wale bhi to bade honge isliye dont go
                    break;
                }
            }
            dp[i]=ans;
        }
        return dp[0];
    }
public:
    int numberOfArrays(string s, int k) {
        
        // int n=s.size();
        // vector<int> dp(n+1,-1);
        // return help(0,n,s,k,dp);
        return tabulation(s,k);
    }
};