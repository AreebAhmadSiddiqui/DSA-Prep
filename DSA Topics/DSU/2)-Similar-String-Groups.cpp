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
private:
    bool isSimilar(string a,string b){
        int cnt=0;
        
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]) cnt++;
        }
        
        if(cnt==2 || cnt==0) return true; // they are equal or swapped at two different places
        return false;
    }
public:
    int numSimilarGroups(vector<string>& strs) {
        
        DSU ds(strs.size());
        
        // O(n*n*4alpha)
        for(int i=0;i<strs.size();i++){
            for(int j=i+1;j<strs.size();j++){
                if(isSimilar(strs[i],strs[j])){
                    ds.unionBySize(i,j);
                }
            }
        }
        
        int ans=0;
        
        // no of components
        for(int i=0;i<strs.size();i++){
            if(ds.findPar(i)==i) ans++;
        }
        
        return ans;
    }
};