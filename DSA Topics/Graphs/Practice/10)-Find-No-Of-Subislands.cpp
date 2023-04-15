1905. Count Sub Islands

You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing land). An island is a group of 1's connected 4-directionally (horizontal or vertical). Any cells outside of the grid are considered water cells.

An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells that make up this island in grid2.

Return the number of islands in grid2 that are considered sub-islands.

class Solution {
private:
    bool isValid(int i,int j,vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<int>>& vis) {
        int n=grid1.size();
        int m=grid1[0].size();
        
        return i>=0 && i<n && j>=0 && j<m && !vis[i][j] && grid2[i][j]==1;
    }
    bool bfs(int i,int j,vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<int>>& vis) {
        
        queue<pair<int,int>> q;
        
        q.push({i,j});
        vis[i][j]=1;
        
        int dx[]={-1,1,0,0};
        int dy[]={0,0,1,-1};
        
        bool ans=true;
        while(!q.empty()){
            auto row=q.front().first;
            auto col=q.front().second;
            q.pop();
            
            // koi bhi row and col agar grid1 mein water hai to ye wala island kabhi bhi uska subpart ni ban sakta
            if(grid1[row][col]==0){
                ans=false;
            }
            for(int dir=0;dir<4;dir++){
                auto newRow=row+dx[dir];
                auto newCol=col+dy[dir];
                
                if(isValid(newRow,newCol,grid1,grid2,vis)){
                    q.push({newRow,newCol});
                    vis[newRow][newCol]=1;
                }
            }
        }
        return ans;
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        int n=grid1.size();
        int m=grid1[0].size();
        
        int cnt=0;
        vector<vector<int>> vis(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid2[i][j]==1 && grid1[i][j]==1){
                    
                    // Agar answer positive ae tab hi add karo warna na karo
                    cnt+= bfs(i,j,grid1,grid2,vis);
                }
            }
        }
        return cnt;
    }
};