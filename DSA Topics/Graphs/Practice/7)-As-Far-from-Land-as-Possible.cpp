1162. As Far from Land as Possible

Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return -1.

The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.
    
struct Data{
    int row,col,dist;
    Data(int r,int c,int d){
        row=r;
        col=c;
        dist=d;
    }
};
class Solution {
private:
    bool isValid(int row,int col,vector<vector<int>> &grid,vector<vector<int>> &vis){
        return row>=0 && row<grid.size() && col>=0 && col<grid.size() && grid[row][col]==0 && vis[row][col]==0;
    }
public:
    int maxDistance(vector<vector<int>>& grid) {
     
        // Manhattan distance is the no of steps thats it bas mutisource bfs laga do
        
        int n=grid.size();
        queue<Data> q; // {row,col,dist}
        
        vector<vector<int>> vis(n,vector<int> (n,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                   q.push({i,j,0}); 
                   vis[i][j]=1;
                }
            }
        }
        
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        
        int maxi=-1;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            
            int row=it.row;
            int col=it.col;
            int dist=it.dist;
            maxi=max(maxi,dist);
            
            for(int i=0;i<4;i++){
                int newRow=row+dx[i];
                int newCol=col+dy[i];
                
                if(isValid(newRow,newCol,grid,vis)){
                    q.push({newRow,newCol,dist+1});
                    vis[newRow][newCol]=1;
                }
            }
        }
        
        return maxi==0 ? -1 : maxi;
    }
};

Map of Highest Peak

Ismein tumhe jo dist array banega use print karna hai bas aur 1 ka matlab water hai 0 ka matlab land hai bas yahi change aur haan n*m hai na ki n*n
struct Data{
    int row,col,dist;
    Data(int r,int c,int d){
        row=r;
        col=c;
        dist=d;
    }
};
class Solution {
private:
    bool isValid(int row,int col,vector<vector<int>> &isWater,vector<vector<int>> &vis){
        
        int n=isWater.size();
        int m=isWater[0].size();
        return row>=0 && row<n && col>=0 && col<m && isWater[row][col]==0 && vis[row][col]==0;
    }
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        
        int n=isWater.size();
        int m=isWater[0].size();
        queue<Data> q; // {row,col,dist}
        
        vector<vector<int>> vis(n,vector<int> (m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]==1){
                   q.push({i,j,0}); 
                   vis[i][j]=0;
                }
            }
        }
        
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            
            int row=it.row;
            int col=it.col;
            int dist=it.dist;
            
            for(int i=0;i<4;i++){
                int newRow=row+dx[i];
                int newCol=col+dy[i];
                
                if(isValid(newRow,newCol,isWater,vis)){
                    q.push({newRow,newCol,dist+1});
                    vis[newRow][newCol]=dist+1;
                }
            }
        }
        
       return vis;
    }
};
