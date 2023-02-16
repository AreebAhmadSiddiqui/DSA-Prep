// You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

// We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

 
1 ---- > 2    with time 1
1---> 3 with time 1
3----> 2 with time 1

2 ka minimum time to 1 se jane wala hi hai na isliye shortest path algo lag gaya yahan pe (tumne sari nodes ka min time to nikla liya lekin ab ans to wo wahi node hogi jismein sabse zyada time laga taki kyunki utne time mein hi sari nodes par signal jaega)
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<pair<int,int>> adj[n+1];
        
        for(auto &vec:times){
            int u=vec[0];
            int v=vec[1];
            int time=vec[2];
            
            adj[u].push_back({v,time});
        }
        
        vector<int> timeArray(n+1,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        timeArray[k]=0;
        
        // ElogV
        while(!pq.empty()){
            int node=pq.top().second;
            int time=pq.top().first;
            
            pq.pop();
            
            // Visit neighbours
            for(auto &it:adj[node]){
                int child=it.first;
                int childTime=it.second;
                
                if(time+childTime<timeArray[child]){
                    timeArray[child]=time+childTime;
                    pq.push({timeArray[child],child});
                }
            }
        }
        
        // Min Time would be the max time taken by any node
        int ans=INT_MIN;
        for(int i=1;i<=n;i++){
            // cout<<i<<" "<<timeArray[i]<<" "<<'\n';
            if(timeArray[i]==1e9) return -1;
            ans=max(ans,timeArray[i]);
        }
        
        return ans;
    }
};