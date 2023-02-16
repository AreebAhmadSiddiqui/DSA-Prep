Fruit Into Baskets

You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits, return the maximum number of fruits you can pick.

    
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        // This question is to solve maximum size subarray with atmost k( =2 in this case) distinct elements
        
        int k=2;
        int i=0;
        int j=0;
        int ans=0;
        int n=fruits.size();
        unordered_map<int,int> mp;
        while(j<n){
            
            // Do stuff
            mp[fruits[j]]++;
            
            if(mp.size()<=k){
                ans=max(ans,j-i+1);
            }
            else if(mp.size()>k){
                
                // We need to shrink our window
                
                while(mp.size()>k){
                    mp[fruits[i]]--;
                    
                    if(mp[fruits[i]]==0) mp.erase(fruits[i]);
                    
                    i++;
                }
            }
            j++;
        }
        
        return ans;
    }
};