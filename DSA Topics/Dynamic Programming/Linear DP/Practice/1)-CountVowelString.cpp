// Given an integer n, return the number of strings of length n that consist only of vowels (a, e, i, o, u) and are lexicographically sorted.

// A string s is lexicographically sorted if for all valid i, s[i] is the same as or comes before s[i+1] in the alphabet.

// Ways find karna hai to simply return 1 aur 0 wala kar diya

// aur yahan nums mein sorted order mein a e i o u le liya aur bas normal dp laga diya


class Solution {
int help(int i,int n,vector<char> &chars,int maxAlpha,vector<vector<int>> &dp){
    if(i==n) return maxAlpha==0;
    
    if(dp[i][maxAlpha]!=-1) return dp[i][maxAlpha];
    
    int pick=0,notPick=0;
    if(maxAlpha>0) pick=help(i,n,chars,maxAlpha-1,dp);
    notPick=help(i+1,n,chars,maxAlpha,dp);
    
    return dp[i][maxAlpha]=pick+notPick;
}
int tabulation(int n){
    
    vector<vector<int>> dp(6,vector<int> (n+1,0));
    vector<char> characters={'a','e','i','o','u'};

    // Base Case
    dp[5][0]=1;
    
    for(int i=4;i>=0;i--){
        for(int maxAlpha=0;maxAlpha<=n;maxAlpha++){
            int pick=0,notPick=0;
            if(maxAlpha>0) pick=dp[i][maxAlpha-1];
            notPick=dp[i+1][maxAlpha];

            dp[i][maxAlpha]=pick+notPick;
        }
    }
    
    return dp[0][n];
}
int spaceOptimisation(int n){
    
    vector<int> front(n+1,0),curr(n+1,0);
    vector<char> characters={'a','e','i','o','u'};

    // Base Case
    front[0]=1;
    
    for(int i=4;i>=0;i--){
        for(int maxAlpha=0;maxAlpha<=n;maxAlpha++){
            int pick=0,notPick=0;
            if(maxAlpha>0) pick=curr[maxAlpha-1];
            notPick=front[maxAlpha];

            curr[maxAlpha]=pick+notPick;
            front=curr;
        }
    }
    
    return front[n];
}    
public:
    int countVowelStrings(int n) {
        
//         vector<vector<int>> dp(5,vector<int> (n+1,-1));
//         vector<char> characters={'a','e','i','o','u'};
        
//         return help(0,5,characters,n,dp);
        
        // return tabulation(n);
        return spaceOptimisation(n);
    }
};