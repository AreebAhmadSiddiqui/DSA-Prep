// Same as Ninjas Training


class Solution {
private:
    int help(int i,int prev,vector<vector<int>> &grid,int n,vector<vector<int>> &dp){
        if(i==0){
            int mini=INT_MAX;
            
            for(int j=0;j<n;j++){
                if(j!=prev) mini=min(mini,grid[0][j]);
            }
            
            return mini;
        }
        
        if(dp[i][prev]!=-1) return dp[i][prev];
        
        int mini=INT_MAX;
        for(int k=0;k<n;k++){
            if(k!=prev){
                mini=min(mini,grid[i][k]+help(i-1,k,grid,n,dp));
            }
        }
        
        return dp[i][prev]=mini;
    }
    int tabulation(vector<vector<int>>& grid){
        int n=grid.size();
        vector<vector<int>> dp(n,vector<int> (n+1,0));
        
        // Base Case
        for(int prev=0;prev<=n;prev++){
            
            int mini=INT_MAX;
            for(int j=0;j<n;j++){
                if(j!=prev) mini=min(mini,grid[0][j]);
            }
            
            dp[0][prev]=mini;
        }
        
        for(int i=1;i<n;i++){
            for(int prev=0;prev<=n;prev++){
                int mini=INT_MAX;
                for(int k=0;k<n;k++){
                    if(k!=prev){
                        mini=min(mini,grid[i][k]+dp[i-1][k]);
                    }
                }
                
                dp[i][prev]=mini;
            }
        }
        
        return dp[n-1][n];
    }
    
    int spaceOptimisation(vector<vector<int>> &grid){
        int n=grid.size();
        vector<int> prev(n+1,0),curr(n+1,0);
        
        // Base Case
        for(int lastPick=0;lastPick<=n;lastPick++){
            
            int mini=INT_MAX;
            for(int j=0;j<n;j++){
                if(j!=lastPick) mini=min(mini,grid[0][j]);
            }
            
            prev[lastPick]=mini;
        }
        
        for(int i=1;i<n;i++){
            for(int lastPick=0;lastPick<=n;lastPick++){
                int mini=INT_MAX;
                for(int k=0;k<n;k++){
                    if(k!=lastPick){
                        mini=min(mini,grid[i][k]+prev[k]);
                    }
                }
                
                curr[lastPick]=mini;
            }
            prev=curr;
        }
        
        return prev[n];
    }
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        
//         int n=grid.size();
//         vector<vector<int>> dp(n,vector<int> (n+1,-1));
        
//         return help(n-1,n,grid,n,dp);
        
        // return tabulation(grid);
            return spaceOptimisation(grid);
    }
};