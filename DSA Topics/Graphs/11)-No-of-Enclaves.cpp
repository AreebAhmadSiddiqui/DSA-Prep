class Solution {
public:
    private:


    TC-> O(n+m+n*m*4)
    SC-> O(n*m)
    void dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>> &vis){
        
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        
       
        vis[row][col]=1;
        
        for(int i=0;i<4;i++){
            
            int newRow=row+dx[i];
            int newCol=col+dy[i];
            if(newRow>=0 && newRow<grid.size() && newCol>=0 && newCol<grid[0].size() && grid[newRow][newCol]==1 && !vis[newRow][newCol]){
                dfs(newRow,newCol,grid,vis);
            }
        }
    }
    public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int> (n,0));
        
        // Get the boundary ones
        
        for(int j=0;j<n;j++){
            // First row
            if(!vis[0][j] && grid[0][j]==1){
                dfs(0,j,grid,vis);
            }
            
            // Last row
            if(!vis[m-1][j] && grid[m-1][j]==1){
                dfs(m-1,j,grid,vis);
            }
        }
        
        
        for(int i=0;i<m;i++){
            // First col
            if(!vis[i][0] && grid[i][0]==1){
                dfs(i,0,grid,vis);
            }
            
            // Last col
            if(!vis[i][n-1] && grid[i][n-1]==1){
                dfs(i,n-1,grid,vis);
            }
        }
        
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]!=1 && grid[i][j]==1) { // This 1 can be surrounded 
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};