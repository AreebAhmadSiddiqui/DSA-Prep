class Solution {
private:
    void dfs(int node,vector<int> adj[],int parent,vector<int> &discovery,vector<int> &low,int time,vector<vector<int>> &ans,vector<int> &visited){
        
        // lets visit this node
        visited[node]=1;
        discovery[node]=low[node]=time++;
        
        //Iterate the neighbors
        for(auto child:adj[node]){
            
            // simply return
            if(child==parent){
                continue;
            }
            // Back edge
            if(visited[child]==1){
                // main tere tak pahunch sakta
                low[node]=min(low[node],discovery[child]);
            }
            else{ // Not Visited Case Do the DFS
                
                dfs(child,adj,node,discovery,low,time,ans,visited);
                low[node]=min(low[node],low[child]);
                
                // after the dfs come back i will question you
                // If i remove you my child will you be able to reach me somehow?
                // The answer would be yes if discovery[mine]>=low[myChild] -> he can reach me or someone above me
                // If the answer is no it means it is a bridge
                if(discovery[node]<low[child]){ // we got our bridge
                    ans.push_back({node,child});
                }
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        
        for(auto vec:connections){
            int u=vec[0];
            int v=vec[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> discovery(n,0);
        vector<int> low(n,0); // lowest of adjacent nodes apart from parent
        vector<vector<int>> ans;
        vector<int> visited(n,0);
        
        dfs(0,adj,0,discovery,low,1,ans,visited); // {node,adj,parent,discovery,low,time,ans,visited}
        
        return ans;
    }
};