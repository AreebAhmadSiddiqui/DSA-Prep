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
    
    // TC-> O(k*4*4*aplha)
    // SC-> O(m*n)
    
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        
        // We need to go for 1d indexes for 2d matrix formula is row*m+col where m is row size
        
        int oneDSize=n*m;
        vector<vector<int>> vis(n,vector<int> (m,0)); // they can give same indices again so to avoid doing the same thing again use this
        
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        DSU ds(oneDSize);
        
        int cnt=0;
        vector<int> ans;
        
        // O(k*4*4*aplha)
        for(auto it:operators){
            int row=it[0];
            int col=it[1];
            
            
            if(vis[row][col]==1){
                ans.push_back(cnt);
                continue;
            }
            
            // initially assume ke ye akela banda hai to lets say ye cnt bdhaa dega
            cnt+=1;
            vis[row][col]=1;
            int oneDIndex=row*m+col;
            for(int i=0;i<4;i++){
                
                int newRow=row+dx[i];
                int newCol=col+dy[i];
                
                int newOneDIndex=newRow*m+newCol;
                
                // iska matlab pehle to wo grid ke andar ho aur 1 ho aur uska parent 
                // alag ho to use ek me le lo
                if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && vis[newRow][newCol]==1 
                && ds.findPar(oneDIndex)!=ds.findPar(newOneDIndex)){
                    cnt--; // as wo island ismein mil gaya
                    ds.unionBySize(oneDIndex,newOneDIndex);
                }
            }
            
            ans.push_back(cnt);
        }
        return ans;
    }
};