Number of Ways to Earn Points

There is a test that has n types of questions. You are given an integer target and a 0-indexed 2D integer array types where types[i] = [counti, marksi] indicates that there are counti questions of the ith type, and each one of them is worth marksi points.

Return the number of ways you can earn exactly target points in the exam. Since the answer may be too large, return it modulo 109 + 7.

Note that questions of the same type are indistinguishable.

For example, if there are 3 questions of the same type, then solving the 1st and 2nd questions is the same as solving the 1st and 3rd questions, or the 2nd and 3rd questions.
 
// Simple Straightforward DP Hai
// Tum curr index mein utne hi questions solve kar sakte ho jab tak tumhare points target se kam ho
class Solution {
private:
    // int mod=1000000007;
//     int help(int i,int target,int n,vector<vector<int>>& types,vector<vector<int>> &dp){
        
//         if(i==n){
//             return target==0;
//         }
        
//         if(dp[i][target]!=-1) return dp[i][target];
//         int ans=0;
        
//         // Picking this index
//         int cnt=types[i][0];
//         int point=types[i][1];
        
//         // We can use this current idx cnt no of times
        
//         // Zero ka matlab main ise na pick karun
//         for(int j=0;j<=cnt;j++){
            
//             // I can choose
//             if(target-point*j>=0){
//                 ans=(ans%mod+help(i+1,target-point*j,n,types,dp)%mod)%mod;
//             }
//         }
//         return dp[i][target]=ans;
//     }
    int mod=1000000007;
    int tabulation(int tar, vector<vector<int>>& types){
//         int n=types.size();
//         vector<vector<int>> dp(n+1,vector<int> (tar+1,0));
        
//         // Base Case
//         dp[n][0]=1;
        
        
//         for(int i=n-1;i>=0;i--){
//             for(int target=0;target<=tar;target++){
//                 int ans=0;
        
//                 // Picking this index
//                 int cnt=types[i][0];
//                 int point=types[i][1];

//                 // We can use this current idx cnt no of times

//                 // Zero ka matlab main ise na pick karun
//                 for(int j=0;j<=cnt;j++){

//                     // I can choose
//                     if(target-point*j>=0){
//                         ans=(ans%mod+dp[i+1][target-point*j]%mod)%mod;
//                     }
//                 }
//                 dp[i][target]=ans;
//             }
//         }
//         return dp[0][tar];
        
        
//         int n=types.size();
//         vector<int> prev(tar+1,0),curr(tar+1,0);
        
//         // Base Case
//         prev[0]=1;
        
        
//         for(int i=n-1;i>=0;i--){
//             for(int target=0;target<=tar;target++){
//                 int ans=0;
        
//                 // Picking this index
//                 int cnt=types[i][0];
//                 int point=types[i][1];

//                 // We can use this current idx cnt no of times

//                 // Zero ka matlab main ise na pick karun
//                 for(int j=0;j<=cnt;j++){

//                     // I can choose
//                     if(target-point*j>=0){
//                         ans=(ans%mod+prev[target-point*j]%mod)%mod;
//                     }
//                 }
//                 curr[target]=ans;
//             }
//             prev=curr;
//         }
//         return prev[tar];
        
        int n=types.size();
        vector<int> prev(tar+1,0);
        
        // Base Case
        prev[0]=1;
        
        
        for(int i=n-1;i>=0;i--){
            for(int target=tar;target>=0;target--){
                int ans=0;
        
                // Picking this index
                int cnt=types[i][0];
                int point=types[i][1];

                // We can use this current idx cnt no of times

                // Zero ka matlab main ise na pick karun
                for(int j=0;j<=cnt;j++){

                    // I can choose
                    if(target-point*j>=0){
                        ans=(ans%mod+prev[target-point*j]%mod)%mod;
                    }
                }
                prev[target]=ans;
            }
        }
        return prev[tar];
    }
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        // int n=types.size();
        // vector<vector<int>> dp(n,vector<int> (target+1,-1));
        // return help(0,target,n,types,dp);
        
        return tabulation(target,types);
    }
};