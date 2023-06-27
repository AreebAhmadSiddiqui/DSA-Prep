class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        // Brute is for every integer in nums1 pair it with every integer in nums2 and get the k min sum
        
        // O(m*nlog(m*n))
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> minHeap;
        
        int n=nums1.size();
        int m=nums2.size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                minHeap.push({nums1[i]+nums2[j],{nums1[i],nums2[j]}});
            }
        }
        
        vector<vector<int>> ans;
        
        while(k-- && !minHeap.empty()){
            auto it=minHeap.top();
            minHeap.pop();
            
            ans.push_back({it.second.first,it.second.second});
        }
        
        return ans;
        
        
        
        // Optimal


        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        
        int n=nums1.size();
        int m=nums2.size();
        
        // Minimum to pehla wala hi hoga
        
        map<pair<int,int>,int> mp;
        pq.push({nums1[0]+nums2[0],{0,0}});
        mp[{0,0}]=1;
        vector<vector<int>> ans;
        
        // O(min(k,m*n)log(m*n))
        while(k-- && !pq.empty()){
            auto it=pq.top();
            pq.pop();
            int val1=it.first;
            int i=it.second.first;
            int j=it.second.second;

            ans.push_back({nums1[i],nums2[j]});
            
            if(i+1<n && mp.find({i+1,j})==mp.end()){
                mp[{i+1,j}]=1;
                pq.push({nums1[i+1]+nums2[j],{i+1,j}});
            }
            
            if(j+1<m && mp.find({i,j+1})==mp.end()){
                mp[{i,j+1}]=1;
                pq.push({nums1[i]+nums2[j+1],{i,j+1}});
            }
        }
        return ans;
    }
};