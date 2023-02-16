class Solution {
private:

    TC->O(n*m + n*m*4)
    SC->O(n*m+n*m)

    // Ismeina hame visited ki zarurat ni kyunki ham ans ko update kar de rahe hai to jab bhi naya row col aega aur wo already visited hoga to uska color change ho chuka hoga
    void bfs(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &ans,int iniColor,int color){
        
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        int n=grid.size();
        int m=grid[0].size();
        
       
        ans[i][j]=color;
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
                if(newRow>=0 && newRow<n && newCol>=0 && newCol<m &&  grid[newRow][newCol]==iniColor && 
                
                ans[newRow][newCol]!=color){ // this condition is needed to avoid using visited array
                    q.push({newRow,newCol});
                    ans[newRow][newCol]=color;
                }
            }
            
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        int iniColor=image[sr][sc];
        vector<vector<int>> ans=image;
        bfs(sr,sc,image,ans,iniColor,color);
        return ans;
    }
};