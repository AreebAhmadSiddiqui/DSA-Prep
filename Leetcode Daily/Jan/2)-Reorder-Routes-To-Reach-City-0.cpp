STEPS

a) Dekho ham log kya kar rahe
b) ham agar u->v hai to use positive dal rahe aur pichle usmein v-> -u dal rahe
c) Yahan pe aisa hoga ki start zero se karenge aur dekhenge ki zero se kaun kaun se child pahunch sakte agar wo child > 0 honge iska matlab 0 se direct edge hai
to unko reverse karna hoga aur thik hai aisa sare children ke saath karenge ab ye confirm ho gaya ki 0-> neighbour reverse ho gae ab wo zero tak pahunch sakte
d) ab neighbors ke bachon ke saath same karo agar outgoing edge hai matlab > to usko reverse karna padega kyunki main zero tak pahunch sakta to tum bhi pahunch sakte to us edge ko bhi cnt kar lo 
e) Do a bfs because it is intuive ki pehle node fir uske bacche fir uske bache and so on
f) aur hana yahan pe visited kyun ni liya are because tree hai ye to ek hi parent hoga isliye

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        
        
        vector<int> adj[n];
        
        for(int i=0;i<n-1;i++){
            int u=connections[i][0];
            int v=connections[i][1];
            
            adj[u].push_back(v);  // this will help us know whether it is an outgoing edge or an incoming edge
            adj[v].push_back(-u); // this will help us know whether it is an outgoing edge or an incoming edge
        }
        
        
        queue<pair<int,int>> q;
        q.push({0,0});
        int cnt=0;
        while(!q.empty()){
            auto node=abs(q.front().first);
            auto parent=q.front().second;
            q.pop();
            
            for(auto child:adj[node]){
                if(abs(child)==parent) continue;
                
                if(child>0){ // it means this node was going outwards so we need to reverse it
                    cnt++;
                }
                q.push({child,node});
            }
        }
        
        return cnt;
    }
};