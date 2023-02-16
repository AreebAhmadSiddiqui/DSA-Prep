class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        // Create The Adjacency List
        vector<pair<int,double>> adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        
        priority_queue<pair<double,int>> pq; // {prob,node};
        vector<double> vis(n,0);
        
        pq.push({1,start});
        vis[start]=1;
        
        // O(ElogV)
        while(!pq.empty()){
            int node=pq.top().second;
            double currProb=pq.top().first;
            pq.pop();
            for(auto vec:adj[node]){
                int child=vec.first;
                double prob=vec.second;
                if(prob*currProb>vis[child]){
                    vis[child]=prob*currProb;
                    pq.push({vis[child],child});
                }
            }
        }
        
        return vis[end];
    }
};