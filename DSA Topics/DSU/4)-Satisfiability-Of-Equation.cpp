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
    bool equationsPossible(vector<string>& equations) {
        DSU ds(26);
        
        // first send all equal case elements
        for(auto eq:equations){
            char u=eq[0];
            char sign=eq[1];
            char v=eq[3];
            
            if(sign=='=') ds.unionBySize(u-'a',v-'a');
        }
        
        // Now check for contradiction
        
        for(auto eq:equations){
            char u=eq[0];
            char sign=eq[1];
            char v=eq[3];
            
            if(sign=='!' && ds.findPar(u-'a')==ds.findPar(v-'a')) return false;
        }
        return true;
    }
};