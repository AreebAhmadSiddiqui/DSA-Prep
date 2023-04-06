Similar to no of enclaves ( Bas no of components cnt Karna hai)
    
Number of Closed Islands
Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.
    

class Solution {
private:
    bool isValid(int row,int col,vector<vector<int>> &vis,vector<vector<int>> &grid){
        int n=grid.size();
        int m=grid[0].size();
        
        return row>=0 && row<n && col>=0 && col<m && !vis[row][col] && grid[row][col]==0;
    }
    void bfs(int i,int j,vector<vector<int>> &vis,vector<vector<int>> &grid){
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j]=1;
        
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
            for(int del=0;del<4;del++){
                int newRow=row+dx[del];
                int newCol=col+dy[del];
                
                if(isValid(newRow,newCol,vis,grid)){
                    q.push({newRow,newCol});
                    vis[newRow][newCol]=1;
                }
            }
        }
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        
        // a) Remove those zeroes on the edges of the cells
            
        vector<vector<int>> vis(n,vector<int> (m,0));
        
        for(int j=0;j<m;j++){
            if(vis[0][j]==0 && grid[0][j]==0){
                bfs(0,j,vis,grid);
            }
        }
        
        for(int i=0;i<n;i++){
            if(vis[i][0]==0 && grid[i][0]==0){
                bfs(i,0,vis,grid);
            }
        }
        
        for(int j=0;j<m;j++){
            if(vis[n-1][j]==0 && grid[n-1][j]==0){
                bfs(n-1,j,vis,grid);
            }
        }
        
        for(int i=0;i<n;i++){
            if(vis[i][m-1]==0 && grid[i][m-1]==0){
                bfs(i,m-1,vis,grid);
            }
        }
        
        int cnt=0;
        // Now find the connected components of zeroes inside
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(!vis[i][j] && grid[i][j]==0){
                    cnt++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }
};