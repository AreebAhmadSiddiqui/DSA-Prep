TC-> O(V+E)
SC-> O(V+V)


class Solution
{
    private:
    
    void dfs(int node,vector<int> adj[],vector<int> &vis,stack<int> &st){
        vis[node]=1;
        
        // Visit the neighbours
        
        for(auto child:adj[node]){
            if(!vis[child]){
                dfs(child,adj,vis,st);
            }
        }
        
        st.push(node);
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    
	   vector<int> vis(V,0),ans;
	   stack<int> st;
	   for(int i=0;i<V;i++){
	       if(!vis[i]){
	           dfs(i,adj,vis,st);
	       }
	   }
	   
	   while(!st.empty()){
	       ans.push_back(st.top());
	       st.pop();
	   }
	   
	   return ans;
	}
};