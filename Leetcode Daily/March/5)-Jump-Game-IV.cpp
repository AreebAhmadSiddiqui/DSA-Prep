Jump Game IV

Given an array of integers arr, you are initially positioned at the first index of the array.

In one step you can jump from index i to index:

i + 1 where: i + 1 < arr.length.
i - 1 where: i - 1 >= 0.
j where: arr[i] == arr[j] and i != j.
Return the minimum number of steps to reach the last index of the array.

Notice that you can not jump outside of the array at any time.
    
// Jab bhi aisa kuch aya kare to bfs bhi socha karo in one step you can move this minimum steps batane hai to bfs lag sakta hai
// Clear hamlog baar baar iterate karna na pade uske liye laga rahe
// Vis to ho jaega lekin loop to chalega hi jitni baar us value ke coresponding array of idx ko traverse karoge

class Solution {
public:
    int minJumps(vector<int>& arr) {
        // for every node i have 3 options i-1 , i+1 and go to a node with the same value
        
        int n=arr.size();
        // For nodes having same value
        
        unordered_map<int,vector<int>> mp;
        
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        
        vector<int> vis(n,0);
        queue<pair<int,int>> q; // {steps,idx}
        q.push({0,0});
        vis[0]=0;
        
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            
            auto idx=it.second;
            auto steps=it.first;
            
            if(idx==n-1) return steps;
            
            // Check for idx-1
            if(idx-1>=0 && !vis[idx-1]){
                q.push({steps+1,idx-1});
                vis[idx-1]=1;
            }
            
            // Check for idx+1
            if(idx+1<n && !vis[idx+1]){
                q.push({steps+1,idx+1});
                vis[idx+1]=1;
            }
            
            // YE TLE DE RAHA
            // KHUD HI SOCHO KI EK VALUE SE KITNE VECTORS HONGE AUR TUM BAAR BAAR LOOP LAGAOGE TO TLE TO AEGA HI
            // check for value
            // for(auto &it:mp[arr[idx]]){
            //     if(!vis[it]){
            //         q.push({steps+1,it});
            //         vis[it]=1;
            //     }
            // }
            
            vector<int> &indices=mp[arr[idx]];
            for(auto &it:indices){
                if(!vis[it]){
                    q.push({steps+1,it});
                    vis[it]=1;
                }
            }
            
            indices.clear(); // ab sirf ek baar iterate hoga ye wali value ke corresponding sare index
        }
        
        return -1;
    }
};