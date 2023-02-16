You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.

Train tickets are sold in three different ways:

a 1-day pass is sold for costs[0] dollars,
a 7-day pass is sold for costs[1] dollars, and
a 30-day pass is sold for costs[2] dollars.
The passes allow that many days of consecutive travel.

For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
Return the minimum number of dollars you need to travel every day in the given list of days.

Mujhe mera wala samjh aya dhang se doosra wala ni aya ;()
class Solution {
private:
// //     int help(int i,vector<int> &days,vector<int> &costs,int maxDaysICanTravelWithoutPass,vector<vector<int>> &dp){
        
// //         int day[]={1,7,30};
// //         if(i==days.size()) return 0;
        
// //         if(dp[i][maxDaysICanTravelWithoutPass]!=-1) return dp[i][maxDaysICanTravelWithoutPass];
// //         int buyPass=1e9,notBuyPass=1e9;
        
// //         // What are the choices i have 
// //         for(int j=0;j<3;j++){
// //             buyPass=min(buyPass,costs[j]+help(i+1,days,costs,days[i]+day[j]-1,dp)); // agar maine pass kharida to main days[i]+day[j]-1 itne din bina pass ke ghoom sakta (ex 2 aur pass buy kiya 7 ka 2+7-1 8we din tak ghoom sakta hun)
// //         }
// //         if(maxDaysICanTravelWithoutPass>=days[i]) notBuyPass=0+help(i+1,days,costs,maxDaysICanTravelWithoutPass,dp); // It main na bhi khareedun to chal jaega
        
// //         return dp[i][maxDaysICanTravelWithoutPass]=min(buyPass,notBuyPass);
// //     }
    
// //     int tabulation(vector<int>& days, vector<int>& costs){
// //         int n=days.size();
// //         vector<vector<int>> dp(n+1,vector<int> (400,0)); // (Why 400 because at max i will have 365 days and if i buy 30 days pass 365+30-1=394 so took 400 for simplicity)
        
// //         // Base Case
// //         // Already done
        
// //         int day[]={1,7,30};
// //         for(int i=n-1;i>=0;i--){
// //             for(int maxDaysICanTravelWithoutPass=0;maxDaysICanTravelWithoutPass<=395;maxDaysICanTravelWithoutPass++){
// //                 int buyPass=1e9,notBuyPass=1e9;

// //                 for(int j=0;j<3;j++) buyPass=min(buyPass,costs[j]+dp[i+1][days[i]+day[j]-1]);
// //                 if(maxDaysICanTravelWithoutPass>=days[i]) notBuyPass=0+dp[i+1][maxDaysICanTravelWithoutPass];
                
// //                 dp[i][maxDaysICanTravelWithoutPass]=min(buyPass,notBuyPass);
// //             }
// //         }
        
// //         return dp[0][0];
// //     }
    
//     int spaceOptimisation(vector<int>& days, vector<int>& costs){
//         int n=days.size();
//         vector<int> prev(400,0),curr(400,0);
        
//         // Base Case
//         // Already done
        
//         int day[]={1,7,30};
//         for(int i=n-1;i>=0;i--){
//             for(int maxDaysICanTravelWithoutPass=0;maxDaysICanTravelWithoutPass<=395;maxDaysICanTravelWithoutPass++){
//                 int buyPass=1e9,notBuyPass=1e9;

//                 for(int j=0;j<3;j++) buyPass=min(buyPass,costs[j]+prev[days[i]+day[j]-1]);
//                 if(maxDaysICanTravelWithoutPass>=days[i]) notBuyPass=0+prev[maxDaysICanTravelWithoutPass];
                
//                 curr[maxDaysICanTravelWithoutPass]=min(buyPass,notBuyPass);
//             }
//             prev=curr;
//         }
        
//         return prev[0];
//     }
    
    
    int help(int i,vector<int> &days,vector<int> &costs,vector<int> &dp){
        
        if(i==days.size()) return 0;
        
        if(dp[i]!=-1) return dp[i];
        // When I buy One Day Pass
        
        int index=i;
        int option1=costs[0]+help(i+1,days,costs,dp);
        
        // When I Buy 7 Day Pass
        for(index=i;index<days.size() && days[i]+7-1>=days[index];index++);
        int option2=costs[1]+help(index+1,days,costs,dp);
        
        // When I Buy 30 Day Pass
        for(index=i;index<days.size() && days[i]+30-1>=days[index];index++);
        int option3=costs[2]+help(index+1,days,costs,dp);
        
        return dp[i]=min(option1,min(option2,option3));
    }
    int tabulation(vector<int>& days, vector<int>& costs){
        
        int n=days.size();
        vector<int> dp(n+1,0);
        
        // Base Case Done
        
        for(int i=n-1;i>=0;i--){
            int option1=1e9;
            int option2=1e9;
            int option3=1e9;
            int index;
            for(index=i;index<days.size() && days[i]+1-1>=days[index];index++)
                option1=costs[0]+dp[index+1];

            // When I Buy 7 Day Pass
            for(index=i;index<days.size() && days[i]+7-1>=days[index];index++)
                option2=costs[1]+dp[index+1];

            // When I Buy 30 Day Pass
            for(index=i;index<days.size() && days[i]+30-1>=days[index];index++)
                option3=costs[2]+dp[index+1];

            dp[i]=min(option1,min(option2,option3));
        }
        
        return dp[0];
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int n=days.size();
        vector<int> dp(n+1,-1);
        return help(0,days,costs,dp); // {i,days,costs}
        
        // return tabulation(days,costs);
    }
};