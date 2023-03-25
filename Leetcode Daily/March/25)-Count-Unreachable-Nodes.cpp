// Count Unreachable Pairs of Nodes in an Undirected Graph

// You are given an integer n. There is an undirected graph with n nodes, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.

// Return the number of pairs of different nodes that are unreachable from each other.
    
    
// Intuition

// Bhai pehle compoents nikal lo fir dekho us component mein jitni nodes hai wo to tum visit kar sakte lekin jo ni hai unhe visit ni kar sakte to add kar do answer mein
// Answer mein do baar add ho gaya isliye /2 kiya
class DSU{
    public:
    vector<int> parent,size;
    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1);
        
        for(int i=0;i<n+1;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findPar(int u){
        if(parent[u]==u) return u;
        return parent[u]=findPar(parent[u]);
    }
    void unionBySize(int u,int v){
        u=findPar(u);
        v=findPar(v);
        
        if(u==v) return;
        
        if(size[u]<size[v]){
            parent[u]=v;
            size[v]+=size[u];
        }else{
            parent[v]=u;
            size[u]+=size[v];
        }
    }
};
class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        
        DSU ds(n);
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            
            if(ds.findPar(u)==ds.findPar(v)) continue;
            ds.unionBySize(u,v);
        }
        
        long long ans=0;
        
        for(int i=0;i<n;i++){
//             int ultiPar=ds.findPar(i);
            
//             // Get the size of this component and jo bhi node is component mein ni hai unhe unreachable mein add kar do
//             int size=ds.size[ultiPar];
            
//             ans+=n-size;
            
            // OR
            //Size to pata hi hai baar baar iterate ni karna
            if(ds.findPar(i)==i){
                int size=ds.size[i];
                
                ans+=size*1ll*(n-size);
            }
        }
        
        return ans/2; // bhai har node do baar add ho jaegi na isliye divide by 2
    }
};