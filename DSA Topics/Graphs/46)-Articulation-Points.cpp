class Solution {
  private:
  // AP array ek to sorted order ke liye use kar rahe
  // Doosra same node kai components ke liye Ap ho skat hai isliye repition na ho to aisa kar lo
  void dfs(int node,vector<int> adj[],int parent,vector<int> &discovery,vector<int> &low,int time,vector<int> &AP,vector<int> &visited){
        
        // lets visit this node
        visited[node]=1;
        discovery[node]=low[node]=time++;
        int noOfChildren=0; // for checking if the first node can be AP
        
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
                
                noOfChildren++;
                dfs(child,adj,node,discovery,low,time,AP,visited);
                low[node]=min(low[node],low[child]);
                
                // after the dfs come back i will question you
                // If i remove myself my child will you be able to reach someone above me?
                // The answer would be yes if discovery[mine]>low[myChild] -> he can reach someone above me
                // If the answer is no it means it is a bridge
                if(discovery[node]<=low[child] && parent!=-1){ // we got our AP
                    AP[node]=1;
                }
            }
        }
        
        if(parent==-1 && noOfChildren>1){ // means more than one child or edge hai
            AP[node]=1;
        }
    }
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        
        vector<int> discovery(V);
        vector<int> low(V); // lowest of adjacent nodes apart from parent
        vector<int> AP(V,0);
        vector<int> visited(V,0);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(0,adj,-1,discovery,low,1,AP,visited); // {node,adj,parent,discovery,low,time,ans,visited}
            }
        }
    
        vector<int> ans;
        
        for(int i=0;i<V;i++){
            if(AP[i]==1) ans.push_back(i);
        }
        
        if(ans.size()==0) return {-1};
        return ans;
    }
};