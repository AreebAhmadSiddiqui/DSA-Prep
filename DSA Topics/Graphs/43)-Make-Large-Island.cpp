

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
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

    // TC->O(n*m*4aplha*log(4))
    Sc->O(4+4+n*n)
    int MaxConnection(vector<vector<int>>& grid) {
        
        int n=grid.size();
        DSU ds(n*n);
        
        //connect every 1 in the graph using DSU
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        
        // DSU with all ones connected
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                
                if(grid[row][col]==1){
                    int node=row*n+col; // 1-d indexing
                    
                    for(int i=0;i<4;i++){
                        
                        int newRow=row+dx[i];
                        int newCol=col+dy[i];
                        
                        int adjNode=newRow*n+newCol; // 1-d indexing
                        
                        if(newRow>=0 && newRow<n && newCol>=0 && newCol<n){
                            if(grid[newRow][newCol]==1 && ds.findPar(node)!=ds.findPar(adjNode)){ // come join me
                                ds.unionBySize(node,adjNode);
                            }
                        }
                    }
                }
            }
        }
        
        
        int ans=0;
        
        //Now check if adding zero will be beneficial;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==0){
                    // vector<int> visited(n*n,0);
                    set<int> visited;
                    int area=0;
                    
                    for(int i=0;i<4;i++){
                        
                        int newRow=row+dx[i];
                        int newCol=col+dy[i];
                        
                        int adjNode=newRow*n+newCol; // 1-d indexing
                        
                        if(newRow>=0 && newRow<n && newCol>=0 && newCol<n){
                            if(grid[newRow][newCol]==1){
                                
                                int ultimateParentNode=ds.findPar(adjNode);
                                
                                // 1 0 1
                                // 1 1 1
                                
                                // aise case maine zero teen bar add kardega isliye ultimate parent ko visited kar diya
                                // lekin ye galat kar diya kyunki ho sakta hai koi doosra zero bhi isi se island se conndectd ho 
                                // aur maine visited kar diya hai to wo dikkat dega na to aisa karo visited ko har zero ko jab check karna tab initialise kardo
                                // array wala tle de raha tha but ye set wala constant hai aur better hai atmost log(4) hi to parents honge set mein
                                if(visited.find(ultimateParentNode)==visited.end()){
                                    area+=ds.size[ultimateParentNode];
                                    visited.insert(ultimateParentNode);
                                }
                            }
                        }
                    }
                    ans=max(ans,area+1); // area of surrounding 1s and plus 1 for converting itself
                }
            }
        }
            
        // just to be sure if there are all ones then answer print zero ho jaega
        ans=max(ans,ds.size[n*n-1]);
        return ans;        
    }
};
