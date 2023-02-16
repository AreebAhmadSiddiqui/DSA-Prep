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
struct Node{
    int u,v,wt;
    Node(int _u,int _v,int _wt){
        u=_u;
        v=_v;
        wt=_wt;
    }
};
bool comp(Node a,Node b){
    return a.wt<b.wt;
}
class Solution
{
    TC-> O(V+E+ElogE+E*4*alpha*2) //do baar kar rahe na
    SC-> O(E+V+V)
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<Node> edges;
        for(int i=0;i<V;i++){
            for(auto it:adj[i])
                edges.push_back(Node(i,it[0],it[1]));  // {u,v,wt};
        }
        
        //ElogE
        sort(edges.begin(),edges.end(),comp);
        
        // Object created
        DSU ds(V);
        int sum=0;
        for(auto it:edges){
            int u=it.u;
            int v=it.v;
            int wt=it.wt;
            if(ds.findPar(u)!=ds.findPar(v)){
                sum+=wt;
                ds.unionByRank(u,v);
            }
        }
        
        return sum;
    }
};