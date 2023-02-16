// Steps

// 1) Same as the no of islands wala bas yahan distinct chahiye
// 2) Matlab agar main RRD wala ones liya to koi bhi doosra RRD same hi hoga
// 3) To maine ismein kya kiya ek set le lo for distinct 
// 4) aur base index wala concept laga do matlab jahan se bfs dfs shuru karo use base index le lo aur jahan jate jao usmein se base index minus karte jao
// 5) Aur unhe ek vector mein store kara lo 
// 6) aur last mein set.size() kar do


// TC->O(n*m*log(n*m)+n*m*4)
// SC->O(n*m+n*m)
class Solution {
  private:
    void dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& vis,vector<pair<int,int>> &order,int iniRow,int iniCol){
        
        vis[row][col]=1;
        order.push_back({row-iniRow,col-iniCol});
        
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        
        for(int i=0;i<4;i++){
            
            int newRow=row+dx[i];
            int newCol=col+dy[i];
            
            if(newRow>=0 && newRow<grid.size() && newCol>=0 && newCol<grid[0].size() && grid[newRow][newCol]==1 && !vis[newRow][newCol]){
                dfs(newRow,newCol,grid,vis,order,iniRow,iniCol);
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        set<vector<pair<int,int>>> st;
        vector<vector<int>> vis(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    vector<pair<int,int>> order;
                    dfs(i,j,grid,vis,order,i,j);
                    st.insert(order);
                }
            }
        }
        return st.size();
    }
};