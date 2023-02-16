class Solution
{
	public:
	
	// Aur hamne Queue kyun ni use kiya kyunki usmein ham bahut sare iterations karenge queue ko lete ho to zaruri ni hai ki har ba min wala mile
    // leki pq lete hi min milega aur answer jaldi a jaega

    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // priority_queue<pair<int,int>> pq; // max heap by default

        // or

        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; 
        
        // pq.push({0,-S});
        // vector<int> dis(V,1e9);
        // dis[S]=0;
        
        // // O(ElogV) proof bhi hai iska dekh lena tum set bhi use kar sakte usmein erase ka function use kar sakte jaise agar koi bhi dis plus wt kam ae to pehle se jo pada hua hai set mein use erase kar do pq mein erase ni kar sakte lekin ye function bhi logV le lega
        // while(!pq.empty()){
        //     int node=-pq.top().second;
        //     int dist=-pq.top().first;
        //     pq.pop();
            
        //     for(auto vec:adj[node]){
        //         int child=vec[0];
        //         int childWt=vec[1];
        //         if(dist+childWt<dis[child]){
        //             dis[child]=dist+childWt;
        //             pq.push({-dis[child],-child});
        //         }
        //     }
        // }
        
        // return dis;
        
        
        set<pair<int,int>> st;
        
        st.insert({0,S});
        vector<int> dis(V,1e9);
        dis[S]=0;
        
        // O(ElogV) proof bhi hai iska dekh lena tum set bhi use kar sakte usmein erase ka function use kar sakte jaise agar koi bhi dis plus wt kam ae to pehle se jo pada hua hai set mein use erase kar do pq mein erase ni kar sakte lekin ye function bhi logV le lega
        while(!st.empty()){
            auto it=*(st.begin()); // smallest element
            int node=it.second;
            int dist=it.first;
            st.erase(it);
            
            for(auto vec:adj[node]){
                int child=vec[0];
                int childWt=vec[1];
                if(dist+childWt<dis[child]){
                    if(dis[child]!=1e9) // It means someone aya aur ise change kiya aur wo set mein hoga to use erase kar do kyunki hame chota answer mil gaya hai wo agar hua to faltu time hi jaega
                    {
                        st.erase({dis[child],child});
                    }
                    dis[child]=dist+childWt;
                    st.insert({dis[child],child});
                }
            }
        }
        
        return dis;
    }
};