// Asan sa tha lekin

// tabulation main maxMoves ka loop pehle row aur col ke andar tha to error a raha tha lekin jab row col ko uske andar kiya to sahi ho gaya
// Hamesha aisa hi karna jo ek se kam ho raha ho use bahar rakhna kyunki wo further space optimised bhi ho sakta hai okkk
// Ye wala bhi ho jaega dhyaan se dekho
// Aur ye dekho tumhara base case hai maxMoves pe dependent isliye tum use pehle hi rakho row and col se pehle

576. Out of Boundary Paths
There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.

Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it modulo 109 + 7.

 
class Solution {
private:
    int mod=1000000007;
    bool isOutOfBoundary(int row,int col,int m,int n){
        return row<0 || col<0 || row>=m || col>=n;
    }
//     int help(int row,int col,int m,int n,int maxMove,vector<vector<vector<int>>> &dp){
        
//         if(isOutOfBoundary(row,col,m,n)) return 1;
        
//         int dx[]={-1,1,0,0};
//         int dy[]={0,0,-1,1};
        
//         if(dp[row][col][maxMove]!=-1) return dp[row][col][maxMove];
        
//         int moves=0;
//         if(maxMove!=0){
//             for(int i=0;i<4;i++){
//                 int newRow=row+dx[i];
//                 int newCol=col+dy[i];
                
//                 moves=(moves%mod+help(newRow,newCol,m,n,maxMove-1,dp)%mod)%mod;
//             }
//         }
        
//         return dp[row][col][maxMove]=moves;
//     }
    int tabulation(int m,int n,int maxMoves,int startRow,int startColumn){
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>> (n+1,vector<int> (maxMoves+1,0)));
        
        // Base Case
        // Will Handle Explicitly
        
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        
        for(int maxMove=1;maxMove<=maxMoves;maxMove++){
            for(int row=0;row<m;row++){
                for(int col=0;col<n;col++){
                    int moves=0;
                    for(int i=0;i<4;i++){
                        int newRow=row+dx[i];
                        int newCol=col+dy[i];

                        if(isOutOfBoundary(newRow,newCol,m,n)) moves+=1;
                        else moves=(moves%mod+dp[newRow][newCol][maxMove-1]%mod)%mod;
                    }
                    dp[row][col][maxMove]=moves;
                }
            }
        }
        
        return dp[startRow][startColumn][maxMoves];
   }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        // vector<vector<vector<int>>> dp(m,vector<vector<int>> (n,vector<int> (maxMove+1,-1)));
        // return help(startRow,startColumn,m,n,maxMove,dp);
        
        return tabulation(m,n,maxMove,startRow,startColumn);
    }
};