Maximum Sum of an Hourglass

You are given an m x n integer matrix grid.

We define an hourglass as a part of the matrix with the following form:

class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        
        int ans=0;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                // choices
                // i,j
                // i-1,j
                // i-1,j-1
                // i+1,j-1
                // i+1,j
                // i+1,j+1
                // i-1,j+1
                int sum=grid[i][j]+grid[i-1][j]+grid[i-1][j-1]+grid[i+1][j-1]+grid[i+1][j]+grid[i+1][j+1]+grid[i-1][j+1];
                ans=max(ans,sum);
            }
        }
        return ans;
    }
};