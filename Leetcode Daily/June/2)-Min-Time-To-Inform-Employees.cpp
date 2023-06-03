
1376. Time Needed to Inform All Employees

A company has n employees with a unique ID for each employee from 0 to n - 1. The head of the company is the one with headID.

Each employee has one direct manager given in the manager array where manager[i] is the direct manager of the i-th employee, manager[headID] = -1. Also, it is guaranteed that the subordination relationships have a tree structure.

The head of the company wants to inform all the company employees of an urgent piece of news. He will inform his direct subordinates, and they will inform their subordinates, and so on until all employees know about the urgent news.

The i-th employee needs informTime[i] minutes to inform all of his direct subordinates (i.e., After informTime[i] minutes, all his direct subordinates can start spreading the news).

Return the number of minutes needed to inform all the employees about the urgent news.

    
// Approach
    
a) Jo sabse badi height hogi wahi answer degi
b) Bas wahi karna hai
c) BFS/DFS karte jao aur max time ko store karte jao ( Kyunki wahi to Time needed Hoga)

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        int ans=0;
        vector<int> adj[n];
        
        for(int i=0;i<n;i++){
            if(manager[i]!=-1) adj[manager[i]].push_back(i);
        }
        
        queue<pair<int,int>> q; // {time,node}
        q.push({0,headID});
        
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto node=q.front().second;
                auto time=q.front().first;
                
                ans=max(ans,time);
                
                q.pop();
                
                for(auto &emp:adj[node]){
                    q.push({time+informTime[node],emp});
                    
                    // Yahan bhi sahi hai upar bhi
                    // ans=max(ans,time+informTime[node]);
                }
            }
        }
        
        return ans;
    }
};