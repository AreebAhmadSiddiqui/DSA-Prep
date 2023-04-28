Similar String Groups

Two strings X and Y are similar if we can swap two letters (in different positions) of X, so that it equals Y. Also two strings X and Y are similar if they are equal.

For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and "rats" and "arts" are similar, but "star" is not similar to "tars", "rats", or "arts".

Together, these form two connected groups by similarity: {"tars", "rats", "arts"} and {"star"}.  Notice that "tars" and "arts" are in the same group even though they are not similar.  Formally, each group is such that a word is in the group if and only if it is similar to at least one other word in the group.

We are given a list strs of strings where every string in strs is an anagram of every other string in strs. How many groups are there?
    

class DSU{
private:
    vector<int> parent,size;
public:
    DSU(int n){
        parent.resize(n,0);
        size.resize(n,1);
        
        for(int i=0;i<n;i++) parent[i]=i;
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
            size[v]+=size[u];
            parent[u]=v;
        }else{
            size[u]+=size[v];
            parent[v]=u;
        }
    }
};
class Solution {
private:
    bool isSimilar(int i,int j,vector<string> &strs){
        string s1=strs[i];
        string s2=strs[j];
        int n=s1.size();
        int diff=0;
        for(int i=0;i<n;i++) diff+=s1[i]!=s2[i];
        
        return diff==0 || diff==2;
    }
public:
    int numSimilarGroups(vector<string>& strs) {
        
        int n=strs.size();
        DSU ds(n);
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isSimilar(i,j,strs)){
                    ds.unionBySize(i,j);
                }
            }
        }
        int cntGrp=0;
        for(int i=0;i<n;i++){
            if(ds.findPar(i)==i){
                cntGrp++;
            }
        }
        return cntGrp;
    }
};