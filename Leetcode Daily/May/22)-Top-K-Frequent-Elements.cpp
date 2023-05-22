// 347. Top K Frequent Elements.
    

// Approach

// a) Do map le lo ek val, cnt aur ek cnt, vals
// b) Ek cnt ki kao values ho sakti hai isliye vector liya

// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
        
//         map<int,int> mp1;
//         map<int,vector<int>> mp2;
        
//         for(auto &it:nums) mp1[it]++;
        
//         for(auto &it:mp1){
//             int val=it.first;
//             int cnt=it.second;
            
//             mp2[-cnt].push_back(val);
//         }
        
//         vector<int> ans;
        
//         for(auto &it:mp2){
//             for(auto &val:it.second){
//                 if(k!=0) ans.push_back(val);
//                 else return ans;
//                 k--;
//             }
//         }
//         return ans;
//     }
// };


// O(nlogk) solution

// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
        
//         priority_queue<pair<int,int>> pq; // max heap
        
//         unordered_map<int,int> mp;
        
//         // O(n)
//         for(auto &it:nums) mp[it]++;
        
        
//         // Sirf k values rakhni hai
        
//         // O(nlog(k))
//         for(auto &it:mp){
//             int cnt=it.second;
//             int val=it.first;
            
//             pq.push({-cnt,val}); // - dalne se min heap ho gaya
            
//             if(pq.size()>k) pq.pop(); // agar k se badha iska matlab sabse chota jo tha uski koi value ni ab usko hata do
//         }
        
//         vector<int> ans;
//         // O(klogk)
//         while(!pq.empty()){
//             ans.push_back(pq.top().second);
//             pq.pop();
//         }
        
//         return ans;
//     }
// };


// Optimised Approach O(n)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // Bucket sort
        // [val,cnt] ka map banao aur ab ek vector<vector<int>> jiska index cnt honge
        
        // At max kitna cnt ho sakta hai? ( equal to size of the array)
        
        int n=nums.size();
        vector<vector<int>> buckets(n+1);
        
        unordered_map<int,int> mp;
        
        // O(n)
        for(auto &it:nums) mp[it]++;
        
        // O(n)
        for(auto &it:mp){
            int cnt=it.second;
            int val=it.first;
            
            buckets[cnt].push_back(val);
        }
        
        // Max cnt to peeche hoga to reverse the buckets or iterate from the back
        
        int i=n;
        vector<int> ans;
        
        // O(n+n) (In all jitne elements hai utna hi to loop chalega)
        for(;i>=0;i--){
            for(auto &it:buckets[i]){
                if(k!=0){
                    ans.push_back(it);
                    k--;
                }else return ans;
            }
        }
        return ans;
    }
};