class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<pair<int,double>> adj[n];
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            double wt=succProb[i];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        priority_queue<pair<double,int>> pq; // maxHeap
        vector<double> maxProb(n,0);
        
        pq.push({1,start});
        maxProb[start]=1;
        
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            
            int node=it.second;
            double prob=it.first;
            
            for(auto &it:adj[node]){
                int child=it.first;
                double probability=it.second;
                
                if(prob*probability>maxProb[child]){
                    maxProb[child]=prob*probability;
                    pq.push({maxProb[child],child});
                }
            }
        }
        return maxProb[end];
    }
};