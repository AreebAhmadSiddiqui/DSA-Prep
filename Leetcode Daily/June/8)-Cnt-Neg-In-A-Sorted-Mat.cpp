
1351. Count Negative Numbers in a Sorted Matrix

Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.
    
    
class Solution {
private:
    int getNeg(vector<int> &nums){
        
        int n=nums.size();
        int s=0;
        int e=n-1;
        
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]<0){
                ans=mid;
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return ans==-1 ? 0 : n-ans;
    }
public:
    
    // O(nm) -> Simply Traverse and Find the answer
    // O(mlogn) -> Binary Search
    
    // O(m+n) -> Linear Traversal ( Use the Given Hint that coumns are sorted too -> If the ith row has a neg element at index x then the the next row will never have the first neg at index grrater than x common sense ( either at <=x) )
    int countNegatives(vector<vector<int>>& grid) {
        
//         int cnt=0;
        
//         int m=grid.size();
//         for(int i=0;i<m;i++){
//             cnt+=getNeg(grid[i]);
//         }
        
//         return cnt;
        
        int cnt=0;
        
        int m=grid.size();
        int n=grid[0].size();
        int j=n-1;
        
        for(int i=0;i<m;i++){
            while(j>=0 && grid[i][j]<0){
                j--;
            }
            cnt+=(j<0) ? n : j==n-1 ? 0 : n-j-1;
        }
        
        return cnt;
    }
};