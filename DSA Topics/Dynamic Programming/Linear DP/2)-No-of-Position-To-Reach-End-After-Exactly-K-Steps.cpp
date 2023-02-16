class Solution {
    int mod=1e9+7;
private:

    // O(3000*k)
    int help(int i,int endPos,int k,vector<vector<int>> &dp){
        if(k==0){
            // see if reach our endPos or not
            if(i==endPos) return 1;
            return 0;
        }
        
        if(dp[i+1000][k]!=-1) return dp[i+1000][k];
        
        int left=help(i-1,endPos,k-1,dp)%mod;
        int right=help(i+1,endPos,k-1,dp)%mod;
        
        return dp[i+1000][k]=(left+right)%mod;
    }
public:
    int numberOfWays(int startPos, int endPos, int k) {
        
        // As range is from (-1000,2000)
        vector<vector<int>> dp(3000,vector<int> (k+1,-1));
        return help(startPos,endPos,k,dp);
    
    }
};