// yahan pe main catch yahi tha ki kitne nodes honge usmein unhone diya hai na mod 1e5 to at most 1e5 hi nodes honge
// bas wahi cheez karni hai multiply karna hai aur steps wala array se dekhna hai agar minimum hai to le lo warna rahne do
// Ham visited wala isliye le rahe kyunki ham mod kar rahe hai to mod kuch bhi de sakta hai [0...9999] ek beech emin to agar hamne vis walal array
// ni rkaha to bahut sare multi hoga aur tle aega

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        
        int mod=1e5;
        queue<pair<int,int>> q; // {steps,multiplication}
        q.push({0,start});
        vector<int> vis(1e5,1e9); //100000
        

        O(100000*N) // lekin ye bahut hypothetical hai kyunki itna kabhi nodes banenge hi ni lekin ye man lo ki hai
        while(!q.empty()){
            int node=q.front().second;
            int steps=q.front().first;
            q.pop();
            
            if(node==end) return steps;
            
            for(auto num:arr){
                int newStart=(num*node)%mod;
                if(steps+1<vis[newStart]){
                    vis[newStart]=steps+1;
                    q.push({steps+1,newStart});
                }
            }
        }
        return -1;
    }
};

YE Wala mera plus thori help

int mod=1e5;
        queue<pair<int,int>> q; // {steps,multiplication}
        q.push({0,start});
        vector<int> vis(1e5,0);
        vis[start]=1;
        
        while(!q.empty()){
            int node=q.front().second;
            int steps=q.front().first;
            q.pop();
            
            for(auto num:arr){
                int newStart=(num*node)%mod;
                if(newStart==end) return steps+1;
                
                if(!vis[newStart]){
                    q.push({steps+1,newStart});
                    vis[newStart]=1;
                }
            }
        }
        return -1;