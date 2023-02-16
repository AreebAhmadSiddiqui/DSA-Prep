STEPS

a) Ekdum same hai cycle check jaisa 
b) Agar is vertex se cycle a rhi to safe State ni agar ni a rhai to safe state aega
c) TO hame check ko safeState hai ki ni uske liye rakh rahe agar cycle hai to ye state is not safe check[node]=0 and agar safe hai to check[node]=1
d) dfVis[node]=0 jahan kar rahe iska matlab hai is node ko traverse kar lya aur cycle ni ayi to check[node]=1 kar diya
e) 21 aur 27 line mein cycle detect hua hai to ye node ka check[node]=0 kar diya
f) line 15 par check[node]=0 ka matlab by deafult unsafe ( aur waise bhi check[node]=0 3 jagah jo likha hai wo na bhi likhte to chal jata kyunki by default wo 0 hi hai)

class Solution {
    private:
    bool dfs(int node,vector<vector<int>> &graph,vector<int> &vis,vector<int> &dfsVis,vector<int> &check){
        vis[node]=1;
        dfsVis[node]=1;
        check[node]=0;
        
        for(auto child:graph[node]){
            // Not visited
            if(!vis[child]){
                if(dfs(child,graph,vis,dfsVis,check)){
                    check[node]=0;
                    return true;
                }
            }
            // Visited but also path visited then return true
            else if(dfsVis[child]){
                check[node]=0;
                return true;
            }
        }
        
        check[node]=1;
        dfsVis[node]=0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        
        vector<int> vis(n,0),dfsVis(n,0),check(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,graph,vis,dfsVis,check);
            }
        }
        vector<int> safeNodes;
        for(int i=0;i<n;i++){
            if(check[i]==1) safeNodes.push_back(i);
        }
        
        return safeNodes;
    }
};



// EK method aur hai TopoSort wala

a) Graphs ki sare edges ko reverse kar do aur toposort laga do lekin usmein wo space aur time wise thora costly hai isliye use na use karna