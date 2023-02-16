class Solution {
public:

    TC-> (n*m+n*m*4)
    SC-> (n*m+n*m)
    int orangesRotting(vector<vector<int>>& grid) {
        
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        int vis[grid.size()][grid[0].size()];
        int fresh=0;
        
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    vis[i][j]=2;
                }
                else if(grid[i][j]==1){
                    fresh++;
                    vis[i][j]=1;
                }
                else{
                    vis[i][j]=0;
                }
            }
        }
        
        int time=-1;
        while(!q.empty()){ //n*m
            
            int size=q.size(); // O(1)
            for(int i=0;i<size;i++){
                
                int row=q.front().first;
                int col=q.front().second;
                q.pop();
                
                for(int del=0;del<4;del++){ // O(n*m*4)
                    int newRow=row+dx[del];
                    int newCol=col+dy[del];
                    
                    // If valid
                    if(newRow>=0 && newRow<grid.size() && newCol>=0 && newCol<grid[0].size() && vis[newRow][newCol]==1){
                            q.push({newRow,newCol});
                            fresh--;
                            vis[newRow][newCol]=2;
                    }
                }
            }
            time++;
        }
        if(fresh!=0) return -1;
        return time==-1 ? 0 : time;
    }
};