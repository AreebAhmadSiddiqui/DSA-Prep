class Solution {
private:
//     int help(int i,int n,vector<int> &sqrs,vector<vector<int>> &dp){
        
//         if(i==0){
//             return n/sqrs[i];
//         }
//         if(dp[i][n]!=-1) return dp[i][n];
        
//         int pick=1e9,notPick=1e9;
//         if(n-sqrs[i]>=0) pick=1+help(i,n-sqrs[i],sqrs,dp);
//         notPick=0+help(i-1,n,sqrs,dp);
        
//         return dp[i][n]=min(pick,notPick);
//     }
    
//     int tabulation(int n){
        
//         // All Sqrs
//         vector<int> sqrs;
//         for(int i=1;i*i<=n;i++){
//             sqrs.push_back(i*i);
//         }
        
//         vector<vector<int>> dp(sqrs.size()+1,vector<int> (n+1,0));
        
//         // Base Case
//         for(int i=0;i<=n;i++) dp[0][i]=i;
        
//         for(int i=1;i<sqrs.size();i++){
//             for(int j=0;j<=n;j++){
//                 int pick=1e9,notPick=1e9;
//                 if(j-sqrs[i]>=0) pick=1+dp[i][j-sqrs[i]];
//                 notPick=0+dp[i-1][j];

//                 dp[i][j]=min(pick,notPick);
//             }
//         }
        
//         return dp[sqrs.size()-1][n];
//     }
    
     int spaceOptimisation(int n){
        
        // All Sqrs
        vector<int> sqrs;
        for(int i=1;i*i<=n;i++){
            sqrs.push_back(i*i);
        }
        
        vector<int> prev(n+1,0),curr(n+1,0);
        
        // Base Case
        for(int i=0;i<=n;i++) prev[i]=i;
        
        for(int i=1;i<sqrs.size();i++){
            for(int j=0;j<=n;j++){
                int pick=1e9,notPick=1e9;
                if(j-sqrs[i]>=0) pick=1+curr[j-sqrs[i]];
                notPick=0+prev[j];

                curr[j]=min(pick,notPick);
            }
            prev=curr;
        }
        
        return prev[n];
    }
public:
//     int numSquares(int n) {
        
// //         // All Sqrs
// //         vector<int> sqrs;
// //         for(int i=1;i*i<=n;i++){
// //             sqrs.push_back(i*i);
// //         }
        
// //         vector<vector<int>> dp(sqrs.size()+1,vector<int> (n+1,-1));
// //         return help(sqrs.size()-1,n,sqrs,dp);
        
//         // return tabulation(n);
//         return spaceOptimisation(n);
//     }
    
    
    // Same as min multiplication to reach end
    int numSquares(int n) {
        
        vector<int> sqrs;
        for(int i=1;i*i<=n;i++){
            sqrs.push_back(i*i);
        }
        
        reverse(sqrs.begin(),sqrs.end());
        
        // BFS Method
        queue<pair<int,int>> q; // {node,steps}
        q.push({0,0});
        while(!q.empty()){      
            auto node=q.front().first;
            auto steps=q.front().second;
            q.pop();
            
            for(auto &child:sqrs){
                if(node+child<=n){
                    if(node+child==n) return steps+1;
                    q.push({node+child,steps+1});
                }
            }
        }
        
        return -1;
    }
};