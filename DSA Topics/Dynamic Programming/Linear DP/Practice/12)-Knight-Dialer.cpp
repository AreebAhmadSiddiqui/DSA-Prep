class Solution {
public:
    int mod=1000000007;
private:
    bool isValid(int row,int col,int n){
        if(row==3 && col==0 || row==3 && col==2) return false;
        return row>=0 && row<=3 && col>=0 && col<=2;
    }
    
//     int help(int row,int col,int n,vector<vector<vector<int>>> &dp){
//         int dx[]={-1,-2,-2,-1,1,2,2,1};
//         int dy[]={2,1,-1,-2,-2,-1,1,2};
//         if(!isValid(row,col,n)) return 0;
        
//         if(n==0) return 1;
        
//         if(dp[n][row][col]!=-1) return dp[n][row][col];
//         int ways=0;
//         for(int del=0;del<8;del++){
//             int newRow=row+dx[del];
//             int newCol=col+dy[del];
//             ways=(ways%mod+help(newRow,newCol,n-1,dp)%mod)%mod;
//         }
        
//         return dp[n][row][col]=ways;
//     }
    
//     int tabulation(int nn){
        
//         int dx[]={-1,-2,-2,-1,1,2,2,1};
//         int dy[]={2,1,-1,-2,-2,-1,1,2};
//         vector<vector<vector<int>>> dp(nn+1,vector<vector<int>> (4,vector<int> (3,0)));
        
//         // Base Case
//         for(int i=0;i<4;i++){
//             for(int j=0;j<3;j++){
//                 if(isValid(i,j,nn)) dp[0][i][j]=1; // ye condition likha ni likha tha to dimmaag kharab hua are bhai row 3 col 0 and 1 invalid hai na isliye
//             }
//         }
        
//         for(int n=1;n<=nn-1;n++){
//             for(int row=0;row<4;row++){
//                 for(int col=0;col<3;col++){
//                     int ways=0;
//                     for(int del=0;del<8;del++){
//                         int newRow=row+dx[del];
//                         int newCol=col+dy[del];
//                         if(isValid(newRow,newCol,n)) ways=(ways%mod+dp[n-1][newRow][newCol]%mod)%mod;
//                     }
//                     if(isValid(row,col,nn)) dp[n][row][col]=ways; // ye condition likha ni likha tha to dimmaag kharab hua are bhai row 3 col 0 and 1 invalid hai na isliye
//                 }
//             }
//         }
        
        
//         int sum=0;
//         for(int i=0;i<4;i++){
//             for(int j=0;j<3;j++){
//                 sum=(sum%mod+dp[nn-1][i][j]%mod)%mod;
//             }
//         }
        
//         return sum;
//     }
    int spaceOptimised(int nn){
        
        int dx[]={-1,-2,-2,-1,1,2,2,1};
        int dy[]={2,1,-1,-2,-2,-1,1,2};
        vector<vector<int>> curr(4,vector<int> (3,0)),prev(4,vector<int> (3,0));
        
        // Base Case
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                if(isValid(i,j,nn)) prev[i][j]=1; // ye condition likha ni likha tha to dimmaag kharab hua are bhai row 3 col 0 and 1 invalid hai na isliye
            }
        }
        
        for(int n=1;n<=nn-1;n++){
            for(int row=0;row<4;row++){
                for(int col=0;col<3;col++){
                    int ways=0;
                    for(int del=0;del<8;del++){
                        int newRow=row+dx[del];
                        int newCol=col+dy[del];
                        if(isValid(newRow,newCol,n)) ways=(ways%mod+prev[newRow][newCol]%mod)%mod;
                    }
                    if(isValid(row,col,nn)) curr[row][col]=ways; // ye condition likha ni likha tha to dimmaag kharab hua are bhai row 3 col 0 and 1 invalid hai na isliye
                }
            }
            prev=curr;
        }
        
        
        int sum=0;
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                sum=(sum%mod+prev[i][j]%mod)%mod;
            }
        }
        
        return sum;
    }
public:
    int knightDialer(int n) {
        
        // vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (4,vector<int> (3,-1)));
        // int sum=0;
        // for(int i=0;i<4;i++){
        //     for(int j=0;j<3;j++){
        //         sum=(sum%mod+help(i,j,n-1,dp)%mod)%mod;
        //     }
        // }
        // return sum;
        
        // return tabulation(n);
        return spaceOptimised(n);
    }
};