#include <bits/stdc++.h>
using namespace std;

// TC->O(N+2*E)
// SC->O(N)

// If u r confused about time complexity part, then see the following dry run of the while loop of the qs. he has solved..

// This is how nodes are connected(assuming undirected graph) :
// 0 -> 1 ,2, 3
// 1 -> 0
// 2 -> 0,  4
// 3 -> 0
// 4 -> 2
// So, total no. of edges = E = 4

// For first while loop , 
// node = 0,   edges = 3
// Now, before going to the for loop part, u see a constant time operation O(1)  --> q.pop( )
// This step will be executed every time we enter into while loop.

// So, for first while loop how many times for loop will execute ??
// It will be equal to the no. of edges , here it will be 3.

// Therefore, total =  ( 1 + 3 )

// Similarly for all other nodes, this is how it will look :
// ( 1 + 3 )  + ( 1 + 1 ) + ( 1 + 2 ) + ( 1 + 1 ) + ( 1 + 1 )
//    =   13  
//    =   O ( V  +  2 * E )  
//    =   O ( 5  +  2  * 4 )


// Amazing explanation! I have a doubt regarding time complexity 18:34 . For loop is running inside while loop right? So shouldn't we multiply both as: 
// O(n*(2E)) instead of adding both as: O(n) + O(2E).  Thanks for the content.

// No,it would have been multiplied only when for each node total number of adjacent node is 2*e,but this is not the case,here ultimately we are overall visiting n nodes and for each node,visiting its adjacent nodes,which is total of 2e for total nodes.


vector<int> bfsOfGraph(int V, vector<int> adj[])
{   
    queue<int> q;
    vector<int> vis(V, 0);
    vector<int> ans;
    q.push(0);
    vis[0] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (auto child : adj[node])
        {
            if (!vis[child])
            {
                vis[child] = 1;
                q.push(child);
            }
        }
    }
    return ans;
}