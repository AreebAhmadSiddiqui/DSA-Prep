class Solution {
private:
    int help(int screen,int clipBoard,int n,vector<vector<int>> &dp){
        
        if(screen>n) return 1e9;
        
        if(screen==n) return 0;
        
        if(dp[screen][clipBoard]!=-1) return dp[screen][clipBoard];
        
        if(clipBoard==screen) return dp[screen][clipBoard]=1+help(screen+clipBoard,clipBoard,n,dp);
        
        int copy=help(screen,screen,n,dp);
        int paste=help(screen+clipBoard,clipBoard,n,dp);
        
        return dp[screen][clipBoard]=1+min(copy,paste);
    }
public:
    int minSteps(int n) {
        
        if(n==1) return 0;
        
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        return 1+help(1,1,n,dp); // Ye sabse pehli choice ke liye kiya hai jab screen par ek A hoga aur clipboard par 0 ( ham log infinite loop mein fas rahe the wahan isliye ek baar copy mar lo aur clipboard par 1 value dal do bas)
        
    }
};