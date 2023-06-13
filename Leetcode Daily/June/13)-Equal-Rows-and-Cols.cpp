2352. Equal Row and Column Pairs

Given a 0-indexed n x n integer matrix grid, return the number of pairs (ri, cj) such that row ri and column cj are equal.

A row and column pair is considered equal if they contain the same elements in the same order (i.e., an equal array).
    
    
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                
                int flag=1;
                for(int x=0;x<n;x++){
                    if(grid[i][x]!=grid[x][j]){
                        flag=0;
                        break;
                    }
                }
                cnt+=flag==1;
            }
        }
        return cnt;
        
        
//         map<vector<int>,int> mp;
//         int cnt=0;
//         for(int i=0;i<n;i++){
//             vector<int> temp;
//             for(int j=0;j<n;j++){
//                 temp.emplace_back(grid[i][j]);
//             }
//             mp[temp]++;
//         }
        
//         for(int j=0;j<n;j++){
//             vector<int> temp;
//             for(int i=0;i<n;i++){
//                 temp.emplace_back(grid[i][j]);
//             }
//             cnt+=mp[temp];
//         }
        
//         return cnt;
    }
};