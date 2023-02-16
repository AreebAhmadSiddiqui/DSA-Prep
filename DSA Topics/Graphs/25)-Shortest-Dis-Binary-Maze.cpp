class Solution {
  public:
    // Simple BFS laga diya kyunki sab ek unit ke distance pe the agar aisa na hota to PQ lagata
    // PQ lagane ka koi fayda ni tha kyunki sab same distance pe the
    // Ek aur observation hai ki agar tum destination par pahunch gae to wo min hi to hoga kyunki ek ek kar ke a rahe ho to return kar sakte wahi
    // poori table banane ki zarurat ni
    
    TC-> O(n*m*4)
    SC-> O(n*m)
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
       
       int n=grid.size(),m=grid[0].size();
       vector<vector<int>> distance(n,vector<int> (m,1e9));
       
       queue<pair<int,int>> q;
       q.push(source);
       distance[source.first][source.second]=0;
       
       
       int dx[]={-1,1,0,0};
       int dy[]={0,0,-1,1};
       
       while(!q.empty()){
           int row=q.front().first;
           int col=q.front().second;
           q.pop();
           
           for(int i=0;i<4;i++){
               int newRow=row+dx[i];
               int newCol=col+dy[i];
               
               if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && 
               grid[newRow][newCol]==1 && (distance[row][col]+1<distance[newRow][newCol])){
                   q.push({newRow,newCol});
                   distance[newRow][newCol]=distance[row][col]+1;
               }
           }
       }
       
       if(distance[destination.first][destination.second]==1e9) return -1;
       
       return distance[destination.first][destination.second];
    }
};