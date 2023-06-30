// 1970. Last Day Where You Can Still Cross

// There is a 1-based binary matrix where 0 represents land and 1 represents water. You are given integers row and col representing the number of rows and columns in the matrix, respectively.

// Initially on day 0, the entire matrix is land. However, each day a new cell becomes flooded with water. You are given a 1-based 2D array cells, where cells[i] = [ri, ci] represents that on the ith day, the cell on the rith row and cith column (1-based coordinates) will be covered with water (i.e., changed to 1).

// You want to find the last day that it is possible to walk from the top to the bottom by only walking on land cells. You can start from any cell in the top row and end at any cell in the bottom row. You can only travel in the four cardinal directions (left, right, up, and down).

// Return the last day where it is possible to walk from the top to the bottom by only walking on land cells.
    

// Approach

// a) Straigforward solution Linear Search

// b) TLE aya to seedhe Binary Search
#include<bits/stdc++.h>
class Solution {
private:
    bool isValid(int row,int col,int n,int m,vector<vector<int>> &grid){
        return row>=0 && row<n && col>=0 && col<m && grid[row][col]==0;
    }
    bool isPossible(int day,int row,int col,vector<vector<int>> &cells){
        
        vector<vector<int>> grid(row,vector<int> (col,0));
        for(int i=0;i<day;i++){
            grid[cells[i][0]-1][cells[i][1]-1]=1;
        }
        
        queue<pair<int,int>> q;
        
        for(int j=0;j<col;j++){
            if(grid[0][j]==0) {
                q.push({0,j});
                grid[0][j]=1;
            }
        }
        
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            
            int r=it.first;
            int c=it.second;
            
            if(r==row-1) return true;
            
            for(int del=0;del<4;del++){
                int nRow=r+dx[del];
                int nCol=c+dy[del];
                
                if(!isValid(nRow,nCol,row,col,grid)) continue;
                
                grid[nRow][nCol]=1;
                q.push({nRow,nCol});
            }
        }
        
        return false;
    }
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        
        int n=cells.size();
        
        
        // O(n*(row*col))
//         for(int i=n;i>=1;i--){
            
//             if(isPossible(i,row,col,cells)){
//                 return i;
//             }
//         }
        
        
        // O(log(n)*(row*col))
        int start=1,end=n;
        
        int ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(isPossible(mid,row,col,cells)){
                ans=mid;
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
        return ans;
    }
};