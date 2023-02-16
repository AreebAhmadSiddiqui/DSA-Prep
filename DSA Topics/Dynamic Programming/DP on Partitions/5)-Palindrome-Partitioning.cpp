class Solution {
private:
    bool isPali(int i,int j,string &s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int f(int i,string &s,int n,vector<int> &dp){
        if(i==n) return 0;
        
        if(dp[i]!=-1) return dp[i];
        
        int ans=INT_MAX;
        for(int j=i;j<n;j++){
            if(isPali(i,j,s)){
                int partitions=1+f(j+1,s,n,dp); 
                ans=min(ans,partitions);
            }
        }
        
        return dp[i]=ans;
    }
    int tabulation(string &s){
        
        vector<int> dp(s.size()+1,0);
        
        // Base Case
        dp[s.size()]=0;
        
        for(int i=s.size()-1;i>=0;i--){
            int ans=INT_MAX;
            for(int j=s.size()-1;j>=i;j--){
                 if(isPali(i,j,s)){
                    int partitions=1+dp[j+1]; 
                    ans=min(ans,partitions);
                }
            }
            dp[i]=ans;
        }
        
        return dp[0];
    }
public:
    int minCut(string s) {
        
//         vector<int> dp(s.size(),-1);
//         return f(0,s,s.size(),dp)-1; // for removin that extra cut at i==n
        
        return tabulation(s)-1;
        
    }
};