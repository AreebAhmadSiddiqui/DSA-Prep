//

// Ismein ham base case ko alag se ni likh rahe the dhyan se
// Grid ke sare questions mein base case ko loop ke andar rakhna warna error ata hai i dont know why

class Solution {
private:
    int help(int i,int j,vector<vector<int>> &dp){
        if(i<0 || j<0) return 0;
        
        if(i==0 && j==0) return 1;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int left=help(i,j-1,dp);
        int up=help(i-1,j,dp);
        
        return dp[i][j]=left+up;
    }
    int tabulation(int m,int n){
        
        vector<vector<int>> dp(m,vector<int> (n,0));
        
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                 
                 if(i==0 && j==0) dp[i][j]=1;
                 else{
                     int left=0,up=0;
                     if(j>0) left=dp[i][j-1];
                     if(i>0) up= dp[i-1][j];
                        dp[i][j]=left+up;
                 }
            }
        }
        
        return dp[m-1][n-1];
    }
    
    int spaceOptimisation(int m,int n){
        
        vector<int> prev(n,0),curr(n,0);
        
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                 
                 if(i==0 && j==0) curr[j]=1;
                 else{
                     int left=0,up=0;
                     if(j>0) left=curr[j-1];
                     if(i>0) up= prev[j];
                        curr[j]=left+up;
                 }
            }
            prev=curr;
        }
        
        return prev[n-1];
    }
    
    int mostOptimal(int m,int n){
        
        int N=m-1+n-1;
        int r=min(m-1,n-1);
        
        double ans=1;
        for(int i=1;i<=r;i++){
            ans=ans*(N-r+i)/i;
        }
        
        return (int)ans;
    }
public:
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m,vector<int> (n,-1));
        // return help(m-1,n-1,dp);
        
        // return tabulation(m,n);
        // return spaceOptimisation(m,n);
           return mostOptimal(m,n);
    }
};