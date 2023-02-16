STEPS

a) Dekho ismein ham log apni recursion ka benefit dekhenge
b) hamlog apne child se calculate karwaenge ki uska answer kya hai aur uske according apna answer set karenge aur apne parent ko bhej denge
c) yahan pe ye kar rahe ki har node mein uske child se dfs karao aur jab wo dfs kar le tab uske pass jo answer hai wo currNode mein bhi dal do
d) aur ultimately jo currentNode hai use return kar do
e) tum soch rahe hoge ki 26 array kyun O(1) mein hi kar dete are dekho ki jab wo neechec jaega to kuch na kuch to count karenga hi aur agar manlo jis node pe ham khade hai us node ka koi answer na ho lekin hamare upar wale ka ho to? agar O(1) wlaa karte to dikkat ati na isliye poora store kar rahe

f) Maine bhi kar diya tha unordered_map se lekin wo tle diya last 2 cases mein ye code bhi tle diya hai last 2 mein lekin ye sahi hai O(n*26)

class Solution {
private:
    vector<int> dfs(int node,int parent,vector<int> adj[],string labels,vector<int> &ans){
        
        vector<int> countCurrentNode(26,0);
        countCurrentNode[labels[node]-'a']=1; // as it is the starting point
        
        for(auto child:adj[node]){
            if(child==parent) continue;
            
            vector<int> countChildNodes=dfs(child,node,adj,labels,ans);
            
            for(int i=0;i<26;i++){
                countCurrentNode[i]+=countChildNodes[i];
            }
        }
        
        ans[node]=countCurrentNode[labels[node]-'a'];
        return countCurrentNode;
    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> ans(n,0);
        
        vector<int> adj[n];
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    
        
        dfs(0,-1,adj,labels,ans);
        return ans;
    }
};