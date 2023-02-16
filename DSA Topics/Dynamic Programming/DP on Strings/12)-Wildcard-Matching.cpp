class Solution {
private:
    bool help(int i,int j,string &s,string &p,vector<vector<int>> &dp){
        // Base Case
        if(i==0 || j==0){
            if(i==0 && j==0) return true;
            
            if(i==0){
                for(int k=1;k<=j;k++){
                    if(p[k-1]!='*') return false;
                }
                return true;
            }
            
            if(j==0){
                return false;
            }
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i-1]==p[j-1] || p[j-1]=='?'){
            return dp[i][j]=help(i-1,j-1,s,p,dp);
        }
        if(p[j-1]=='*'){
            return dp[i][j]=help(i-1,j,s,p,dp) || help(i,j-1,s,p,dp);
        }
        return dp[i][j]=false; // no match
    }
    bool tabulation(string &s,string &p){
        vector<vector<int>> dp(s.size()+1,vector<int> (p.size()+1,0));
        
        // Base Case
        
        dp[0][0]=true;
        
        for(int j=0;j<=p.size();j++){
            int flag=0;
            for(int k=1;k<=j;k++){
                 if(p[k-1]!='*'){
                     flag=1;
                     break;
                 }
            }
            if(flag==1) dp[0][j]=false;
            else dp[0][j]=true;
        }
        
        for(int i=1;i<=s.size();i++) dp[i][0]=false;
        
        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=p.size();j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?'){
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*'){
                    dp[i][j]=dp[i-1][j] || dp[i][j-1];
                }
                else dp[i][j]=false; // no match
            }
        }
        
        return dp[s.size()][p.size()];
    }
    bool spaceOptimisation(string &s,string &p){
        vector<int> prev(p.size()+1,0),curr(p.size()+1,0);
        
        // Base Case
        
        prev[0]=true;
        
        for(int j=0;j<=p.size();j++){
            int flag=0;
            for(int k=1;k<=j;k++){
                 if(p[k-1]!='*'){
                     flag=1;
                     break;
                 }
            }
            if(flag==1) prev[j]=false;
            else prev[j]=true;
        }
        
        // for(int i=1;i<=s.size();i++) dp[i][0]=false;
        
        for(int i=1;i<=s.size();i++){
            curr[0]=false;
            for(int j=1;j<=p.size();j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?'){
                    curr[j]=prev[j-1];
                }
                else if(p[j-1]=='*'){
                    curr[j]=prev[j] || curr[j-1];
                }
                else curr[j]=false; // no match
            }
            prev=curr;
        }
        
        return prev[p.size()];
    }
public:
    bool isMatch(string s, string p) {
        
        // vector<vector<int>> dp(s.size()+1,vector<int> (p.size()+1,-1));
        // return help(s.size(),p.size(),s,p,dp);
        
        // return tabulation(s,p);
        return spaceOptimisation(s,p);
    }
};