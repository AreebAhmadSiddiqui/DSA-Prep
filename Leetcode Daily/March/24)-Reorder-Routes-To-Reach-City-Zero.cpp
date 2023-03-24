Reorder Routes to Make All Paths Lead to the City Zero

There are n cities numbered from 0 to n - 1 and n - 1 roads such that there is only one way to travel between two different cities (this network form a tree). Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow.

Roads are represented by connections where connections[i] = [ai, bi] represents a road from city ai to city bi.

This year, there will be a big event in the capital (city 0), and many people want to travel to this city.

Your task consists of reorienting some roads such that each city can visit the city 0. Return the minimum number of edges changed.

It's guaranteed that each city can reach city 0 after reorder.

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        
        vector<int> adj[n]; // {u,v} // dir +v when edge is u->v and -ve when v->u
        
        
        for(auto &vec:connections){
            int u=vec[0];
            int v=vec[1];
            
            adj[u].push_back({+v});
            adj[v].push_back({-u});
        }
        
        queue<int> q;
        q.push(0);
        // Vis ki zarurat bhi ni thi tum seedhe q pair ka leke parent aur child le sakte the lekin space utnie hi leta
        vector<int> vis(n,0);
        vis[0]=1;
        int routes=0;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            
            for(auto &child:adj[node]){
                if(vis[abs(child)]) continue;
                
                q.push(abs(child));
                vis[abs(child)]=1;
                
                if(child>0){ // wo zero se door ja rha
                    routes++;
                }
            }
        }
        return routes;
    }
};