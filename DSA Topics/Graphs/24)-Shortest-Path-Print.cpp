class Solution {
  public:

  TC-> ElogV+V
  Sc-> O(V+V+V)
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        
        // Create Adjacency List
        vector<pair<int,int>> adj[n+1];
        for(auto vec:edges){
            int u=vec[0];
            int v=vec[1];
            int wt=vec[2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        priority_queue<pair<int,int>> pq; 
        
        pq.push({0,-1});
        vector<int> dis(n+1,1e9);
        dis[1]=0;
        
        // For getting the previous -> element kahan se aya main
        vector<int> parent(n+1,0);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        
        while(!pq.empty()){
            int node=-pq.top().second;
            int dist=-pq.top().first;
            pq.pop();
            
            for(auto vec:adj[node]){
                int child=vec.first;
                int childWt=vec.second;
                
                if(dist+childWt<dis[child]){
                    dis[child]=dist+childWt;
                    pq.push({-dis[child],-child});
                    parent[child]=node;
                }
            }
        }
        
        if(parent[n]==n) return {-1};
        
        vector<int> ans;
        int i=n;
        while(parent[i]!=i){
            ans.push_back(i);
            i=parent[i];
        }
        ans.push_back(i);
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};