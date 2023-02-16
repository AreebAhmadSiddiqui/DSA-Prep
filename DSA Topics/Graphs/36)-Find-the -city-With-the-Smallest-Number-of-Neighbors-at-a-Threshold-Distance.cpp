// Dijstra's Method
class Solution {
    private:
    vector<int> dijsktrasAlgorithm(int V, vector<pair<int,int>> adj[], int S){
        
        priority_queue<pair<int,int>> pq; // max heap by default
        
        pq.push({0,-S});
        vector<int> dis(V,1e9);
        dis[S]=0;
        
        while(!pq.empty()){
            int node=-pq.top().second;
            int dist=-pq.top().first;
            pq.pop();
            
            for(auto vec:adj[node]){
                int child=vec.first;
                int childWt=vec.second;
                if(dist+childWt<dis[child]){
                    dis[child]=dist+childWt;
                    pq.push({-dis[child],-child});
                }
            }
        }
        
        return dis;
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<pair<int,int>> adj[n];
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        vector<vector<int>> matrix;
        
        // Get all sources
        for(int i=0;i<n;i++){
            matrix.push_back(dijsktrasAlgorithm(n,adj,i)); // {v,adj,src}
        }
        
        int minCnt=INT_MAX,ans=0;
        for(int i=0;i<n;i++){
            // for each city check if threshold to ni cross ho gaya
            int cnt=0,flag=0;
            for(int j=0;j<n;j++){
                if(matrix[i][j]<=distanceThreshold){
                    cnt++;
                }
            } 
            
            // For min no of cities
            if(cnt<=minCnt){
                minCnt=cnt;
                ans=i;
            }
        }
        return ans;
    }
};