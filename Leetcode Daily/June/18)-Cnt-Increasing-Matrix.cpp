2328. Number of Increasing Paths in a Grid

You are given an m x n integer matrix grid, where you can move from a cell to any adjacent cell in all 4 directions.

Return the number of strictly increasing paths in the grid such that you can start from any cell and end at any cell. Since the answer may be very large, return it modulo 109 + 7.

Two paths are considered different if they do not have exactly the same sequence of visited cells.
    
Approach

a) Simply grid traversal hai 
b) Bas paths ko 1 initialise kar dena kyunki row,col khud ek path bhi hai isliye


class Solution {
public:
    int mod=1000000007;
    bool isValid(int row,int col,int n,int m){
        return row>=0 && row<n && col>=0 && col<m;
    }
    int getWays(int row,int col,int n,int m,vector<vector<int>> &grid,vector<vector<int>> &dp){
        
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        
        if(dp[row][col]!=-1) return dp[row][col];
        
        
        int paths=0; // Each cell will contribute to 1 path
        
        for(int del=0;del<4;del++){
            int newRow=row+dx[del];
            int newCol=col+dy[del];
            if(isValid(newRow,newCol,n,m)){
                if(grid[newRow][newCol]>grid[row][col]){
                    paths=(paths%mod+getWays(newRow,newCol,n,m,grid,dp)%mod)%mod;
                }
            }
        }
        
        return dp[row][col] = paths;
    }
    int countPaths(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        
        int cntWays=0;
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cntWays=(cntWays%mod+getWays(i,j,n,m,grid,dp)%mod)%mod;
            }
        }
        
        return cntWays;
    }
};