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
int main() {

#ifdef ONLINEJUDGE
	freopen("inputf.in", "r", stdin); //can need to change file . this one for taking input
	freopen("outputf.in", "w", stdout); // this one for output
#endif
	DSU ds(7);

	// ds.unionByRank(1,2);
	// ds.unionByRank(2,3);
	// ds.unionByRank(4,5);
	// ds.unionByRank(6,7);
	// ds.unionByRank(5,6);

	// // are 3 and 7 same compo
	// if(ds.findPar(3)==ds.findPar(7)){
	// 	cout<<"Same\n";
	// }
	// else{
	// 	cout<<"Not same\n";
	// }

	// ds.unionByRank(3,7);

	// // are 3 and 7 same compo
	// if(ds.findPar(3)==ds.findPar(7)){
	// 	cout<<"same\n";
	// }
	// else{
	// 	cout<<"Not same\n";
	// }

	ds.unionBySize(1,2);
	ds.unionBySize(2,3);
	ds.unionBySize(4,5);
	ds.unionBySize(6,7);
	ds.unionBySize(5,6);

	// are 3 and 7 same compo
	if(ds.findPar(3)==ds.findPar(7)){
		cout<<"Same\n";
	}
	else{
		cout<<"Not same\n";
	}

	ds.unionBySize(3,7);

	// are 3 and 7 same compo
	if(ds.findPar(3)==ds.findPar(7)){
		cout<<"same\n";
	}
	else{
		cout<<"Not same\n";
	}
}