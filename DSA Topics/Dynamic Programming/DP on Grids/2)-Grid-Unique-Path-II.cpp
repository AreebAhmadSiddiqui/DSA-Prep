class Solution {
private:
    int help(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &dp){
        if(i<0 || j<0 || grid[i][j]==1) return 0;
        
        if(i==0 && j==0) return 1;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int left=help(i,j-1,grid,dp);
        int up=help(i-1,j,grid,dp);
        
        return dp[i][j]=left+up;
    }
    
    int tabulation(vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> dp(m,vector<int> (n,0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=1){
                     if(i==0 && j==0) dp[i][j]=1;
                     else{
                         int left=0,up=0;
                     if(j>0) left=help(i,j-1,grid,dp);
                     if(i>0) up=help(i-1,j,grid,dp);

                     dp[i][j]=left+up;
                     }
                }
            }
        }
        
        return dp[m-1][n-1];
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        
        // vector<vector<int>> dp(m,vector<int> (n,-1));
        // return help(m-1,n-1,obstacleGrid,dp);
        
        vector<vector<int>> dp(m,vector<int> (n,0));
        return tabulation(obstacleGrid);
    }
};