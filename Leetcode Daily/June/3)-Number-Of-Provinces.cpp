class DSU{
  public:
    vector<int> parent,size;
    DSU(int n){
        parent.resize(n,0);
        size.resize(n,0);
        
        for(int i=0;i<n;i++){
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n=isConnected.size();
        DSU ds(n+1);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    ds.unionBySize(i,j);
                }
            }
        }
        
        int provinces=0;
        for(int i=0;i<n;i++){
            if(ds.findPar(i)==i) provinces++;
        }
        
        return provinces;
    }
};