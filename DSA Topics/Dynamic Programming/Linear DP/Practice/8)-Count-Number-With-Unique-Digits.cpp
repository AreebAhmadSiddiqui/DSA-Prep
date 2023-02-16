class Solution {
public:
    
    // O(10) O(10)
    int countNumbersWithUniqueDigits(int n) {
        vector<int> dp(11,0);
        
        if(n==0) return 1;
        
        dp[1]=10;
        dp[2]=81;
        
        for(int i=3;i<=10;i++){
            dp[i]=dp[i-1]*(10-i+1);
        }
        
        int ans=0;
        for(int i=1;i<=n;i++){
            ans+=dp[i];
        }
        
        return ans;
        
        
        // Explanation
        
        n is no of digits
            
        n                ans
        0                 1
        1                 10
        2                 pehli digit ko lena ke 9 tarike aur doosri ko lene ke liye same agar ni karna to 9 tarike 9*9
        3                 (f(2))*8 (Pehli 2 apas mein le le fir same ni hona hai to 10-2 kar do kyunki itn ehi options bache)
        -
        10                f(9)*1
        11                0 (because 10 ke baad ek na ek digit to repeat karegi hi)
        
        for n>10          return 0;
        
        f(n)=f(n-1)*(10-n+1)  for all n>=3
    }
};