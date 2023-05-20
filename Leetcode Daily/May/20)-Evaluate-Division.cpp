399. Evaluate Division

You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

Return the answers to all queries. If a single answer cannot be determined, return -1.0.

Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

class Solution {
private:
    bool dfs(string src,string end,unordered_map<string,vector<pair<string,double>>> &adj,unordered_map<string,int> &vis,double &ans){
        
        if(src==end) return true;
        
        vis[src]=1;
        
        for(auto &it:adj[src]){
            string child=it.first;
            double val=it.second;
            
            if(vis.find(child)!=vis.end()) continue;
            ans*=val;
            if(dfs(child,end,adj,vis,ans)) return true;
            ans/=val;
        }
        return false;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        // Treat this as a graph porblem and start visiting from query[i][0] to query[i][1] and keep track of answer
        // If you are able to reach the target return true else return false;
        
        unordered_map<string,vector<pair<string,double>>> adj;
        
        int n=equations.size();
        for(int i=0;i<n;i++){
            string s1=equations[i][0];
            string s2=equations[i][1];
            
            double val=values[i];
            
            adj[s1].push_back({s2,val});
            adj[s2].push_back({s1,1.0/val});
        }    
        vector<double> ans;
        for(auto &it:queries){
            string src=it[0];
            string end=it[1];
            
            unordered_map<string,int> vis;
            
            if(adj.find(src)!=adj.end() && adj.find(end)!=adj.end()){
                double val=1.0;
                if(dfs(src,end,adj,vis,val)) ans.push_back(val);
                else ans.push_back(-1.0);
            }else{
                ans.push_back(-1.0);
            }
        }
        return ans;
    }
};