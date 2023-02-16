class Solution {
private:
    int mod=1000000007;
//     int help(int i,bool prevGap,int n,vector<vector<int>> &dp){
//         if(i==n) return prevGap==false;
//         if(i>n) return 0;
        
//         if(dp[i][prevGap]!=-1) return dp[i][prevGap];
//         int first=0,second=0;
//         // When I have left no gap at previous index I have 4 choices
//         if(!prevGap){
//             first=(help(i+1,prevGap,n,dp)%mod+help(i+2,prevGap,n,dp)%mod+2*1ll*help(i+2,true,n,dp)%mod)%mod;
//         }
//         // When I have left a gap at previous index I have 2 choices to fill it
//         else{
//             second=(help(i+1,false,n,dp)%mod+help(i+1,true,n,dp)%mod)%mod;
//         }
        
//         // By filling and all we mean just the current index we are standing on 
        
//         // second wale casse mein maine *2 kiya tha dono ko lekin khud hi socha agar main peeche jahag chode ke aya hun to is col pe agar mujhe bharna hai to 2 hi to choice hai ya to main us L ko doosre L se bhar dun ya fir ek gap aur chod do
//         return dp[i][prevGap]=(first%mod+second%mod)%mod;
//     }
//     int tabulation(int n){
//         vector<vector<int>> dp(n+2,vector<int> (2,0));
        
//         // Base Case
//         dp[n][0]=1;
//         dp[n][1]=0;
        
//         for(int i=n-1;i>=0;i--){
//             for(int prevGap=0;prevGap<=1;prevGap++){
//                 int first=0,second=0;

//                 if(!prevGap){
//                     first=(dp[i+1][prevGap]%mod+dp[i+2][prevGap]%mod+2*1ll*dp[i+2][true]%mod)%mod;
//                 }
//                 else{
//                     second=(dp[i+1][false]%mod+dp[i+1][true]%mod)%mod;
//                 }
//                 dp[i][prevGap]=(first%mod+second%mod)%mod;
//             }
//         }
//         return dp[0][0];
//     }
    int tabulation(int n){
        vector<vector<int>> dp(n+2,vector<int> (2,0));
        
        // Base Case
        dp[n][0]=1;
        dp[n][1]=0;
        
        for(int i=n-1;i>=0;i--){
            // prevGap=0
            dp[i][0]=(dp[i+1][0]%mod+dp[i+2][0]%mod+2*1ll*dp[i+2][1]%mod)%mod;
            
            // prevGap=1
            dp[i][1]=(dp[i+1][0]%mod+dp[i+1][1]%mod)%mod;
        }
        return dp[0][0];
    }
     int spaceOptimisation(int n){
        vector<int> curr(2,0),next1(2,0),next2(2,0);
        
        // Base Case
        next1[0]=1;
        next1[1]=0;
        
        for(int i=n-1;i>=0;i--){
            // prevGap=0
            curr[0]=(next1[0]%mod+next2[0]%mod+2*1ll*next2[1]%mod)%mod;
            
            // prevGap=1
            curr[1]=(next1[0]%mod+next1[1]%mod)%mod;
            
            next2=next1;
            next1=curr;
        }
        return next1[0];
    }
public:
    int numTilings(int n) {
//         vector<vector<int>> dp(n+1,vector<int> (2,-1));
        
//         return help(0,false,n,dp); // {currCol, prevGap,n}
        // return tabulation(n);
        return spaceOptimisation(n);
    }
};

https://leetcode.com/problems/domino-and-tromino-tiling/discuss/1620975/C%2B%2BPython-Simple-Solution-w-Images-and-Explanation-or-Optimization-from-Brute-Force-to-DP

Fo visual explanantion