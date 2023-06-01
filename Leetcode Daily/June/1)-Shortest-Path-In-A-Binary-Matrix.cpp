1091. Shortest Path in Binary Matrix

Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.
    

struct Data{
    int dis,x,y;
    Data(int d,int _x,int _y){
        dis=d;
        x=_x;
        y=_y;
    }
};
class Solution {
private:
    bool isValid(int row,int col,int n,vector<vector<int>> &vis,vector<vector<int>> &grid){
        return row>=0 && row<n && col>=0 && col<n && !vis[row][col] && grid[row][col]==0;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        queue<Data> q; // {dis,node};
        
        int n=grid.size();
        vector<vector<int>> vis(n,vector<int> (n,0));
        vector<vector<int>> dist(n,vector<int> (n,1e9));
        
        if(grid[0][0]!=0) return -1;
        
        q.push(Data(1,0,0));
        vis[0][0]=1;
        dist[0][0]=1;
        
        int dx[]={0,0,-1,1,1,1,-1,-1};
        int dy[]={1,-1,0,0,1,-1,-1,1};
        
        while(!q.empty()){
            auto it=q.front();
            auto dis=it.dis;
            auto row=it.x;
            auto col=it.y;
            q.pop();
            
            
            for(auto del=0;del<8;del++){
                auto newRow=row+dx[del];
                auto newCol=col+dy[del];
                
                if(isValid(newRow,newCol,n,vis,grid) && dist[newRow][newCol]>dis+1){
                    q.push(Data(dis+1,newRow,newCol));
                    vis[newRow][newCol]=1;
                    dist[newRow][newCol]=dis+1;
                }
            }    
        }
        
        return dist[n-1][n-1]==1e9 ? -1 : dist[n-1][n-1];
    }
};