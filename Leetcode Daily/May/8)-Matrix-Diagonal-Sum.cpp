Matrix Diagonal Sum

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        
        int n=mat.size();
        int sum=0;
        
        for(int i=0;i<n;i++){
            sum+= n&1 && i==n/2 ? mat[i][i] : mat[i][i]+mat[n-i-1][i];
        }
        return sum;
    }
};