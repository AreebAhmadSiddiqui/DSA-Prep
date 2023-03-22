2492. Minimum Score of a Path Between Two Cities

You are given a positive integer n representing n cities numbered from 1 to n. You are also given a 2D array roads where roads[i] = [ai, bi, distancei] indicates that there is a bidirectional road between cities ai and bi with a distance equal to distancei. The cities graph is not necessarily connected.

The score of a path between two cities is defined as the minimum distance of a road in this path.

Return the minimum possible score of a path between cities 1 and n.

Note:

A path is a sequence of roads between two cities.
It is allowed for a path to contain the same road multiple times, and you can visit cities 1 and n multiple times along the path.
The test cases are generated such that there is at least one path between 1 and n.
    

class Solution {
public:
    
    
    Maine ismein socha ki har node pe pahunche par dekho uska min kitna hai agar tum kam min se a rahe ho to use le lo aur pq main dal do
    simple pq bas dis ki jaha abhi tak ka min store karo

    // ElogV
//     int minScore(int n, vector<vector<int>>& roads) {
        
//         vector<pair<int,int>> adj[n+1];
        
//         for(int i=0;i<roads.size();i++){
//             int u=roads[i][0];
//             int v=roads[i][1];
//             int wt=roads[i][2];
            
//             adj[u].push_back({v,wt});
//             adj[v].push_back({u,wt});
//         }
        
//         // Min Heap
//         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
//         vector<int> dis(n+1,1e9);
//         pq.push({1e9,1});
        
//         while(!pq.empty()){
//             auto minDisTillNow=pq.top().first;
//             auto node=pq.top().second;
//             pq.pop();
            
//             for(auto &ngbr:adj[node]){
//                 auto child=ngbr.first;
//                 auto childDis=ngbr.second;
                
//                 int minDisIfChildAdded=min(childDis,minDisTillNow);
                
//                 if(minDisIfChildAdded<dis[child]){
//                     dis[child]=minDisIfChildAdded;
//                     pq.push({dis[child],child});
//                 }
//             }
//         }
        
//         return dis[n];
//     }
    
    
    // EK bahut asan solution
    
    // a) Bhai usne gaurantee diya hai ki 1 se n tak ka path exist karta hai
    // b) To tumhe ultimately yahi find karna hai ki poore graph mein min edge kaha hai tum waha se hote hue n tak chale jana to overall min dis wahi min edge hogi
    // c) Ek catch hai ki graph connected ni hai to tumhe wo wala component hi chahiye jo jismein 1 and n dono ho to tum simply 1 se bfs aur dfs kar do okk
        
    int minScore(int n, vector<vector<int>>& roads) {
        
        vector<pair<int,int>> adj[n+1];
        
        
        // Min hi niklana tha to yahn kyun ni nikala
        // Because connected na hue aur min wo wali edge le li tab dikkat ho jaegi
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int wt=roads[i][2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        
        vector<int> vis(n+1,0);
        
        queue<int> q;
        q.push(1);
        vis[1]=1;
        
        
        // O(V+E)
        int minScore=1e9;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            
            for(auto &vec:adj[node]){
                auto child=vec.first;
                auto edgWt=vec.second;
                // min edge to leni hi hai bhale hi visited ho ya na ho
                minScore=min(minScore,edgWt);
                
                if(vis[child]) continue;
                q.push(child);
                vis[child]=1;
            }
        }
        
        return minScore;
    }
};