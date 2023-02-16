Steps

a) Ismein main ek gadbadi kar raha tha main distance ko pq mein rakh raha tha to answer galat ho raha tha kyunki distance yahan main criteria ni hai 
b) Ho sakta hai price/distance zyada ho jae lekin ham minimum stops mein pahunche isliye stops ko criteria banaya agar kisi saste raste se ham pahunche kisi node pe lekin stops k se zyada ho gae to galat hai na ham stops kam kar sakte the aur price thora increase
c) aur pq ke zarurat ni kunkia har step mein tum ek hi stop age badh rahe ho to q se kaam chal jaega


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<pair<int,int>> adj[n];
        for(auto vec:flights){
             int u=vec[0];
             int v=vec[1];
             int wt=vec[2];
             adj[u].push_back({v,wt});
        }
        
        vector<int> price(n,1e9);
        
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        price[src]=0;
        
        while(!q.empty()){
            int node=q.front().second.first;
            int fare=q.front().second.second;
            int stops=q.front().first;
            q.pop();
            
            for(auto vec:adj[node]){
                int child=vec.first;
                int cost=vec.second;
                
                if(fare+cost<price[child] && stops<=k){
                    price[child]=fare+cost;
                    q.push({stops+1,{child,price[child]}});
                }
            }
        }
        
        if(price[dst]==1e9) return -1;
        return price[dst];
    }
};