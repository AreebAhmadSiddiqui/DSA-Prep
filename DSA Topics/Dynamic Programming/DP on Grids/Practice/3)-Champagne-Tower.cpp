// Ismein tabulation wala code hi likhna warna band baj jaegi

// Man lo sara paani dp[0][0] pe hai aur extra hoga to left wale aur right wale main batega bas yahi karna hai math.min kyun liya because ho sakta hai us paani mein idhar udhar se paani ake 1 se zyada ikhata ho jae to spill ho jaega na lekin tum spill to kiye ni isliye min of 1 ya agar usse kam hai koi tab to wahi le lo
class Solution {
private:
//     double help(int row,int col,double poured,int qRow,int qGlass,vector<vector<double>> &dp){
//         if(row>qRow || col>qRow || col>qGlass) return 0;
        
//         if(row==qRow && col==qGlass) return poured;
        
//         if(dp[row][col]!=-1) return dp[row][col];
        
        
//         double left=max(0.0,help(row+1,col,(poured-1)/2.0,qRow,qGlass,dp));
//         double right=max(0.0,help(row+1,col+1,(poured-1)/2.0,qRow,qGlass,dp));
        
//         return dp[row][col]=left+right;
        
//     }
    
//         double help(int row,int col,double poured,vector<vector<double>> &dp){
//         if(row<0 || col<0 || col>row) return 0;
        
//         if(row==0 && col==0) return poured;
        
//         if(dp[row][col]!=-1) return dp[row][col];
        
        
//         double left=max(0.0,help(row-1,col-1,poured,dp)-1)/2.0;
//         double right=max(0.0,help(row-1,col,poured,dp)-1)/2.0;
        
//         return dp[row][col]=left+right;
        
//     }
    
    
    double tabulation(double poured,int query_row,int query_glass){
        
        vector<vector<double>> dp(query_row+2,vector<double> (query_row+2,0.0));
        
        // Lets Assume All the water is on dp[0][0] cell
        dp[0][0]=poured;
        
        for(int i=0;i<=query_row;i++){
            for(int j=0;j<=i;j++){
                double portion=(dp[i][j]-1.0)/2.0;
                
                double left=max(0.0,portion);
                double right=max(0.0,portion);
                
                dp[i+1][j]+=left;
                dp[i+1][j+1]+=right;
            }
        }
        return min(1.0,dp[query_row][query_glass]);
    }
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        
        // vector<vector<double>> dp(query_row+1,vector<double> (query_row+1,-1));
        // return min(1.0,help(query_row,query_glass,poured,dp));
        // return min(1.0,help(0,0,poured,query_row,query_glass,dp));
        
        return tabulation(poured,query_row,query_glass);
    }
};