// Just find the articulation point

bfs jab karoge to agar 0 children ae queu mein tab to bhaiya return true karoge hi kyunki wo end tak pahunch hi ni paya
aur agar q.size==1 to q mein jo co ordinat pade hai wo dest hai tab to return false kar do warna return true

  0 1 2 3 4
0 1 1 1 0 0   yahan jab tum bfs karoge to pehle (0,0) fir ({0,1},{1,0}) fir ({0,2},{1,1}) uske baad sirf ({1,2}) aega ye articulation point hai to ise remove kardenge to kabhi ni pahunch paegnge
1 1 1 1 0 0
2 0 0 1 1 1
3 0 0 1 1 1

wahi agar example liye ki 

  0 1 2
0 1 1 1
1 1 0 1 Ismein bfs karoge to last mein qsize 1 hoga lekin wo to end point hi hai to usko na lo
2 1 1 1
class Solution {
private:
    bool isValid(int row,int col,vector<vector<int>> &grid,vector<vector<int>> &vis){
        int n=grid.size();
        int m=grid[0].size();
        return row<n && col<m && grid[row][col]==1 && vis[row][col]==0;
    }
public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        if(n==1 && m==1 || n==2 && m==1 || n==1 && m==2) return false;
        
        vector<vector<int>> vis(n,vector<int> (m));
        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0][0]=1;
        
        int dx[]={1,0};
        int dy[]={0,1};
        
        while(!q.empty()){
            
            int size=q.size();
            for(int i=0;i<size;i++){
                int row=q.front().first;
                int col=q.front().second;
                q.pop();

                for(int del=0;del<2;del++){
                    int newRow=row+dx[del];
                    int newCol=col+dy[del];

                    if(isValid(newRow,newCol,grid,vis)){
                        q.push({newRow,newCol});
                        vis[newRow][newCol]=1;
                    }
                }
            }
            if(q.size()==0) return true;
            if(q.size()==1){
                
                // Check if it is the destination if not this is the articulation point
                int row=q.front().first;
                int col=q.front().second;
                q.pop();
                return !(row==n-1 && col==m-1);
            }
        }
        return false;
    }
};