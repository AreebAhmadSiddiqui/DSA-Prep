// You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.

// The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. If there is no outgoing edge from i, then edges[i] == -1.

// You are also given two integers node1 and node2.

// Return the index of the node that can be reached from both node1 and node2, such that the maximum between the distance from node1 to that node, and from node2 to that node is minimized. If there are multiple answers, return the node with the smallest index, and if no possible answer exists, return -1.

// Note that edges may contain cycles.


// Simple shortest path algo laga diya hai aur maximum leke minimize kar diya
class Solution {
private:
    void getMinDis(vector<int> &dist,vector<int> &edges,int src){
        
        queue<int> q;
        q.push(src);
        dist[src]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            int child=edges[node];
            
            if(child!=-1 && dist[node]+1<dist[child]){
                dist[child]=dist[node]+1;
                q.push(child);
            }
        }
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        
        
        int n=edges.size();
        vector<int> dist1(n,1e9);
        vector<int> dist2(n,1e9);
        
        getMinDis(dist1,edges,node1);
        getMinDis(dist2,edges,node2);

        
        int maxi=1e9;
        int ansIdx=-1;
        for(int i=0;i<n;i++){
            if(dist1[i]!=1e9 && dist2[i]!=1e9){
                int maxx=max(dist1[i],dist2[i]); // maximum liya
                if(maxx<maxi){ // minimize the maximum kar diya
                    maxi=maxx;
                    ansIdx=i;
                }
            }
        }
        
        return ansIdx;
        
    }
};