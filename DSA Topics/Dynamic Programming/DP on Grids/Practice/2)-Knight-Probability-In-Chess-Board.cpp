Knight Probability in Chessboard
Are dekho ye ekdum normal total probability jaisa hai

tum usmein kya karte the tree banate the na
    
       1/8
      /
   1/8 
  /   \ 1/8
    
1                    Total prob kya hota tha 1*1/8*1/8+1*1/8*1/8+1*1/8*1/8+1*1/8*1/8 (to wahi to kar rahe ki 1/8 common le lo aur baaki total                                probability jitni ae usko 1/8 se multi kar do same as 8 se divide)
        1/8
  \   /
   1/8
      \
        1/8
class Solution {
private:
    bool isValid(int row,int col,int n){
        return row>=0 && col>=0 && row<n && col<n;
    }
//     double help(int row,int col,int n,int k,vector<vector<vector<double>>> &dp){
//         int dx[]={-2,-1,1,2,2,1,-1,-2};
//         int dy[]={-1,-2,-2,-1,1,2,2,1};
        
//         if(row<0 || col<0 || row>=n || col>=n) return 0;
        
//         if(k==0) return 1;
        
//         if(dp[row][col][k]!=-1) return dp[row][col][k];
//         double ans=0;
//         for(int del=0;del<8;del++){
//             ans+=help(row+dx[del],col+dy[del],n,k-1,dp);
//         }
        
//         return dp[row][col][k]=ans/8;
//     }
//     double tabulation(int n, int kk, int row, int column){
//         int dx[]={-2,-1,1,2,2,1,-1,-2};
//         int dy[]={-1,-2,-2,-1,1,2,2,1};
        
//         vector<vector<vector<double>>> dp(kk+1,vector<vector<double>> (n,vector<double> (n,0)));
        
//         // Base Case
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 dp[i][j][0]=1;
//             }
//         }
        
//         for(int k=1;k<=kk;k++){
//             for(int row=0;row<n;row++){
//                 for(int col=0;col<n;col++){
//                     double ans=0;
//                     for(int del=0;del<8;del++){
//                         int newRow=row+dx[del];
//                         int newCol=col+dy[del];
                      
//                         if(isValid(newRow,newCol,n)){
//                             ans+=dp[k-1][newRow][newCol];
//                         }
//                     }
//                     dp[k][row][col]=ans/8;
//                 }
//             }
//         }
        
//         return dp[kk][row][column];
//     }
    double spaceOptimisation(int n, int kk, int row, int column){
        int dx[]={-2,-1,1,2,2,1,-1,-2};
        int dy[]={-1,-2,-2,-1,1,2,2,1};
        
        vector<vector<double>> curr(n,vector<double> (n,0)),prev(n,vector<double> (n,0));
        
        // Base Case
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                prev[i][j]=1;
            }
        }
        
        for(int k=1;k<=kk;k++){
            for(int row=0;row<n;row++){
                for(int col=0;col<n;col++){
                    double ans=0;
                    for(int del=0;del<8;del++){
                        int newRow=row+dx[del];
                        int newCol=col+dy[del];
                      
                        if(isValid(newRow,newCol,n)){
                            ans+=prev[newRow][newCol];
                        }
                    }
                    curr[row][col]=ans/8;
                }
            }
            prev=curr;
        }
        
        return prev[row][column];
    }
public:
    double knightProbability(int n, int k, int row, int column) {
        
       
        // return help(row,column,n,k,dp);
        // return tabulation(n,k,row,column);
        return spaceOptimisation(n,k,row,column);
    }
};