STEPS

a) Ham indegrees nikal rahe hai sare vertex ki isse ye pata chalega ki agar indegree zero hai matlab uski kisi pe koi dependency ni hai to u->v ordering mein u ki jagah aega yani pehle
b) aur fir ham use lenge aur hata denge aur hataenge to child ki indegrees kam ho jaegi
c) aur jis child ki indegree zero ho jae use ham q mein le lenge aur continue karenge
d) agar kisi child ki indegree zero ni hui iska matlab yahi hai ki wo kahin aur se connected hai basically cycle hai

class Solution
{
    TC-> O(V+E)
    SC-> O(V+V)
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	   vector<int> indegree(V,0);
	   for(int i=0;i<V;i++){
	       for(auto child:adj[i]){
	           indegree[child]++;
	       }
	   }
	   
	   queue<int> q;
	   for(int i=0;i<V;i++){
	       if(indegree[i]==0) q.push(i);
	   }
	   
	//    vector<int> topo;
	   int c=0;
	   while(!q.empty()){
	       int node=q.front();
	       q.pop();
	       
	    //    topo.push_back(node);
            c++;

           // Remove the nodes dependency from children
	       for(auto child:adj[node]){
	           indegree[child]--;
	           if(indegree[child]==0) q.push(child);
	           }
	    }
	    
	    // return topo;
        if(c==v) { // it means sabhi vertices visit ho gayi
            return noCycle;
        }
        else{
            return cycle;
        }
	}
};