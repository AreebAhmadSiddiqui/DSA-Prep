class Solution {
private:
     
    Dekho ismein hame kya karna hai

    a) Pehli obvervation to ye hi hogi ki hame dfs lagana hai
    b) doosri baat ki kya tree banao ya graph dekho tree banana mushkil hai aur need bhi ni to graph bana do
    c) Ab dekho har node pe jao aur uske children se poocho ki tumhare children mein apple tha kya? aur kahin tumhare pass hi to apple ni hai
    d) Agar upar mein se koi bhi condtition true hoti hai to jis node pe main khada hun uska time + child ka time+ 2(ane jane ka add) kar do
    
    int dfs(int node,vector<int> adj[],vector<bool> &hasApple,int parent){
        
        int currNodeTime=0;
        int childrenTime=0;
        
        for(auto child:adj[node]){
            if(child!=parent){
                childrenTime=dfs(child,adj,hasApple,node);
                
                if(childrenTime>0 || hasApple[child]){
                    currNodeTime+=childrenTime+2; // (when the child has apple then going to the child and returning back will result in 2 steps)
                }
            }
        }
        
        return currNodeTime;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> adj[n];
        
        for(auto &vec:edges){
            int u=vec[0];
            int v=vec[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> visited(n,0);
        
        int time=dfs(0,adj,hasApple,-1);
        
        return time;
    }
};