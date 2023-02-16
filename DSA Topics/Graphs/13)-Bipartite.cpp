// BFS


// TC-> V+V+2E
// SC-> V
class Solution {
private:
    bool bfs(int i,vector<int> adj[],vector<int> &colored){
        queue<int> q;
        q.push(i);
        colored[i]=1; // start with 1
        
        // Traverse its neighbours
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto child:adj[node]){
                if(colored[child]==colored[node]) {// cant color it
                    return false;
                }
                if(colored[child]==-1){ // color ni hai to color kar do
                    q.push(child);
                    colored[child]=1-colored[node];
                }
            }
        }
        return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> colored(V,-1);
	    for(int i=0;i<V;i++){
	        if(colored[i]==-1){ // not coloured do a bfs
	            if(!bfs(i,adj,colored)){ // 0 is initial color
	                return false;
	            }
	        }
	    }
	    return true;
	}

};



// DFS


// TC-> V+V+2E
// SC-> V
class Solution {
private:
    bool dfs(int node,vector<int> adj[],vector<int> &colored,int color){
        
        colored[node]=color; // start with 1
        
        // Traverse its neighbours
            for(auto child:adj[node]){
                if(colored[child]==colored[node]) {// cant color it
                    return false;
                }
                if(colored[child]==-1){ // color ni hai to color kar do
                   if(!dfs(child,adj,colored,1-color)) return false;
                }
            }
        return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> colored(V,-1);
	    for(int i=0;i<V;i++){
	        if(colored[i]==-1){ // not coloured do a bfs
	            if(!dfs(i,adj,colored,1)){ // 1 is initial color
	                return false;
	            }
	        }
	    }
	    return true;
	}

};