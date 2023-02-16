class Solution {
public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
//         multiset<int> pq;
        
//         int n=nums.size();
//         int i=0;
//         int j=0;
//         vector<int> ans;
//         while(j<n){
            
//             pq.insert(-nums[j]);
            
//             if(pq.size()==k){ // now i need the maxi
//                 int maxi=*pq.begin();
//                 ans.push_back(-maxi);
                
                
//                 // now i need to move my window so remove the i th guy
//                 pq.erase(pq.find(-nums[i]));
//                 i++;
//             }
//             j++;
//         }
//         return ans;
//     }
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> dq;
        int i=0;
        int j=0;
        vector<int> ans;
        
        // O(N+N) for inserting and removing once
        while(j<nums.size()){
            
            while(!dq.empty() && nums[dq.back()]<nums[j]){// remove those
                dq.pop_back();
            }
            
            // push this index
            dq.push_back(j);
            
            if(j-i+1==k){ // window reached
                ans.push_back(nums[dq.front()]);
                
                //Now we need to remove the ith element if it is in dequeue it should be at the front
                if(!dq.empty() && dq.front()==i){
                    dq.pop_front();
                }
                i++;
            }
            j++;
        }
        
        return ans;
    }
};