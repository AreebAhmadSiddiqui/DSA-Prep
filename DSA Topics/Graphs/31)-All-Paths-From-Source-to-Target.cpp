class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>> ans;
        
        vector<int> path;
        path.push_back(0);
        
        queue<vector<int>> q;
        q.push(path);
        
        // O(N+E)
        while(!q.empty()){
            auto currPath=q.front();
            q.pop();
            
            int node=currPath.back(); //last inserted node
            if(node==graph.size()-1){ // dest node
                ans.push_back(currPath);
                continue;
            }
            for(auto child:graph[node]){
                currPath.push_back(child);
                q.push(currPath);
                currPath.pop_back();
            }
        }
        return ans;
    }
};