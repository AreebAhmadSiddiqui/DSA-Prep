class Solution {
private:
    bool dfs(string &start,string &dest,unordered_map<string,vector<pair<string,double>>> &adj,unordered_map<string,int> &vis,double &value){
        
        if(start==dest) return true;
        
        vis[start]=1;
        for(auto &vec:adj[start]){
            string child=vec.first;
            double wt=vec.second;

            if(vis.find(child)==vis.end()){
                value*=wt;
                if(dfs(child,dest,adj,vis,value)) return true;
                value/=wt;
            }
        }
        return false;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        unordered_map<string,vector<pair<string,double>>> adj;
        
        for(int i=0;i<equations.size();i++){
            
            string a=equations[i][0];
            string b=equations[i][1];
            double val=values[i];
            adj[a].push_back({b,val});  // a se b means a/b 
            adj[b].push_back({a,1.0/val}); // b se a means 1/(a/b)
        }
  
        vector<double> ans;
        for(auto &query:queries){
            string src=query[0];
            string end=query[1];
            
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