// Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

// The distance between two adjacent cells is 1.


// Steps

// 1) Pehle sare zeros ka queue main dal lo
// 2) Ab unse jo 1 sate honge wo 1 distance pe honge to
// 3) Fir un sab 1 distance wale 1 ko dalo queue mein aur fir dhondho one jo 2 distance par honge
// 4) similary aisa karte jao

// Mashallah ye code mera tha striver ne kai vectors aur queue main pair pair liya tha


// TC-> O(n*m*4)
// SC->O(n*m)
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int n=mat.size();
        int m=mat[0].size();
        
        queue<pair<int,int>> q;
        vector<vector<int>> ans(n,vector<int> (m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        
        while(!q.empty()){
            
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
            for(int del=0;del<4;del++){
                int newRow=row+dx[del];
                int newCol=col+dy[del];
                
                // If valid
                if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && mat[newRow][newCol]==1 && 
                   ans[newRow][newCol]==0){ // iska matlab hai ki ye wala 1 abhi update ni hua hai to update kar sakte agar update ho gaya hoga to use fir se change ni karna hai
                    q.push({newRow,newCol});
                    ans[newRow][newCol]=ans[row][col]+1; // is row,col ka anser pichle wale row,col ke ans + 1 hoga kyunki ek hi step to badh rahe ham to aise kar diya
                }
            }
        }
        
        return ans;
    }