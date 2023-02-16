class Solution {
private:
    static bool comp(pair<string, int>& a, pair<string, int>& b){
        
        return a.second==b.second ? a.first<b.first : a.second<b.second;
    }
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        
        int n=friends.size();
        vector<int> adj[n];
        
        for(int i=0;i<n;i++){
            int u=i;
            for(int j=0;j<friends[i].size();j++){
                adj[u].push_back(friends[i][j]);
            }
        }
        
        vector<int> visited(n,0);
        unordered_map<string,int> mp;
        
        queue<int> q;
        q.push(id);
        visited[id]=1;
        while(!q.empty()){
            
            int size=q.size();
            for(int i=0;i<size;i++){
                
                int node=q.front();
                q.pop();
                
                // Visit ngbrs
                for(auto &child:adj[node]){
                    if(visited[child]) continue;
                    
                    q.push(child);
                    visited[child]=1;
                }
            }
            
            level--;
            
            if(level==0) break;
        }
        
        while(!q.empty()){
            
            int node=q.front();
            q.pop();
            
            for(auto &videos:watchedVideos[node]){
                if(mp.find(videos)==mp.end()) mp[videos]=1;
                else mp[videos]++;
            }
        }
        vector<pair<string,int>> v(mp.begin(),mp.end());
        sort(v.begin(),v.end(),comp);
        
        vector<string> ans;
        for(auto &it:v){
            ans.push_back(it.first);
        }
        return ans;
    }
};