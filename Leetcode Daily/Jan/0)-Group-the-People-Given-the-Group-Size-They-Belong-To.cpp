class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& num) {
        unordered_map<int,vector<int>> mp;
        
        vector<vector<int>> ans;
        
        for(int i=0;i<num.size();i++){
            mp[num[i]].push_back(i);
            
            if(mp[num[i]].size()==num[i]){ // it is full so we need to create another group
                ans.push_back(mp[num[i]]);
                mp.erase(num[i]);
            }
        }
        return ans;
    }
};