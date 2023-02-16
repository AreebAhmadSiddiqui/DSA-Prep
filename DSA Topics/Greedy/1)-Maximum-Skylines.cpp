// Dekho hame maximum answer batana hai to simple max of row le lo aur max of col le lo kyunki unse zyada to bhadega ni to jo bhi un do max mein se min ho usmein se grid[i][j] subtract kar do
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid.size();
        
        vector<int> rowMax(n,0),colMax(n,0);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                rowMax[i]=max(rowMax[i],grid[i][j]);
                colMax[i]=max(colMax[i],grid[j][i]);
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans+=min(rowMax[i],colMax[j])-grid[i][j];
            }
        }
        
        return ans;
    }
};