228. Summary Ranges

You are given a sorted unique integer array nums.

A range [a,b] is the set of all integers from a to b (inclusive).

Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

Each range [a,b] in the list should be output as:

"a->b" if a != b
"a" if a == b


class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        vector<string> ans;
        int n=nums.size();
        int i=0;
        while(i<n){
            
            int s=nums[i];
            
            while(i+1<n && nums[i]+1==nums[i+1]) i++;
            
            int e=nums[i];
            
            if(s!=e) ans.push_back(to_string(s)+"->"+to_string(e));
            else ans.push_back(to_string(s));
            
            i++;
        }
        return ans;
    }
};