// Number of Ways to Form a Target String Given a Dictionary

// You are given a list of strings of the same length words and a string target.

// Your task is to form target using the given words under the following rules:

// target should be formed from left to right.
// To form the ith character (0-indexed) of target, you can choose the kth character of the jth string in words if target[i] = words[j][k].
// Once you use the kth character of the jth string of words, you can no longer use the xth character of any string in words where x <= k. In other words, all characters to the left of or at index k become unusuable for every string.
// Repeat the process until you form the string target.
// Notice that you can use multiple characters from the same string in words provided the conditions above are met.

// Return the number of ways to form target from words. Since the answer may be too large, return it modulo 109 + 7.
    
    
// Approach

// a) f(i,j) se solve karna hai i words[k][i] hai matlab i th column of any word aur j target ka hai
// b) tu dekho ki is ith col pe main khada hun to kaunsr word mein ith index jth char ke baraba hai 
// c) agar baraba hai to i+1,j+1 warna doosra dhoodne
// d) aur main seedhe seedhe is ith col ko hi skip kar dun

// e) O(n3) se O(n2) lane ke liye tum har words mein jao aur dekho ki ith index pe sare cha kitni baar a rhae hai bas o(1) mein cnt a jaega aur use multiply kar dena to answer a jaega

 class Solution {
private:
    int mod=1000000007;
    // O(n3)
//     int help(int i,int j,vector<string>& words, string &target,vector<vector<int>> &dp,vector<vector<int>> cntArr){
//         if(j>=target.size()) return 1;
        
//         if(i>=words[0].size()) return 0;
        
//         if(dp[i][j]!=-1) return dp[i][j];
        
//         int pick=0,notPick=0;
//         for(int k=0;k<words.size();k++){
//             if(words[k][i]==target[j]){
//                 pick=(pick%mod+help(i+1,j+1,words,target,dp)%mod)%mod;
//             }
//         }
//         notPick=help(i+1,j,words,target,dp)%mod;
        
//         return (pick+notPick)%mod;
//     }
    
    // O(n2)
    int help(int i,int j,vector<string>& words, string &target,vector<vector<int>> &dp,vector<vector<int>> cntArr){
        if(j>=target.size()) return 1;
        
        if(i>=words[0].size()) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ways=cntArr[i][target[j]-'a'];
        int pick=(ways*1ll*help(i+1,j+1,words,target,dp,cntArr)%mod);
        int notPick=help(i+1,j,words,target,dp,cntArr)%mod;
        
        return dp[i][j]=(pick+notPick)%mod;
    }
    
    
     // O(n2)
//     int tabulation(vector<string>& words, string target) {
        
//         int n=words[0].size();
//         int m=target.size();
        
//         vector<vector<int>> cntArr(n,vector<int> (26,0));
        
//         // Precompute is jth col mein character kitni baar aya, ye nikaloge to seedhe multiply kar denge ek loop bach jaega
        
//         for(auto &word:words){
//             for(int j=0;j<word.size();j++){
//                 cntArr[j][word[j]-'a']++;
//             }
//         }
        
//         vector<vector<int>> dp(n+2,vector<int> (m+2,0));
        
//         // Base Case
//         for(int i=0;i<=n+1;i++) dp[i][m]=1;
        
//         for(int i=n-1;i>=0;i--){
//             for(int j=m-1;j>=0;j--){
                
//                 int ways=cntArr[i][target[j]-'a'];
                
//                 int pick=ways*1ll*dp[i+1][j+1]%mod;
//                 int notPick=dp[i+1][j]%mod;
                
//                 dp[i][j]=(pick+notPick)%mod;
//             }
//         }
        
//         return dp[0][0];
//     }
     
     
     int spaceOptimisation(vector<string>& words, string target) {
        
        int n=words[0].size();
        int m=target.size();
        
        vector<vector<int>> cntArr(n,vector<int> (26,0));
        
        // Precompute is jth col mein character kitni baar aya, ye nikaloge to seedhe multiply kar denge ek loop bach jaega
        
        for(auto &word:words){
            for(int j=0;j<word.size();j++){
                cntArr[j][word[j]-'a']++;
            }
        }
        
        vector<int> prev(m+2,0),curr(m+2,0);
        
        // Base Case
        prev[m]=1;
        
        for(int i=n-1;i>=0;i--){
            curr[m]=1;
            for(int j=m-1;j>=0;j--){
                
                int ways=cntArr[i][target[j]-'a'];
                
                int pick=ways*1ll*prev[j+1]%mod;
                int notPick=prev[j]%mod;
                
                curr[j]=(pick+notPick)%mod;
            }
            prev=curr;
        }
        
        return prev[0];
    }
public:
    int numWays(vector<string>& words, string target) {
        
//         vector<vector<int>> dp(words[0].size(),vector<int> (target.size(),-1));
        
//         vector<vector<int>> cntArr(words[0].size(),vector<int> (26,0));
        
//         // Precompute kar lo Is jth col mein character kitni baar aya to seedhe multiply kar denge ek loop bach jaega
        
//         for(auto &word:words){
//             for(int j=0;j<word.size();j++){
//                 cntArr[j][word[j]-'a']++;
//             }
//         }
//         return help(0,0,words,target,dp,cntArr);
        // return tabulation(words,target);
        return spaceOptimisation(words,target);
    }
};