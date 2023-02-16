STEPS

a) Toposort ki classical problem hai 
b) hame words sorted order mein diye hue to ham adjacent elements ko choose karenge aur dekhenge kaun chota hai use u bana denge aur bade wale ko aur fir u -> v edge bana denge
c) Main soch to sahi raha bas dikkat a rahi thi ki kitne bande le wo bhi diya hai ki sirf k bande lene hai
d) To 26 ka array banane se acha hai ki K ka hi array lo K alpha ka matlab first k characters tabhi to ham x-'a' kar pa rahe agar k=5 hota aur letter z diya hota tab to fit bhi na hota na array mein
e) K is the no of vertices

Acha interviewer ye bhi pooch sakta hai ki kab order ni valid hoga to 2 test case dena

1) abcd abc yahan ham d ko kisi se compare hi ni kar pae lekin agar abc abcd hota tab thik hai kyunki abc shorter hai wo pehle hi aega
2) Doosra agar cyclic dependency ho jaise

    abc
    baf
    ade

iska aega a->b->a dekho eeror hai ye
class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        
        
        vector<int> adj[K];
        
        for(int i=0;i<N-1;i++){
            
            string word1=dict[i];
            string word2=dict[i+1];
            int len=min(word1.size(),word2.size());
            
            // First differentiating character
            for(int j=0;j<len;j++){
                if(word1[j]!=word2[j]){
                    adj[word1[j]-'a'].push_back(word2[j]-'a');
                    break;
                }
            }
        }
        
       //TOPOSORT 
       vector<int> indegree(K,0);
	   for(int i=0;i<K;i++){
	       for(auto child:adj[i]){
	           indegree[child]++;
	       }
	   }
	   
	   queue<int> q;
	   for(int i=0;i<K;i++){
	       if(indegree[i]==0) q.push(i);
	   }
	   
	   string topo;
	   
	   while(!q.empty()){
	       int node=q.front();
	       q.pop();
	       
	       topo.push_back(node+'a');

          // Remove the nodes dependency from children
	       for(auto child:adj[node]){
	           indegree[child]--;
	           if(indegree[child]==0) q.push(child);
	           }
	    }
	    
	    return topo;
    }
};