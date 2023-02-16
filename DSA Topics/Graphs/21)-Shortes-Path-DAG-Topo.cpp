class Solution {
  private:

  STEPS

  a) Find the toposort order
  b) Then solve for the distance problem 
  c) In topo sort the left most element are the ones who cannot be reached by anyone while the right ones can be reached by left ones
  d) When we get this order of toposort we are sure that any vertex i can only be visited by the nodes left most to it ans because of the toposort ham unhe already include kar chuke honge so we will get our answer
  
  void dfs(int node,vector<pair<int,int>> adj[],vector<int> &vis,stack<int> &st){
      vis[node]=1;
      
      for(auto vec:adj[node]){
          int child=vec.first;
          int wt=vec.second;
          
          if(!vis[child]){
              dfs(child,adj,vis,st);
          }
      }
      
      st.push(node);
  }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        
        // Create The Adjacency List
        vector<pair<int,int>> adj[N];
        for(auto vec: edges){
            adj[vec[0]].push_back({vec[1],vec[2]});
        }
        
        // Get toposort O(N+E)
        stack<int> st;
        vector<int> vis(N,0);
        dfs(0,adj,vis,st);
        
        
        vector<int> dis(N,INT_MAX);
        dis[0]=0;
        //Get the distances
        
        // O(N+E)
        while(!st.empty()){
            int node=st.top();
            st.pop();
            
            for(auto vec:adj[node]){
              int child=vec.first;
              int wt=vec.second;
              
              if(dis[node]+wt<dis[child]){
                  dis[child]=dis[node]+wt;
              }
            }
        }
        
        for(int i=0;i<N;i++){
            if(dis[i]==INT_MAX) dis[i]=-1;
        }
        
        return dis;
    }
};