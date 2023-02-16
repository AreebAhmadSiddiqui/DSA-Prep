695. Max Area of Island
You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.
class Solution {
private:
    bool isValid(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& vis){
        int n=grid.size();
        int m=grid[0].size();
        return row>=0 && row<n && col>=0 && col<m && grid[row][col]==1 && !vis[row][col];
    }
    int bfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis){
        
        queue<pair<int,int>> q;
        q.push({i,j});
        
        vis[i][j]=1;
        int cntNodes=0;
        
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            cntNodes++;
            
            for(int del=0;del<4;del++){
                int newRow=row+dx[del];
                int newCol=col+dy[del];
                
                if(isValid(newRow,newCol,grid,vis)){
                    q.push({newRow,newCol});
                    vis[newRow][newCol]=1;
                }
            }
        }
        
        return cntNodes;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        int ans=0;
        
        // O(m*n+4*m*n)
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    ans=max(ans,bfs(i,j,grid,vis));
                }
            }
        }
        return ans;
    }
};