Word Search

Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.
    
    
class Solution {
private:
    bool isValid(int row,int col,vector<vector<char>>& board, string &word,int i,vector<vector<int>> &vis){
        int m=board.size();
        int n=board[0].size();
        
        return row>=0 && row<m && col>=0 && col<n && board[row][col]==word[i] && !vis[row][col];
    }
    bool help(int i,int row,int col,vector<vector<char>>& board, string &word,vector<vector<int>> &vis){
        
        if(i==word.size()) return true;
        
        
        if(!isValid(row,col,board,word,i,vis)) return false;
        
        int m=board.size();
        int n=board[0].size();
        
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        
        vis[row][col]=1;
        for(int del=0;del<4;del++){

            int newRow=row+dx[del];
            int newCol=col+dy[del];

            if(help(i+1,newRow,newCol,board,word,vis)) return true;
        }
        
        vis[row][col]=0;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                vector<vector<int>> vis(m,vector<int> (n,0));
                if(help(0,i,j,board,word,vis)) return true;
            }
        }
        return false;
    }
};