class Solution {
public:
//     int minimumCardPickup(vector<int>& cards) {
        
//         // Minimum subarray with exactly one repeating character
        
//         unordered_map<int,int> mp;
        
//         int i=0;
//         int j=0;
//         int ans=INT_MAX;
//         while(j<cards.size()){
            
//             // Do stuff
//             mp[cards[j]]++;
            
// //             if(mp[cards[j]]==2){ // first repeating
// //                 ans=min(ans,j-i+1);
                
// //                 // Shrink the window
// //                 while(mp[cards[j]]==2){
// //                     mp[cards[i]]--;
// //                     ans=min(ans,j-i+1);
// //                     i++;
// //                 }
// //             }
            
//             while(mp[cards[j]]==2){ // first repeating
    
//                 // Shrink the window
//                     mp[cards[i]]--;
//                     ans=min(ans,j-i+1);
//                     i++;
//                 }
            
//             j++;
//             }
//         return ans==INT_MAX ? -1 : ans;
//     }
    
    int minimumCardPickup(vector<int>& cards) {
        
        // Track Last Element
        
        unordered_map<int,int> mp;
        
        int i=0;
        int j=0;
        int ans=INT_MAX;
        // O(N*1)
        while(j<cards.size()){
            
            if(mp.find(cards[j])!=mp.end()){ // repeating character
                ans=min(ans,j-mp[cards[j]]+1); // answer
            }
               
            mp[cards[j]]=j;  // yahan update isliye kar raha taki most recent banda mi sake
            j++;
        }
        
        return ans==INT_MAX ? -1 : ans;
    }
};