class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        int rowStart=0;
        int rowEnd=n-1;
        int colStart=0;
        int colEnd=n-1;
        
        vector<vector<int>> ans(n,vector<int> (n,0));
        int i=1;
        while(i<=n*n){
            for(int col=colStart;col<=colEnd;col++){
                ans[rowStart][col]=i++;
            }
            for(int row=rowStart+1;row<=rowEnd;row++){
                ans[row][colEnd]=i++;
            }
            for(int col=colEnd-1;col>=colStart;col--){
                ans[rowEnd][col]=i++;
            }
            for(int row=rowEnd-1;row>rowStart;row--){
                ans[row][colStart]=i++;
            }
            rowStart++;
            colStart++;
            rowEnd--;
            colEnd--;
        }
        return ans;
    }
};