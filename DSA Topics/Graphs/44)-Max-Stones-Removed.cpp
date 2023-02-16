class DSU{
public:
    vector<int> rank,parent,size;
	
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
    // TC-> O(n)
    int removeStones(vector<vector<int>>& stones) {
        
        int n=stones.size();
        // Get maxRow and maxCol for dsu
        int maxRow=0,maxCol=0;
        for(auto vec:stones){
            int row=vec[0];
            int col=vec[1];
            maxRow=max(row,maxRow);
            maxCol=max(col,maxCol);
        }
        
        // Create DSU
        DSU ds(maxRow+maxCol+1);
        
        // We are considering rows+columns to be nodes as the stones sharing same row and col would be connected easily
        
        for(auto vec:stones){
            int row=vec[0];
            int col=vec[1];
            
            int rowNode=row;
            int colNode=maxRow+col+1;
            // lets suppose rows are from 0...4 so the column 0 would 0+4+1=5 column 1 would be 1+4+1=6
            
            ds.unionBySize(rowNode,colNode); // join them in one
        }
        
        // Our DSU is created so ther would be many components in the DSU graph so how many max stones can you remove from each component?
        // ans is component.size()-1 so you have to this for all components
        
        // lets say
        
        // C1-> 4 stones  max stones removed= 4-1
        // C2-> 5 stones  max stones removed= 5-1
        // C3-> 3 stones  max stones removed= 3-1
        
        // Total = > (4+5+3)-(1+1+1)
        // Total = >  No of stones(n) - No of components
        
        // Get the no of components;
        
        int noOfComponents=0;
        for(int i=0;i<=maxRow+maxCol;i++){
            // Why we removed those with size 1 because wo log akele honge unse saaath koi ni hoga to remove ni kar sakte
            if(ds.size[i]!=1 && ds.findPar(i)==i){
                noOfComponents++;
            }
        }
        
        return n-noOfComponents;
    }
};