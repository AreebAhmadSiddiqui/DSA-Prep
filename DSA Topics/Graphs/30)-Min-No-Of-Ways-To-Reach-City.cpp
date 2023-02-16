STEPS

a) Maine kuch had tak sahi kar liya tha
b) Dekho ismein hame ways array extra le ke rakhna hai aur disjkstra's laga dena hai
c) but thora socho agar main kisi bande ke paas pehli baar gaya to main jitne ways se apne paas aunga in total main us bande ke pass bhi utne hi ways mein to jaunga kamre wala example lena agar mein is kamre main baitha hun aur usmein ane ke 2 darwaze hai to teesra darwaze se doosre kamre main jane ke bhi 2 hi ways hue
d) Aur kahain kisi node pe same distance se aya ja sakta hai to main jitne se a sakta hun wo aur wo jitne se a sakta hai wo unhe add kardo


        vector<pair<long long,long long>> adj[n];
        long long mod=1e9+1;
        // Adjanceny List Creation
        for(auto vec:roads){
            long long u=vec[0];
            long long v=vec[1];
            long long wt=vec[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
        vector<long long> vis(n,LONG_MAX);
        vector<long long> ways(n,0);
        pq.push({0,0});
        vis[0]=0;
        ways[0]=1;
        
        while(!pq.empty()){
            long long currTime=pq.top().first;
            long long node=pq.top().second;
            pq.pop();
            
            for(auto vec:adj[node]){
                long long child=vec.first;
                long long time=vec.second;
                
                if(currTime+time<vis[child]){
                    vis[child]=currTime+time;
                    pq.push({vis[child],child});
                    ways[child]=ways[node];
                }
                else if(currTime+time==vis[child]){
                    ways[child]+=ways[node];
                }
            }
        }
        return ways[n-1]%mod;