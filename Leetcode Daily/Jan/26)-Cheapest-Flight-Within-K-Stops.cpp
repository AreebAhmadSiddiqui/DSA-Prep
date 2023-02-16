// Ham log Q kyun use kar rahe kyunki bro stops ko criteria bnaya hai to use use kar sakte hai

// Aur doosra ki dist ko main jusdgement ni bana sakta hai
// Ho sakta hai ham kisi path se dst n pahunch par jab ham min dis le ke chale lekin wahi ham min stops le ke chale to price thora zyada ho jae lekin stops k se kam hi rahe
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<pair<int,int>> adj[n];
        
        for(auto &vec:flights){
            int u=vec[0];
            int v=vec[1];
            int wt=vec[2];
            adj[u].push_back({v,wt});
        }
        
        // priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq; // min heap
        
        queue<pair<int,pair<int,int>>> pq;
        // Don't need Pq because we are arranging in terms of stops and the stops are increasing by 1 only
        
        int dis[n];
        for(int i=0;i<n;i++) dis[i]=1e9;
        
        pq.push({0,{src,0}}); // {stopsSoFar,src,dis}
        dis[src]=0;
        
        while(!pq.empty()){
            auto it=pq.front();
            pq.pop();
            int node=it.second.first;
            int stops=it.first;
            int fare=it.second.second;
            
            for(auto &it:adj[node]){
                
                int child=it.first;
                int dist=it.second;
                if(fare+dist<dis[child] && stops<=k){
                    dis[child]=dist+fare;
                    pq.push({stops+1,{child,dis[child]}});
                }
            }
        }
        
        return dis[dst]==1e9 ? -1 : dis[dst];
    }
};