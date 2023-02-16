You have a 2-D grid of size m x n representing a box, and you have n balls. The box is open on the top and bottom sides.

Each cell in the box has a diagonal board spanning two corners of the cell that can redirect a ball to the right or to the left.

A board that redirects the ball to the right spans the top-left corner to the bottom-right corner and is represented in the grid as 1.
A board that redirects the ball to the left spans the top-right corner to the bottom-left corner and is represented in the grid as -1.


class Solution {
private:
//     int help(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &dp){
        
//         if(i==grid.size()) return j;
        
//         if(dp[i][j]!=-1) return dp[i][j];
        
//         int nextCol=j+grid[i][j]; // ye aisa kyun because grid[i][j] mein 1 aur -1 hi hai to j+grid[i][j] karoge tab wo ya to age jaega ya peeche to chahe jahan jae to same hona hona chahiye ball ko age le jane ke liye ( maine jo pehle likha tha usmein bahut conditions dal ke beekar kar diya tha)
        
//         if(nextCol<0 || nextCol>=grid[0].size() || grid[i][j]!=grid[i][nextCol]) return dp[i][j]=-1;
        
//         return dp[i][j]=help(i+1,nextCol,grid,dp);
//     }
    
    vector<int> tabulation(vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m+1,vector<int> (n+1,0));
        vector<int> ans;
        
        // Base Case
        for(int j=0;j<n;j++) dp[m][j]=j;
        
        
        for(int i=m-1;i>=0;i--){
            for(int j=0;j<n;j++){
                int nextCol=j+grid[i][j]; 
                if(nextCol<0 || nextCol>=grid[0].size() || grid[i][j]!=grid[i][nextCol]) dp[i][j]=-1;
                else dp[i][j]=dp[i+1][nextCol];
                
                if(i==0) ans.push_back(dp[0][j]);
            }
        }
        
        return ans;
    }

public:
    vector<int> findBall(vector<vector<int>>& grid) {
       
//         int m=grid.size();
//         int n=grid[0].size();
//         vector<vector<int>> dp(m,vector<int> (n,-1));
//         vector<int> ans;
        
//         for(int j=0;j<n;j++){
//             ans.push_back(help(0,j,grid,dp));
//         }
//         return ans;
        
        // return tabulation(grid);
    }
};