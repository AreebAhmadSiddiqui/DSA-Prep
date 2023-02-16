class Solution {
    
    TC-> O(N+N+E)
    SC-> O(N+N+N)
    private:
    bool dfsCycleCheck(int node,vector<int> adj[],vector<int> &vis,vector<int> &dfsVis){
        vis[node]=1;
        dfsVis[node]=1;
        
        for(auto child:adj[node]){
            // Not visited
            if(!vis[child]){
                if(dfsCycleCheck(child,adj,vis,dfsVis)){
                    return true;
                }
            }
            // Visited but also path visited return true
            else if(dfsVis[child]){
                return true;
            }
        }
        
        dfsVis[node]=0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        
        vector<int> vis(V,0);
        vector<int> dfsVis(V,0);
       for(int i=0;i<V;i++){
           if(!vis[i]){
               if(dfsCycleCheck(i,adj,vis,dfsVis)) return true;
           }
       }
       return false;
    }
};


TC-> O(N+N+E)
SC-> O(N+N)
BUT With SIngle array

STEPS

a) Jab bhi DFS visit karna to vis ko 2 kardena aur jab dfs vis khatam ho jae to vis ko 1 kardena
class Solution {
    
    private:
    bool dfsCycleCheck(int node,vector<int> adj[],vector<int> &vis){
        vis[node]=2;
        
        for(auto child:adj[node]){
            if(!vis[child]){
                if(dfsCycleCheck(child,adj,vis)){
                    return true;
                }
            }
            else if(vis[child]==2){
                return true;
            }
        }
        
        vis[node]=1;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        
        vector<int> vis(V,0);
       for(int i=0;i<V;i++){
           if(!vis[i]){
               if(dfsCycleCheck(i,adj,vis)) return true;
           }
       }
       return false;
    }
};