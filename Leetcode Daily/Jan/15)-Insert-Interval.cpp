class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        int n=intervals.size();
        int currStart=newInterval[0],currEnd=newInterval[1];
        
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            
            int start=intervals[i][0];
            int end=intervals[i][1];
            
            // Case 1
            // New Interval is before the range of the given interval
            
            if(currEnd<start){
                ans.push_back({currStart,currEnd});
                currStart=start;
                currEnd=end;
            }
            
            // Case 2 
            // New Interval is in after the range of the given interval
            else if(currStart>end){
                ans.push_back({start,end});
            }
            
            // case 3
            // New interval is in between the range
            else{
                currStart=min(currStart,start);    
                currEnd=max(currEnd,end);
            }
        }
        ans.push_back({currStart,currEnd});
        return ans;
    }
};