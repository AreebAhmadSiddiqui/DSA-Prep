2661. First Completely Painted Row or Column


You are given a 0-indexed integer array arr, and an m x n integer matrix mat. arr and mat both contain all the integers in the range [1, m * n].

Go through each index i in arr starting from index 0 and paint the cell in mat containing the integer arr[i].

Return the smallest index i at which either a row or a column will be completely painted in mat.
    


Preprocess the values

aur jaise hi row aur col ki value poori ho jae reutrn kardo
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        vector<int> rows(n+1,0);
        vector<int> cols(m+1,0);
        
        unordered_map<int,pair<int,int>> mp;
        
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                mp[mat[row][col]]={row,col};
            }
        }
        
        int size=arr.size();
        for(int i=0;i<size;i++){
            int val=arr[i];
            
            int row=mp[val].first;
            int col=mp[val].second;
            
            rows[row]++;
            cols[col]++;
            
            if(rows[row]==m || cols[col]==n) return i;
        }
        return size;
    }
};