class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        vector<int> cntArray(256,0);
        
        int n=s.size();
        int i=0;
        int j=0;
        int ans=0;
        while(j<n){
            
            // Do stuff
            cntArray[s[j]]++;
            
            if(cntArray[s[j]]!=1){ // it means repeating
                ans=max(ans,j-i);
                
                // No we need to shrink our window tille the point it is stopes repeating
                
                while(cntArray[s[j]]!=1){ // yahan tak hi kyun because agar ye banda repeat ho raha hai s[j] ki baat kar raha to jab tak wo hatega ni tab tak hamari window mein repeating character rahega to use hatane ke liye jab tak iska cnt one na ho jae baaki sab ka cnt kam karte raho
                    cntArray[s[i]]--;
                    i++;
                }
            }
            j++;
        }
        return max(ans,j-i);;
    }
};