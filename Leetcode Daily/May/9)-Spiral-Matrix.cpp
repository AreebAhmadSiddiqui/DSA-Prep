54. Spiral Matrix


Given an m x n matrix, return all elements of the matrix in spiral order.

// Approach

a) Sab to pata hi hai lekin
b) Bas ek cheez zarur check karna ki i<m*n hai ki ni agar ni hai to address not found index out of bound aega


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        
        vector<int> ans(m*n,0);
        
        int rowStart=0,rowEnd=m-1;
        int colStart=0,colEnd=n-1;
        
        int i=0;
        while(i<m*n){
            
            
            for(int col=colStart;col<=colEnd;col++){
                ans[i++]=matrix[rowStart][col];
            }
            
            for(int row=rowStart+1;row<=rowEnd;row++){
                ans[i++]=matrix[row][colEnd];
            }
            
            for(int col=colEnd-1;i<m*n && col>=colStart;col--){
                ans[i++]=matrix[rowEnd][col];
            }
            
            for(int row=rowEnd-1;i<m*n && row>rowStart;row--){
                ans[i++]=matrix[row][colStart];
            }
            
            rowStart++;
            rowEnd--;
            colStart++;
            colEnd--;
            
        }
        return ans;
    }
};