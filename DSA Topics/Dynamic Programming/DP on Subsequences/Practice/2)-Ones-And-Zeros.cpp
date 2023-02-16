474. Ones and Zeroes

You are given an array of binary strings strs and two integers m and n.

Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.

A set x is a subset of a set y if all elements of x are also elements of y.


vector<int> &cnt ye maine for any i what is the cnt of 1 in it precompute kar liya basically taki complexity bdhae na

class Solution {
private:
//     int help(int i,vector<string> &strs,int m,int n,vector<vector<vector<int>>> &dp,vector<int> &cnt){
        
//         if(i==strs.size()) return 0;
        
//         if(dp[i][m][n]!=-1) return dp[i][m][n];
//         int pick=0,notPick=0;
        
        
//         int oneCnt=cnt[i],zeroCnt=strs[i].size()-cnt[i];
        
//         if(zeroCnt<=m && oneCnt<=n) pick=1+help(i+1,strs,m-zeroCnt,n-oneCnt,dp,cnt);
//         notPick=0+help(i+1,strs,m,n,dp,cnt);
        
//         return dp[i][m][n]=max(pick,notPick);
//     }
    
//     int tabulation(vector<string>& strs, int mm, int nn) {
//         vector<vector<vector<int>>> dp(strs.size()+1,vector<vector<int>> (mm+1,vector<int> (nn+1,0)));
//         vector<int> cntOnes(strs.size(),0);
        
//         for(int i=0;i<strs.size();i++){
//             for(auto &it:strs[i]){
//                 cntOnes[i]+=it=='1';
//             }
//         }
        
//         // Base Case
//         // Done Already
        
//         for(int i=strs.size()-1;i>=0;i--){
//             for(int m=0;m<=mm;m++){
//                 for(int n=0;n<=nn;n++){
//                     int pick=0,notPick=0;
                    
//                     int oneCnt=cntOnes[i],zeroCnt=strs[i].size()-cntOnes[i];
                    
//                     if(zeroCnt<=m && oneCnt<=n) pick=1+dp[i+1][m-zeroCnt][n-oneCnt];
//                     notPick=0+dp[i+1][m][n];

//                     dp[i][m][n]=max(pick,notPick);
//                 }
//             }
//         }
//         return dp[0][mm][nn];
//     }
    int spaceOptimisation(vector<string>& strs, int mm, int nn) {
        vector<vector<int>> prev(mm+1,vector<int> (nn+1,0)),curr(mm+1,vector<int> (nn+1,0));
        vector<int> cntOnes(strs.size(),0);
        
        for(int i=0;i<strs.size();i++){
            for(auto &it:strs[i]){
                cntOnes[i]+=it=='1';
            }
        }
        
        // Base Case
        // Done Already
        
        for(int i=strs.size()-1;i>=0;i--){
            for(int m=0;m<=mm;m++){
                for(int n=0;n<=nn;n++){
                    int pick=0,notPick=0;
                    
                    int oneCnt=cntOnes[i],zeroCnt=strs[i].size()-cntOnes[i];
                    
                    if(zeroCnt<=m && oneCnt<=n) pick=1+prev[m-zeroCnt][n-oneCnt];
                    notPick=0+prev[m][n];

                    curr[m][n]=max(pick,notPick);
                }
            }
            prev=curr;
        }
        return prev[mm][nn];
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        
//         vector<vector<vector<int>>> dp(strs.size()+1,vector<vector<int>> (m+1,vector<int> (n+1,-1)));
//         vector<int> cntOnes(strs.size(),0);
        
//         for(int i=0;i<strs.size();i++){
//             for(auto &it:strs[i]){
//                 cntOnes[i]+=it=='1';
//             }
//         }
//         return help(0,strs,m,n,dp,cntOnes);
        
        // return tabulation(strs,m,n);
        return spaceOptimisation(strs,m,n);
    }
};