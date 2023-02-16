class Solution {
private:
    bool isAnagram(vector<int> &a,vector<int> &b){
        
        for(int i=0;i<26;i++){
            if(a[i]!=b[i]) return false;
        }
        return true;
    }
public:
    vector<int> findAnagrams(string pat, string txt) {
        vector<int> hashTxt(26,0),hashPat(26,0);
	    
	    for(int i=0;i<txt.size();i++){
	        hashTxt[txt[i]-'a']++;
	    }
	    
	    int k=txt.size();
	    
	    int i=0;
	    int j=0;
	    vector<int> ans;
	    while(j<pat.size()){
	        
	        hashPat[pat[j]-'a']++;
	        
	        if(j-i+1==k){ // we reach our window limit now we need to check for anagrams
	            
	            if(isAnagram(hashPat,hashTxt)){ // jitne freq pat mein hogi utna hi txt mein bhi honi chahiye for anagrams
	                ans.push_back(i);
	            }
	            
	            // Now slide the window
	            hashPat[pat[i]-'a']--; // since we are now leaving it so decrease its value
	            i++;
	        }
	        
	        j++;
	    }
	    
	    return ans;
    }
};