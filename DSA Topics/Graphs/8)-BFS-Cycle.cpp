// TC-> (N+N+2E)
// SC-> (N+N)
    bool detect(int i,vector<int> &vis,vector<int> adj[]){
        queue<pair<int,int>> q; // {node,parent}
           q.push({i,-1});
           vis[i]=1;
           while(!q.empty()){
               int node=q.front().first;
               int parent=q.front().second;
               q.pop();
               for(auto child:adj[node]){
                   if(vis[child] && child!=parent){ // already visited but is not the parent
                       return true;
                   }
                   if(!vis[child]){
                       q.push({child,node});
                       vis[child]=1;
                    }
                }
           }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
       
       vector<int> vis(V,0);
      
      
       for(int i=0;i<V;i++){ 
           
           if(!vis[i]){
               if(detect(i,vis,adj)) return true;
           }
       }
       return false;
    }