Count Servers that Communicate

You are given a map of a server center, represented as a m * n integer matrix grid, where 1 means that on that cell there is a server and 0 means that it is no server. Two servers are said to communicate if they are on the same row or on the same column.

Return the number of servers that communicate with any other server.

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        
        // Count Servers in rows and columns and check if there is an isolated element
        
        int m=grid.size();
        int n=grid[0].size();
        vector<int> rows(m,0),col(n,0);
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    rows[i]++;
                    col[j]++;
                }
            }
        }
        int ans=0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && (rows[i]>1 || col[j]>1)){
                    ans++;
                }
            }
        }
        return ans;
    }
};