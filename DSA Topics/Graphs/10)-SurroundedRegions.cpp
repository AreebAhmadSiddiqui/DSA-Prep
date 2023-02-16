

// STEPS

// 1) Dekho jo bhi zeros boundary wale zeros se connected honge wo regions mein ni a sakte 
// 2) to bas un boundary zeros ko nikalo aur dfs bfs karke unse jude hue zeros ko -1 ya invalid jo bhi hai kar do
// 3) Fir loop laga dena aur check karna agar ye zero invalid ni hai to surround ho jaega aur x bana dena


TC-> O( n + m + n*m * 4)
SC-> O(n*m)
class Solution {
    
    private:
    void dfs(int row,int col,vector<vector<char>>& board,vector<vector<int>> &vis){
        
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        
       
        vis[row][col]=-1;
        
        for(int i=0;i<4;i++){
            
            int newRow=row+dx[i];
            int newCol=col+dy[i];
            if(newRow>=0 && newRow<board.size() && newCol>=0 && newCol<board[0].size() && board[newRow][newCol]=='O' && !vis[newRow][newCol]){
                dfs(newRow,newCol,board,vis);
            }
        }
        
    }
public:
    void solve(vector<vector<char>>& board) {
        
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> vis(m,vector<int> (n,0));
        
        // Get the boundary zeros
        
        for(int j=0;j<n;j++){
            // First row
            if(!vis[0][j] && board[0][j]=='O'){
                dfs(0,j,board,vis);
            }
            
            // Last row
            if(!vis[m-1][j] && board[m-1][j]=='O'){
                dfs(m-1,j,board,vis);
            }
        }
        
        
        for(int i=0;i<m;i++){
            // First col
            if(!vis[i][0] && board[i][0]=='O'){
                dfs(i,0,board,vis);
            }
            
            // Last col
            if(!vis[i][n-1] && board[i][n-1]=='O'){
                dfs(i,n-1,board,vis);
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]!=-1 && board[i][j]=='O') { // This zero can be surrounded 
                    board[i][j]='X';
                }
            }
        }
    }
};