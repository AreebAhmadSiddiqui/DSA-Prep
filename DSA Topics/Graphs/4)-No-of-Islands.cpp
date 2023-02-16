class Solution {
private:

    // TC-> O(n*m + m*n*4)
    // SC-> O(n*m+n*m)
    void bfs(int i,int j,vector<vector<int>> &vis,vector<vector<char>> &grid){
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        int n=grid.size();
        int m=grid[0].size();
        
        vis[i][j]=1;
        queue<pair<int,int>> q;
        q.push({i,j});
        

        // O(4)
        while(!q.empty()){
            
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
            // Traverse the neighbours In this 4 directions in gfg 8 directions
            for(int del=0;del<4;del++){
                int newRow=row+dx[del];
                int newCol=col+dy[del];
                // If valid
                if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && !vis[newRow][newCol] && grid[newRow][newCol]=='1'){
                    q.push({newRow,newCol});
                    vis[newRow][newCol]=1;
                }
            }
            
        }
    }
public:
    
    // Ismein row aur column number diff hain to simple vis vector ni chalega 2d lena padega
    // aur node mein bhi single node ni chalega pair lena padega
    int numIslands(vector<vector<char>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> vis(n,vector<int> (m,0));
        
        int cnt=0;

        // N*M
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }
};