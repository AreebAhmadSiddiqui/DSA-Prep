2215. Find the Difference of Two Arrays

Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:

answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
Note that the integers in the lists may be returned in any order.
    
    
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp1,mp2;
        
        for(auto &it:nums1) mp1[it]++;
        
        for(auto &it:nums2) mp2[it]++;
        
        vector<vector<int>> ans(2,vector<int> ());
        
        for(auto &it:mp1){
            int val=it.first;
            if(!mp2[val]){
                ans[0].push_back(val);
            }
        }
        
        for(auto &it:mp2){
            int val=it.first;
            if(!mp1[val]){
                ans[1].push_back(val);
            }
        }
        
        return ans;
    }
};