class DSU{
private:
    vector<int> parent;
public:
    DSU(int n){
        parent.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int findParent(int u){
        if(parent[u]==u) return u;
        
        return parent[u]=findParent(parent[u]);
    }
    void unionByAlphabets(int u,int v){
        u=findParent(u);
        v=findParent(v);
        
        if(u<v){
            parent[v]=u;
        }
        else{
            parent[u]=v;
        }
    }
};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        
        DSU ds(26);
        
        for(int i=0;i<s1.size();i++){
            int u=s1[i]-'a';
            int v=s2[i]-'a';
            
            ds.unionByAlphabets(u,v);
        }
        
        string ans="";
        
        for(int i=0;i<baseStr.size();i++){
            int node=baseStr[i]-'a';
            
            int minNode=ds.findParent(node);
            ans+=(minNode+'a');
        }
        
        return ans;
    }
};