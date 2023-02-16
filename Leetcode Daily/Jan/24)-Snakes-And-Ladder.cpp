Why BFS?

Because dekho ismein hame har choice pe ek step hi lena hai to agar graph mana to hame sabse kam steps mein pahunch jana hai target aur agar ham bfs karenge to asani se pahucnhe
Har index mein wo 6 steps lega aur sabse door jo le ja raha hoga use mark kardega to next time ham waha se shuru karenge isliye jaldi pahunchenge

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        
        // Convert it into One-D indices;
        
        int n=board.size();
        vector<int> grid(n*n+1,0);
        
        bool leftToRight=true;
        
        // Store in in nodes
        int ind=1;
        int i=n-1,j=0;
        // O(n2)
        while(ind<=n*n){
            grid[ind++]=board[i][j];
         
            if(leftToRight && j==n-1){
                leftToRight=false;
                i--;
            }else if(!leftToRight && j==0){
                leftToRight=true;
                i--;
            }else{
                
                if(leftToRight) j++;
                else j--;
            }
        }

        
        // Do a bfs
        
        queue<int> q;
        q.push(1); // start index
        vector<int> dis(n*n+1,1e9);
        dis[1]=0;
        
        // O(6n2) 
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            for(int moves=node+1;moves<=min(node+6,n*n);moves++){
                int nextStep=moves; 
                if(grid[moves]!=-1){ // this is because we need to find whether this guy hame snake de raha ki ladder agar kuch ni to nextStep to moves hai hi kyunki snake aur ladder ke case mein hame jahan wo point karenge waha jana padega isliye
                    nextStep=grid[moves];
                }
                if(dis[node]+1<dis[nextStep]){
                    dis[nextStep]=dis[node]+1;
                    q.push(nextStep);
                }
            }
        }
        
        return dis[n*n]==1e9 ? -1 : dis[n*n];
    }
};