class Solution {
  public:

//    O(V*E)
// Jab bhi koi kahe ki v-1 kyun tab linear graph leke explain kar dena
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        
        
        vector<int> dis(V,1e8);
        dis[S]=0;
        // Relaxation V-1 times
        for(int i=0;i<V-1;i++){
            for(auto vec:edges){
                int u=vec[0];
                int v=vec[1];
                int wt=vec[2];
                
                // Algo
                if(dis[u]+wt<dis[v]){
                    dis[v]=dis[u]+wt;
                }
            }
        }
        
        //Checking if negative cycle is there
        
        // iterate one more time
        int flag=0;
        for(auto vec:edges){
                int u=vec[0];
                int v=vec[1];
                int wt=vec[2];
                
                // Algo
                if(dis[u]+wt<dis[v]){
                    flag=1;
                    break;
                }
        }
        if(flag==0) return dis;
        
        return {-1};
    }
};