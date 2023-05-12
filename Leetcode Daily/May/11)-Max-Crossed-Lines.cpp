1035. Uncrossed Lines

You are given two integer arrays nums1 and nums2. We write the integers of nums1 and nums2 (in the order they are given) on two separate horizontal lines.

We may draw connecting lines: a straight line connecting two numbers nums1[i] and nums2[j] such that:

nums1[i] == nums2[j], and
the line we draw does not intersect any other connecting (non-horizontal) line.
Note that a connecting line cannot intersect even at the endpoints (i.e., each number can only belong to one connecting line).

Return the maximum number of connecting lines we can draw in this way.
    
    
class Solution {
private:
//     int help(int i,int j,int n,int m,vector<int>& nums1, vector<int>& nums2,vector<vector<int>> &dp) {
//         if(i==n || j==m) return 0;
        
//         if(dp[i][j]!=-1) return dp[i][j];
//         int match=0;
//         int notMatch=0;
//         if(nums1[i]==nums2[j]){
//             match=1+help(i+1,j+1,n,m,nums1,nums2,dp);
//         }else{
//             notMatch=max(help(i,j+1,n,m,nums1,nums2,dp),help(i+1,j,n,m,nums1,nums2,dp));
//         }
//         return dp[i][j]=max(match,notMatch);
//     }
//     int tabulation(vector<int>& nums1, vector<int>& nums2) {
//         int n=nums1.size();
//         int m=nums2.size();
        
//         vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        
//         // Base Case
//         // Already Done
        
//         for(int i=n-1;i>=0;i--){
            
//             for(int j=m-1;j>=0;j--){
//                 int match=0;
//                 int notMatch=0;
//                 if(nums1[i]==nums2[j]) match=1+dp[i+1][j+1];
//                 else notMatch=max(dp[i][j+1],dp[i+1][j]);
//                 dp[i][j]=max(match,notMatch);
//             }
//         }
//         return dp[0][0];
//     }
    int spaceOptimisation(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        
        vector<int> prev(m+1,0),curr(m+1,0);
        
        // Base Case
        // Already Done
        
        for(int i=n-1;i>=0;i--){
            
            for(int j=m-1;j>=0;j--){
                int match=0;
                int notMatch=0;
                if(nums1[i]==nums2[j]) match=1+prev[j+1];
                else notMatch=max(curr[j+1],prev[j]);
                curr[j]=max(match,notMatch);
            }
            prev=curr;
        }
        return prev[0];
    }
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
//         int n=nums1.size();
//         int m=nums2.size();
        
//         vector<vector<int>> dp(n,vector<int> (m,-1));
//         return help(0,0,n,m,nums1,nums2,dp);
        // return tabulation(nums1,nums2);
        return spaceOptimisation(nums1,nums2);
    }
};