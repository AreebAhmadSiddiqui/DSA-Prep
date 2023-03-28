class Solution {
private:
//     int help(int i,int canTravelDays,vector<int> &days,vector<int> &costs,vector<int> &passesAvailable,vector<vector<int>> &dp){
//         int n=days.size();
//         if(i==n) return 0;
        
//         if(dp[i][canTravelDays]!=-1) return dp[i][canTravelDays];
        
//         int pick=1e9,notPick=1e9;
        
//         // For picking
//         for(int j=0;j<3;j++){
//             pick=min(pick,costs[j]+help(i+1,days[i]+passesAvailable[j]-1,days,costs,passesAvailable,dp));
//         }
//         if(canTravelDays>=days[i]){
//             notPick=0+help(i+1,canTravelDays,days,costs,passesAvailable,dp);
//         }
//         return dp[i][canTravelDays]=min(pick,notPick);
//     }
//     int tabulation(vector<int> &days,vector<int> &costs){
        
//         vector<int> passesAvailable={1,7,30};
//         int n=days.size();

        At max 365+30 hoga to maine 400 le liya for safety

        Kyunki main day ko man raha ki is din tak mein travel kar sakte to baar baar ad karne ki zarurat ni
        
//         vector<vector<int>> dp(n+1,vector<int> (400,0));
        
//         // Base Case Done
        
//         for(int i=n-1;i>=0;i--){
//             for(int canTravelDays=0;canTravelDays<400;canTravelDays++){
//                 int pick=1e9,notPick=1e9;
        
//                 // For picking
//                 for(int j=0;j<3;j++){
//                     pick=min(pick,costs[j]+dp[i+1][days[i]+passesAvailable[j]-1]);
//                 }
//                 if(canTravelDays>=days[i]){
//                     notPick=0+dp[i+1][canTravelDays];
//                 }
//                 dp[i][canTravelDays]=min(pick,notPick);
//             }
//         }
//         return dp[0][0];
//     }
    int spaceOptimisation(vector<int> &days,vector<int> &costs){
        
        vector<int> passesAvailable={1,7,30};
        int n=days.size();
        vector<int> prev(400,0),curr(400,0);
        
        // Base Case Done
        
        for(int i=n-1;i>=0;i--){
            for(int canTravelDays=0;canTravelDays<400;canTravelDays++){
                int pick=1e9,notPick=1e9;
        
                // For picking
                for(int j=0;j<3;j++){
                    pick=min(pick,costs[j]+prev[days[i]+passesAvailable[j]-1]);
                }
                if(canTravelDays>=days[i]){
                    notPick=0+prev[canTravelDays];
                }
                curr[canTravelDays]=min(pick,notPick);
            }
            prev=curr;
        }
        return prev[0];
    }


    // Ye wala optimised hai ise dekhna
    int help(int i,vector<int> &days,vector<int> &costs,vector<int> &dp){
        int n=days.size();
        
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        
        int dayOneOp=1e9,daySevenOp=1e9,dayThirtyOp=1e9;
        
        int j;
        // Ill choose day 1 pass on this ith day how long can i go
        for(j=i;j<n && days[i]+1-1>=days[j];j++){
            dayOneOp=costs[0]+help(j+1,days,costs,dp);
        }
        
        // Ill choose day 7 pass on this ith day how long can i go
        for(j=i;j<n && days[i]+7-1>=days[j];j++){
            daySevenOp=costs[1]+help(j+1,days,costs,dp);
        }
        // Ill choose day 30 pass on this ith day how long can i go
        for(j=i;j<n && days[i]+30-1>=days[j];j++){
            dayThirtyOp=costs[2]+help(j+1,days,costs,dp);
        }
        
        
        return dp[i]=min(dayOneOp,min(daySevenOp,dayThirtyOp));
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> passesAvailable={1,7,30};
        int n=days.size();
        vector<int> dp(n,-1);
        // return help(0,0,days,costs,passesAvailable,dp);
        
        // return tabulation(days,costs);
        // return spaceOptimisation(days,costs);
        
        return help(0,days,costs,dp);
    }
};