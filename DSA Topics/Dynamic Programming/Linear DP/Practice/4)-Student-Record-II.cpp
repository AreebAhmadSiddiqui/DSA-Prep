// An attendance record for a student can be represented as a string where each character signifies whether the student was absent, late, or present on that day. The record only contains the following three characters:

// 'A': Absent.
// 'L': Late.
// 'P': Present.
// Any student is eligible for an attendance award if they meet both of the following criteria:

// The student was absent ('A') for strictly fewer than 2 days total.
// The student was never late ('L') for 3 or more consecutive days.
// Given an integer n, return the number of possible attendance records of length n that make a student eligible for an attendance award. The answer may be very large, so return it modulo 109 + 7.

class Solution {
     int mod=1000000007;
private:
    int help(int day,int a,int l,vector<vector<vector<int>>> &dp){
        if(a==2 || l==3) return 0;
        
        if(day==0){
            return 1;
        }
        
        if(dp[day][a][l]!=-1) return dp[day][a][l];
        int absent=help(day-1,a+1,0,dp); // zero kyun kar raho explicitly ( are bhai itna dimaag kharab hua tha aisa na karke ki kya bataun)
        // Dekh bhai question to dhang se padhoge ni to yahi hoga na bagal mein dekh likha hai 3 or more consecutive days to agar main aj absent ho gaya ya present to age ke liye l 0 ho jaega na noobde gadha
        int late=help(day-1,a,l+1,dp);
        int present=help(day-1,a,0,dp);
        
        return dp[day][a][l]=((absent%mod+present%mod)%mod+late%mod)%mod;
    }
//     int tabulation(int n){
        
//         vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (3,vector<int> (4,0)));
        
//         // Base Case 
        
//         for(int a=0;a<2;a++){
//             for(int l=0;l<3;l++){
//                 dp[0][a][l]=1;
//             }
//         }
        
//         for(int day=1;day<=n;day++){
//             for(int a=1;a>=0;a--){
//                 for(int l=2;l>=0;l--){
//                     int absent=dp[day-1][a+1][0];
//                     int late=dp[day-1][a][l+1];
//                     int present=dp[day-1][a][0];

//                     dp[day][a][l]=((absent%mod+present%mod)%mod+late%mod)%mod;
//                 }
//             }
//         }
        
//         return dp[n][0][0];
//     }
    
     int spaceOptimisation(int n){
        
        vector<vector<int>> prev(3,vector<int> (4,0)),curr(3,vector<int> (4,0));
        
        // Base Case 
        
        for(int a=0;a<2;a++){
            for(int l=0;l<3;l++){
                prev[a][l]=1;
            }
        }
        
        for(int day=1;day<=n;day++){
            for(int a=1;a>=0;a--){
                for(int l=2;l>=0;l--){
                    int absent=prev[a+1][0];
                    int late=prev[a][l+1];
                    int present=prev[a][0];

                    curr[a][l]=((absent%mod+present%mod)%mod+late%mod)%mod;
                }
            }
            prev=curr;
        }
        
        return prev[0][0];
    }
public:
    int checkRecord(int n) {
        
        // vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (3,vector<int> (4,-1)));
        // return help(n,0,0,dp);
        
        // return tabulation(n);
        return spaceOptimisation(n);
    }
};