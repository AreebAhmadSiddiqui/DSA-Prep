// Simple tha but gcd main error a raha tha to wo tle wala case hai

// so jitne bhi multipe ho nodes jo ki threshold se zyada hai unhe dsu mein dal do aur har query ke liye dsu se find parent kar lo

The numbers can be connected through other numbers, like this: 16 - 12 - 18 - 9.

Yeah, you need to check whether there is a path of any length between them.

mean i have to check path form another node pair also
example [[12,16], [12,19],[18,9'],[9,16]].....
for th= 3 there will no direct edge btw [9,16] but there is path btw 9 and 16 through


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
    int gcd(int a,int b){
        if(a==0) return b;
        return gcd(b%a,a);
    }
    void unionBySize(int u,int v){
        u=findPar(u);
        v=findPar(v);
        
        // int gc=gcd(u,v);
        // if(gc>threshold){
        //     parent[v]=u;
        // }
        
        if(u==v) return;
        if(size[u]<size[v]){
            parent[u]=v;
        }
        else{
            parent[v]=u;
        }
    }
};
class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        
        DSU ds(n);
        vector<bool> ans(queries.size());
        
        
        for(int i=threshold+1;i<=n;i++){
            for(int j=2*i;j<=n;j+=i){
                ds.unionBySize(i,j);
            }
        }
        
        for(int i=0;i<queries.size();i++){
            int u=queries[i][0];
            int v=queries[i][1];
            
            int ultiParentOfU=ds.findPar(u);
            int ultiParentOfV=ds.findPar(v);
            
            if(ultiParentOfU==ultiParentOfV) ans[i]=true;
        }
        
        return ans;
    }
};