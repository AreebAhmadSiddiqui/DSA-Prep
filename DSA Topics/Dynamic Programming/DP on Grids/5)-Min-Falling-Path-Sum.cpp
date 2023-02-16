class Solution {
private:
    int help(int i,int j,vector<vector<int>>& matrix,int n,vector<vector<int>>& dp){
        
        if(j<0 || j>=n) return 1e9;

        if(i==0) return matrix[i][j];
        
        if(dp[i][j]!=-1) return dp[i][j];

        int up=help(i-1,j,matrix,n,dp);
        int leftDiagUp=help(i-1,j-1,matrix,n,dp);
        int rightDiagUp=help(i-1,j+1,matrix,n,dp);

        return dp[i][j]=min(up,min(leftDiagUp,rightDiagUp))+matrix[i][j];
    }
    int tabu(vector<vector<int>>& matrix){
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        
        for(int j=0;j<n;j++){
            dp[0][j]=matrix[0][j];
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                
                int up=1e9,leftDiagUp=1e9,rightDiagUp=1e9;
                if(i>0) up=dp[i-1][j];
                if(j>0) leftDiagUp=dp[i-1][j-1];
                if(j+1<n) rightDiagUp=dp[i-1][j+1];

                dp[i][j]=min(up,min(leftDiagUp,rightDiagUp))+matrix[i][j];
            }
        }
        
        int ans=INT_MAX;
        for(int j=0;j<n;j++){
            ans=min(ans,dp[n-1][j]);
        }
        
        return ans;
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        // int n=matrix.size();
        // vector<vector<int>> dp(n,vector<int> (n,-1));
        
        // int ans=INT_MAX;
        // for(int j=0;j<n;j++){
        //     ans=min(ans,help(n-1,j,matrix,n,dp));
        // }
        // return ans;
        
        return tabu(matrix);
    }
};