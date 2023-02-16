class Solution{
  public:
    int longestKSubstr(string &s, int k){
    
        unordered_map<char,int> mp;   // O(26)
        
        int ans=-1;
        int n=s.size();
        int i=0,j=0;
        
        // O(2nlog26)
        while(j<n){
            
            // Do stuff
            mp[s[j]]++; // O(log(26))
            
            int size=mp.size(); //O(log(26))
            if(size==k){ // we got one potential answer
                ans=max(ans,j-i+1);
            }
            else if(size>k){
                
                // We need to decrease our window
                
                while(mp.size()>k){ //O(log26)
                    mp[s[i]]--;
                    
                    if(mp[s[i]]==0) mp.erase(s[i]);
                    
                    i++;
                }
            }
            
            j++;
        }
        
        return ans;
    }
};