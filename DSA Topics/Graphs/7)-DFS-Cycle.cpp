// TC-> (N+N+2E)
// SC-> (N+N)
    bool dfs(int node,vector<int> &vis,vector<int> adj[],int parent){
        vis[node]=1;
        
        for(auto child:adj[node]){
            if(vis[child] && child!=parent){ // already visited but is not the parent
                return true;
            }
            if(!vis[child]){
                if(dfs(child,vis,adj,node)) return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
       
       vector<int> vis(V,0);
       
       for(int i=0;i<V;i++){ 
           if(!vis[i]){
               if(dfs(i,vis,adj,-1)) return true;
           }
       }
       return false;
    }