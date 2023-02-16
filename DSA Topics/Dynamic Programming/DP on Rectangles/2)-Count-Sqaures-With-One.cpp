class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
     
        vector<vector<int>> dp(matrix.size(),vector<int> (matrix[0].size()));
        
        // dp[i][j]-> Number of sqaure if i and j are the bottom right corner
        
        // Base Case (Because these values cannot form more than 1 size sqaure)
        for(int i=0;i<matrix.size();i++) dp[i][0]=matrix[i][0];
        for(int j=0;j<matrix[0].size();j++) dp[0][j]=matrix[0][j];
        
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i][j]) dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j-1],dp[i-1][j]));
            }
        }
                             
        int cnt=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                cnt+=dp[i][j];
            }
        }
        
        return cnt;
    }
};