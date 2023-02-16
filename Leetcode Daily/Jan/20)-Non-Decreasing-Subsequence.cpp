class Solution {
private:
    void help(int i,int j,vector<int> &nums,set<vector<int>> &ans,vector<int> ds){
        if(i==nums.size()){
            if(ds.size()>1) ans.insert(ds);
                return;
        }
        
        if(j==-1 || nums[j]<=nums[i]){
            ds.push_back(nums[i]);
            help(i+1,i,nums,ans,ds);
            ds.pop_back();
        }
        help(i+1,j,nums,ans,ds);
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        set<vector<int>> temp;
        vector<int> ds;
        
        help(0,-1,nums,temp,ds);
        
        vector<vector<int>> ans;
        
        for(auto &vec:temp){
            ans.push_back(vec);
        }
        return ans;
    }
};