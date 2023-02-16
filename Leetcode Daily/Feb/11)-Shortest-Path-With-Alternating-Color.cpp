Shortest Path with Alternating Colors

You are given an integer n, the number of nodes in a directed graph where the nodes are labeled from 0 to n - 1. Each edge is red or blue in this graph, and there could be self-edges and parallel edges.

You are given two arrays redEdges and blueEdges where:

redEdges[i] = [ai, bi] indicates that there is a directed red edge from node ai to node bi in the graph, and
blueEdges[j] = [uj, vj] indicates that there is a directed blue edge from node uj to node vj in the graph.
Return an array answer of length n, where each answer[x] is the length of the shortest path from node 0 to node x such that the edge colors alternate along the path, or -1 if such a path does not exist.
    

// Yahan hamare paas two options hai main jis node pe hun usse pahle ya to main red color leke aya honga ya fir blue color so ham distance ko main criteria ni man sakte agar color adjacent same ni hai to chahe distance badh jae lekin wo anwer ho sakta hai to hame visited bhi rakhna padega ki ham is node pe is color se a chuke hai kya agar ni to push karna hi padega q main ho skata hai age koi banda ho jo ki distance zyada rakhne par hi pahunch pae baaki to bfs hai 
struct Data{
    int node,dis,color;
    Data(int d,int n,int c){
        node=n;
        dis=d;
        color=c;
    }
};
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        // Create the graph
        vector<pair<int,int>> adj[n]; // {child,colorOfTheEdge}
        
        // color 1-> for red 0-> blue
        for(auto &it:redEdges){
            int u=it[0];
            int v=it[1];
            int color=1; // 1 for red
            
            adj[u].push_back({v,color});
        }
        
        for(auto &it:blueEdges){
            int u=it[0];
            int v=it[1];
            int color=0; // 0 for blue
            
            adj[u].push_back({v,color});
        }
        
        vector<vector<int>> vis(n,vector<int> (2,0)); // {for every node if we have visited this node with a color a then we should not visit this node with color a}
        vector<int> distance(n,1e9);
        
        queue <Data> q;
        
        q.push({0,0,-1}); // {dist,node,prevColor}
        distance[0]=0;
        vis[0][0]=vis[0][0]=1;
        
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            
            int node=it.node;
            int dis=it.dis;
            int nodeColor=it.color;
            
            for(auto &children:adj[node]){
                
                int child=children.first;
                int childColor=children.second;
                
                if(!vis[child][childColor] && nodeColor!=childColor){
                    
                    if(dis+1<distance[child]) distance[child]=dis+1;
                    q.push({dis+1,child,childColor}); // dis+1 kyun distance[child] kyun ni because distance[child] min distance bata raha lekin agar main us child par doosre bade alternating path se aya hun to distance to badh jaega na isliye sirf dis+1 lo hamesha
                    vis[child][childColor]=1;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(distance[i]==1e9) distance[i]=-1;
        }
        
        return distance;
    }
};