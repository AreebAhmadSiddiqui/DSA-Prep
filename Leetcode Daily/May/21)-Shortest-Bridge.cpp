934. Shortest Bridge

You are given an n x n binary matrix grid where 1 represents land and 0 represents water.

An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.

You may change 0's to 1's to connect the two islands to form one island.

Return the smallest number of 0's you must flip to connect the two islands.

Approach

a) Yahan to maine dono island nikale
b) Aur un sabhi ka manhattan distance nikal diya to bahut complexity a rahi hai


// class Solution {
// private:
//     bool isValid(int row,int col,int n,vector<vector<int>> &grid,vector<vector<int>> &vis){
//         return row>=0 && row<n && col>=0 && col<n && grid[row][col]==1 && !vis[row][col];
//     }
//     void bfs(int i,int j,int n,vector<vector<int>> &grid,vector<vector<int>> &vis,map<pair<int,int>,int> &mp){
        
//         queue<pair<int,int>> q;
//         q.push({i,j});
//         vis[i][j]=1;
        
//         mp[{i,j}]=1;
        
//         int dx[]={-1,1,0,0};
//         int dy[]={0,0,-1,1};
//         while(!q.empty()){
//             auto row=q.front().first;
//             auto col=q.front().second;
//             q.pop();
            
//             for(int del=0;del<4;del++){
//                 int newRow=row+dx[del];
//                 int newCol=col+dy[del];
                
//                 if(isValid(newRow,newCol,n,grid,vis)){
//                     q.push({newRow,newCol});
//                     vis[newRow][newCol]=1;
//                     mp[{newRow,newCol}]=1;
//                 }
//             }
//         }
//     }
// public:
//     int shortestBridge(vector<vector<int>>& grid) {
        
//         map<pair<int,int>,int> mp1,mp2;
    
//         int n=grid.size();
//         vector<vector<int>> vis(n,vector<int> (n,0));
        
//         int cnt=0;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 if(!vis[i][j] && grid[i][j]==1){
//                     if(cnt==0) {
//                         bfs(i,j,n,grid,vis,mp1);
//                         cnt++;
//                     }
//                     else bfs(i,j,n,grid,vis,mp2);
//                 }
//             }
//         }
        
//         int ans=1e9;
        
//         for(auto &it1:mp1){
//             for(auto &it2:mp2){
//                 int r1=it1.first.first;
//                 int c1=it1.first.second;
//                 int r2=it2.first.first;
//                 int c2=it2.first.second;
//                 // cout<<r1<<" "<<c1<<"\n"<<r2<<" "<<c2<<'\n';
//                 ans=min(ans,(abs(r1-r2)+abs(c1-c2)-1));
//             }
//         }
//         return ans;
//     }
// };
    

    
// Approach 2
    
// a) Pehle ek island nikal lo
// b) Fir us island ke elements se bfs shuru kar do
// c) aur jahan  1 dikhe wahan ans mein min(ans,steps) laga do
    
class Solution {
private:
    bool isValid(int row,int col,int n,vector<vector<int>> &grid,vector<vector<int>> &vis){
        return row>=0 && row<n && col>=0 && col<n && grid[row][col]==1 && !vis[row][col];
    }
    void bfs(int i,int j,int n,vector<vector<int>> &grid,vector<vector<int>> &vis,queue<pair<int,pair<int,int>>> &islandQueue){
        
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j]=1;
        
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        while(!q.empty()){
            auto row=q.front().first;
            auto col=q.front().second;
            q.pop();
            
            for(int del=0;del<4;del++){
                int newRow=row+dx[del];
                int newCol=col+dy[del];
                
                if(isValid(newRow,newCol,n,grid,vis)){
                    q.push({newRow,newCol});
                    vis[newRow][newCol]=1;
                }
            }
            islandQueue.push({row,{col,0}});
        }
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
       
        int n=grid.size();
        vector<vector<int>> vis(n,vector<int> (n,0));
        
        queue<pair<int,pair<int,int>>> islandQueue; // {i,j,steps}
        
        int c=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(c==1 && !vis[i][j] && grid[i][j]==1){
                    bfs(i,j,n,grid,vis,islandQueue);
                    c=0; // for once
                }
            }
        }
        
        int ans=1e9;
        
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        
        // cout<<islandQueue.size()<<'\n';
        while(!islandQueue.empty()){
            
           
            auto row=islandQueue.front().first;
            auto col=islandQueue.front().second.first;
            auto steps=islandQueue.front().second.second;
           
            // cout<<row<<" "<<col<<" "<<steps<<'\n';
            
            islandQueue.pop();
            
            for(int del=0;del<4;del++){
                int newRow=row+dx[del];
                int newCol=col+dy[del];
                
                if(newRow>=0 && newRow<n && newCol>=0 && newCol<n && !vis[newRow][newCol]){
                    if(grid[newRow][newCol]==0){
                        islandQueue.push({newRow,{newCol,steps+1}});
                        vis[newRow][newCol]=1;
                    }else{ // we reached one the island so take min of ans
                        ans=min(ans,steps);
                    }
                }
            }
            
        }
        return ans;
    }
};