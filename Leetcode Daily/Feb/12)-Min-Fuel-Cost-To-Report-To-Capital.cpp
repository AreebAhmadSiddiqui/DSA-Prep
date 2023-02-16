Minimum Fuel Cost to Report to the Capital

There is a tree (i.e., a connected, undirected graph with no cycles) structure country network consisting of n cities numbered from 0 to n - 1 and exactly n - 1 roads. The capital city is city 0. You are given a 2D integer array roads where roads[i] = [ai, bi] denotes that there exists a bidirectional road connecting cities ai and bi.

There is a meeting for the representatives of each city. The meeting is in the capital city.

There is a car in each city. You are given an integer seats that indicates the number of seats in each car.

A representative can use the car in their city to travel or change the car and ride with another representative. The cost of traveling between two cities is one liter of fuel.

Return the minimum number of liters of fuel to reach the capital city.
    
class Solution {
private:
    
    // Fuel is equal to the number of cars coming to the source
    // How to get no of cars ceil(people/seats)
    // Ek dum neeche tak chale jao aur har node se poocho tumko upar jane mein kitni cars lagengi aur usko ans main add kar do
    long long dfs(int node,int parent,vector<int> adj[],int seats,long long &fuel){
        
        
        int people=1;
        for(auto &child:adj[node]){
            if(child==parent) continue;
            
            people+=dfs(child,node,adj,seats,ans);
        }
        
        int noOfCars=(people+seats-1)/seats;
        if(node!=0) fuel+=noOfCars; // why this condition because zero ke upar to jana ni hai zero tak hi to reach karna hai 
        return people;
    }
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        
        int n=roads.size();
        vector<int> adj[n+1];
        for(auto &it:roads){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        long long fuel=0;
        dfs(0,-1,adj,seats,fuel);
        return fuel;
    }
};