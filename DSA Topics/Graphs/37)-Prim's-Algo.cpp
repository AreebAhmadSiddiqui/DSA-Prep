class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // O(E+V)
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> mst(V,0);
        pq.push({0,0}); // {wt,startNode}
        
        int sum=0;
        
        // ElogE+ElogE
        while(!pq.empty()){
            int node=pq.top().second;
            int currWt=pq.top().first;
            pq.pop();
            
            if(mst[node]) continue; // ye check kyun because dekho ek node ke kai child honge kai sare similar child bhi honge ho skata hai wo visit ho gae ho already aur pq main baad mein ho wo with greater distance
            // pq hamesha smaller distance ko hi to lega aur jab ho sakta hai ham ek node visit kar jaen pehle aur wahi node kisi bade distance ke saath upar pada ho to ye check lagaya
            // Add it to mst
            mst[node]=1;
            sum+=currWt;
            
            // ElogE
            for(auto vec:adj[node]){
                int child=vec[0];
                int wt=vec[1];
                
                if(!mst[child]){
                    pq.push({wt,child}); // Ham log yahan kyun ni mark kar rahe visited kyunki hame minimum wala chahiye to pq main dalne ke baad hi to pata chalega minimum isliye
                }
            }
        }
        return sum;
    }
};