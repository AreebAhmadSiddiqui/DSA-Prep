class Solution {
private:
//     int help(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &dp){
//         if(i<0 || j<0 ) return 1e9;
        
//         if(i==0 && j==0) return grid[0][0];
        
//         if(dp[i][j]!=-1) return dp[i][j];
        
//         int left=help(i,j-1,grid,dp);
//         int up=help(i-1,j,grid,dp);
        
//         return dp[i][j]=min(left,up)+grid[i][j];
//     }
    int tabulation(vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int> (n,0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(i==0 && j==0) dp[i][j]=grid[0][0];
                else{
                    int left=1e9,up=1e9;
                    
                    if(j>0) left=dp[i][j-1];
                    if(i>0) up=dp[i-1][j];
                    
                    dp[i][j]=min(left,up)+grid[i][j];
                }
            }
        }
        
        return dp[m-1][n-1];
    }
    
    int spaceOptimisation(vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        vector<int> prev(n,0),curr(n,0);
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(i==0 && j==0) curr[j]=grid[0][0];
                else{
                    int left=1e9,up=1e9;
                    
                    if(j>0) left=curr[j-1];
                    if(i>0) up=prev[j];
                    
                    curr[j]=min(left,up)+grid[i][j];
                }
            }
            prev=curr;
        }
        
        return prev[n-1];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        // vector<vector<int>> dp(m,vector<int> (n,-1));
        // return help(m-1,n-1,grid,dp);
        
        // return tabulation(grid);
        return spaceOptimisation(grid);
    }
};