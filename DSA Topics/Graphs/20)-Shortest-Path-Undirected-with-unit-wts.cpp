class Solution {
  public:
    
    // Why bfs?

    // Because ismein ham queue ka use kar rahe hai aur bfs mein ham log plus one distanc epar hi jate to ye karna asan hai


    // TC-> O(n+2E)
    // SC-> O(N+2E+N)
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        
        
        // Adjacency List Created
        vector<int> adj[N];
        for(auto vec:edges){
            adj[vec[0]].push_back(vec[1]);
            adj[vec[1]].push_back(vec[0]);
        }
        
        vector<int> dist(N,INT_MAX);
        
        // BFS
        queue<int> q; // {node,dist}
        q.push(src); //src
        dist[src]=0;
        
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            for(auto child:adj[node]){
               if(dist[node]+1<dist[child]){
                   q.push(child);
                   dist[child]=dist[node]+1;
               }
            }
        }
        
        for(int i=0;i<N;i++){
            if(dist[i]==INT_MAX) dist[i]=-1;
        }
        return dist;
    }
};