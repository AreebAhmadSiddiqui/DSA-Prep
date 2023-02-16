class DSU{
	vector<int> rank,parent,size;

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
    Steps

    a) Hamlog sirf extra edges ko hi use kar sakte hai aut min kitne edges chahiye hongi c components ko join karne main c-1
    b) to nikalo ki extra edges kitni hai agar wo c-1 se zyada ya barabar hai to c-1 print kardo otherwise -1
    // O(E+V)
    int Solve(int n, vector<vector<int>>& edge) {
        
        int noOfComponents=0,noOfRedundantEdges=0; // Redundant edges mean if they are removed from a graph the graph is still connected i.e cycle wali edges jisse cycle bane
        // As we have to remove edges from graph then connect this is why we do this otherwise to it was simple cntComp-1
        DSU ds(n);
        for(auto vec:edge){
            int u=vec[0];
            int v=vec[1];
            
            if(ds.findPar(u)!=ds.findPar(v)){
                ds.unionBySize(u,v);
            }
            else{
                noOfRedundantEdges++; // cycle wali edges
            }
        }
        
        for(int i=0;i<n;i++){
            if(ds.findPar(i)==i){
                noOfComponents++;
            }
        }
        
        int edgesRequired=noOfComponents-1;  // no of components -1 because bhai agar 4 compo hai to 3 edge hi to lagengi mini connect karne main
        return noOfRedundantEdges>=edgesRequired ? edgesRequired : -1;
    }
};