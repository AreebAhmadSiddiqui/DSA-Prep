class Solution {
private:
    int help(int i,int j1,int j2,int n,int m,vector<vector<int>> &grid,vector<vector<vector<int>>> &dp){
        if(j1<0 || j1>=m || j2<0 || j2>=m) return 0;
        
        if(i==n-1){
            
            if(j1==j2) return grid[i][j1];
            return grid[i][j1]+grid[i][j2];
        }
        
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        
        int ans=0;
        for(int dx1=-1;dx1<=1;dx1++){
            for(int dx2=-1;dx2<=1;dx2++){
                // move simultaneously
                int points=grid[i][j1]+grid[i][j2]+help(i+1,j1+dx1,j2+dx2,n,m,grid,dp);
                
                // this is wrong
                // int robo1=grid[i][j1]+help(i+1,j1+dx1,j2+dx2,n,m,grid,dp);
                // int robo2=grid[i][j2]+help(i+1,j1+dx1,j2+dx2,n,m,grid,dp);
                
                ans=max(ans,points);
                if(j1==j2) ans-=grid[i][j1]; // if they are at the same level take only one time
            }
        }
        
        return dp[i][j1][j2]=ans;
    }
    int tabulation(vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (m,vector<int> (m,0)));
        
        // Base Case
        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
                if(j1==j2) dp[n-1][j1][j2]=grid[n-1][j1];
                else dp[n-1][j1][j2]=grid[n-1][j1]+grid[n-1][j2];
            }
        }
        
        for(int i=n-2;i>=0;i--){
            for(int j1=m-1;j1>=0;j1--){
                for(int j2=m-1;j2>=0;j2--){
                    int ans=0;
                    for(int dx1=-1;dx1<=1;dx1++){
                        for(int dx2=-1;dx2<=1;dx2++){
                           
                            if(j1+dx1<0 || j1+dx1>=m || j2+dx2<0 || j2+dx2>=m) continue;
                             
                            // move simultaneously
                            int points=grid[i][j1]+grid[i][j2]+dp[i+1][j1+dx1][j2+dx2];
                            ans=max(ans,points);
                            
                            if(j1==j2) ans-=grid[i][j1]; // if they are at the same level take only one time
                        }
                    }
                    dp[i][j1][j2]=ans;
                }
            }
        }
        
        return dp[0][0][m-1];
    }
    
    int spaceOptimisation(vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> front(m,vector<int> (m,0)),curr(m,vector<int> (m,0));
        
        // Base Case
        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
                if(j1==j2) front[j1][j2]=grid[n-1][j1];
                else front[j1][j2]=grid[n-1][j1]+grid[n-1][j2];
            }
        }
        
        for(int i=n-2;i>=0;i--){
            for(int j1=m-1;j1>=0;j1--){
                for(int j2=m-1;j2>=0;j2--){
                    int ans=0;
                    for(int dx1=-1;dx1<=1;dx1++){
                        for(int dx2=-1;dx2<=1;dx2++){
                           
                            if(j1+dx1<0 || j1+dx1>=m || j2+dx2<0 || j2+dx2>=m) continue;
                             
                            // move simultaneously
                            int points=grid[i][j1]+grid[i][j2]+front[j1+dx1][j2+dx2];
                            ans=max(ans,points);
                            
                            if(j1==j2) ans-=grid[i][j1]; // if they are at the same level take only one time
                        }
                    }
                    curr[j1][j2]=ans;
                }
            }
            front=curr;
        }
        
        return front[0][m-1];
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        
//         int n=grid.size();
//         int m=grid[0].size();
        
//         vector<vector<vector<int>>> dp(n,vector<vector<int>> (m,vector<int> (m,-1)));
//         return help(0,0,m-1,n,m,grid,dp);
        
        // return tabulation(grid);
        return spaceOptimisation(grid);
    }
};