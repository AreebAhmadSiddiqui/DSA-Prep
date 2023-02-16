class Solution {
public:

    // TC-> O(N /* outer loop */ + N+2*N /*Inner Loop*/)
    // SC-> O(n+n)
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int cnt=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                queue<int> q;
                q.push(i);
                vis[i] = 1;
                while (!q.empty())
                {
                    int node = q.front();
                    q.pop();
                    for (int j=0;j<n;j++)
                    {
                        if (isConnected[node][j]==1 && !vis[j])
                        {
                            vis[j] = 1;
                            q.push(j);
                        }
                    }
                }
            }
        }
        return cnt;
    }


    
};

// One DSU solution is also there
class DSU{
	vector<int> rank;
	vector<int> parent;
	vector<int> size;

public:
	DSU(int n){
		rank.resize(n+1,0);
		parent.resize(n+1,0);
		size.resize(n+1,1);

		for(int i=0;i<=n;i++){
			parent[i]=i;
		}
	}

	int findPar(int u){
		if(u==parent[u]){
			return u;
		}
		return parent[u]=findPar(parent[u]);
	}

	void unionByRank(int u,int v){
		u=findPar(u);
		v=findPar(v);

		if(u==v) return;
		// u is chota than v add it to v
		if(rank[u]<rank[v]){
			parent[u]=v;
		}
		else if(rank[u]>rank[v]){
			parent[v]=u;
		}
		else{
			parent[v]=u;
			rank[u]++;
		}
	}

	void unionBySize(int u,int v){
		u=findPar(u);
		v=findPar(v);

		if(u==v) return;
		
		// u is chota than v add it to v
		if(size[u]<size[v]){
			parent[u]=v;
			size[v]+=size[u];
		}
		else{
			parent[v]=u;
			size[u]+=size[v];	
		}
	}
};
class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        DSU ds(V);
        
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==1){
                    int u=i+1;
                    int v=j+1;
                    ds.unionByRank(u,v);
                }
            }
        }
        
        int cnt=0;
        for(int i=0;i<V;i++){
            int u=i+1;
            
            // Alag Component
            if(ds.findPar(u)==u){
                cnt++;
            }
        }
        return cnt;
    }
};