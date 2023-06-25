1575. Count All Possible Routes

You are given an array of distinct positive integers locations where locations[i] represents the position of city i. You are also given integers start, finish and fuel representing the starting city, ending city, and the initial amount of fuel you have, respectively.

At each step, if you are at city i, you can pick any city j such that j != i and 0 <= j < locations.length and move to city j. Moving from city i to city j reduces the amount of fuel you have by |locations[i] - locations[j]|. Please notice that |x| denotes the absolute value of x.

Notice that fuel cannot become negative at any point in time, and that you are allowed to visit any city more than once (including start and finish).

Return the count of all possible routes from start to finish. Since the answer may be too large, return it modulo 109 + 7
    
    
class Solution {
private:
    int mod=1000000007;
    int help(int i,int n,vector<int> &locations,int finish,int fuel,vector<vector<int>> &dp){
    
        // Kisi bhi point pe fuel agar zero ho gaya to age jane ka koi point ni aur agar i ==finish hai to return 1 otherwise return 0
        if(fuel==0){
            return i==finish;
        }

        if(dp[i][fuel]!=-1) return dp[i][fuel];
        
    
        // Baaki sab sahi hai but ye dhyan dena agar i==finish to ek way to hai hi wo use add kar do
        int cnt= i==finish ;
        
        for(int j=0;j<n;j++){
            int diff=abs(locations[j]-locations[i]);
            if(j!=i && diff<=fuel){
                cnt=(cnt+help(j,n,locations,finish,fuel-diff,dp))%mod;
            }
        }
        return dp[i][fuel]=cnt;
    }
    
    int tabulation(vector<int>& locations, int start,int finish, int fue) {
        int n=locations.size();
        vector<vector<int>> dp(n+1,vector<int> (fue+1,0));
        
        // Base Case
        dp[finish][0]=1;
        
        
        for(int fuel=1;fuel<=fue;fuel++){
            for(int i=0;i<n;i++){
                int cnt=0;
                if(i==finish) cnt=1;
                for(int j=0;j<n;j++){
                    int diff=abs(locations[j]-locations[i]);
                    if(j!=i && diff<=fuel){
                        cnt=(cnt+dp[j][fuel-diff])%mod;
                    }
                }
                dp[i][fuel]=cnt;
            }
        }
        return dp[start][fue];
    }
public:
    int countRoutes(vector<int>& locations, int start,int finish, int fuel) {
        
        // int n=locations.size();
        // vector<vector<int>> dp(n+1,vector<int> (fuel+1,-1));
        // return help(start,locations.size(),locations,finish,fuel,dp);
        return tabulation(locations,start,finish,fuel);
    }
};