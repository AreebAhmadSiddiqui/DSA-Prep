Range Sum Query 2D - Immutable

Given a 2D matrix matrix, handle multiple queries of the following type:

Calculate the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
Implement the NumMatrix class:

NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
You must design an algorithm where sumRegion works on O(1) time complexity.
    
 
class NumMatrix {
    vector<vector<int>> prefixSum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        prefixSum.resize(n,vector<int> (m,0));
        // row,col ko bottom right corner mante hue yahan tak ka sum store kar lo
        
        prefixSum[0][0]=matrix[0][0];
        
        for(int i=1;i<n;i++) prefixSum[i][0]=prefixSum[i-1][0]+matrix[i][0];
        for(int j=1;j<m;j++) prefixSum[0][j]=prefixSum[0][j-1]+matrix[0][j];
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                
                // i-1,j-1 do baar add ho gaya isliye subtract kardo
                prefixSum[i][j]=matrix[i][j]+prefixSum[i-1][j]+prefixSum[i][j-1]-prefixSum[i-1][j-1];
            }
        }
    }
    int getValue(int row,int col){
        if(row<0 || col<0) return 0;
        return prefixSum[row][col];
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        // int ans=prefixSum[row2][col2]-prefixSum[row2][col1-1]-prefixSum[row1-1][col2]+prefixSum[row1-1][col1-1];
        int ans=getValue(row2,col2)-getValue(row2,col1-1)-getValue(row1-1,col2)+getValue(row1-1,col1-1);
        return ans;
    }
};
