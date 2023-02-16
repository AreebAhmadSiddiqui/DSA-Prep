class DSU{
    vector<int> parent,size;
    public:
    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
        
    }
    int findPar(int u){
        if(u==parent[u]) return u;
        return parent[u]=findPar(parent[u]);
    }
    void unionBySize(int u,int v){
        u=findPar(u);
        v=findPar(v);
        
        if(u==v) return;
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        // We need to get the number of extra edges in the network
        // Then we can connect the not connected component to the same network
        
        DSU ds(n);
        
        int extraEdges=0;
        for(auto vec:connections){
            int u=vec[0];
            int v=vec[1];
            
            if(ds.findPar(u)==ds.findPar(v)){ // same component redundat edge
                extraEdges++;
            }else{ // add it to the network
                ds.unionBySize(u,v);
            }
        }
        
        int noOfComponents=0;
        
        for(int i=0;i<n;i++){
            if(ds.findPar(i)==i) noOfComponents++;
        }
        
        // To connect n components we need n-1 edges if that is possible then return the no of edges else -1
        
        return extraEdges>=noOfComponents-1 ? noOfComponents-1 : -1;
    }
};