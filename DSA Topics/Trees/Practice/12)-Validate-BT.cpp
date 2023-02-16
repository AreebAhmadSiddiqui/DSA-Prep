Validate Binary Tree Nodes

You have n binary tree nodes numbered from 0 to n - 1 where node i has two children leftChild[i] and rightChild[i], return true if and only if all the given nodes form exactly one valid binary tree.

If node i has no left child then leftChild[i] will equal -1, similarly for the right child.

Note that the nodes have no values and that we only use the node numbers in this problem.
    
class DSU{
    public:
    vector<int> parent,size;
    DSU(int n){
        parent.resize(n+1,0);
        size.resize(n+1,1);
        
        for(int i=0;i<=n;i++) parent[i]=i;
    }
    
    int findPar(int u){
        if(parent[u]==u) return u;
        
        return parent[u]=findPar(parent[u]);
    }
    
    bool unionBySize(int u,int v){
        u=findPar(u);
        v=findPar(v);
        if(u==v) return true;
        if(size[u]<size[v]){
            parent[u]=v;
            size[v]+=size[u];
        }else{
            parent[v]=u;
            size[u]+=size[v];
        }
        return false;
    }
};

// Bahut Sare edge case

For a tree to be valid

a) Har node ka ek hi parent hona chahiye except root node (indegree[child]==1 agar kisi ki bhi indegree zyada hui to not valid)
b) koi cycle ni honi chahiye
c) multiple components ya bt ni hona chahiye
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        
        vector<int> indegree(n,0);
        DSU ds(n);
        for(int i=0;i<n;i++){
            int left=leftChild[i];
            int right=rightChild[i];
            
            if(left!=-1 && ds.unionBySize(i,left) || right!=-1 && ds.unionBySize(i,right)) { // maine union wale mein return true kar raha jab dono ka parent same ho to
                return false; 
            }
            
            if(left!=-1) indegree[left]++;
            if(right!=-1) indegree[right]++;
        }
        
        // If there are more than one components then false
        int cnt=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i) {
                cnt++;
            }
        }
        
        // if kisi ke do parents hue tab bhi return false
        for(int i=0;i<n;i++){
            if(indegree[i]>1) return false;
        }
        
        return cnt==1;
    }
};