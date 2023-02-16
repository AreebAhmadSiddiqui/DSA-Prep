class Solution {
private:
    bool isConcatenatedSubstring(string &s,unordered_map<string,int> mp,int len,int maxWords){ // ye bhi dekho map ko reference se paas ni kar raha
    // agar kardeta hun to jo neeche freq kam kari hai fir se baar baar bhadana padega
        
        int cntOfWords=0; // cntWords kyun ? main jab is s mein string count karunga to all total mein jitne words hai hamari dictionary mein utna hi count ana chahiye
        Example

        // s=abcdef   words={'ab','cd','ef'}
        // Jab isko dekhunga to cnt inke barabar hi aega

        lekin

        // s=ababef  words={'ab','cd','ef'}
        // lekin ismein cnt 2 hi aega jo ki galat ho jaega

        int i=0;
        int cnt=0;
        // O(No of Words * word len * log(noOfWords))
        while(i<s.size()){
            string temp=s.substr(i,len);  // O(word len)
            if(mp.find(temp)==mp.end()) return false;  // age dekhne ki zarurat ni

            if(mp.find(temp)!=mp.end() && mp[temp]!=0){ // map ka use yahan pe hai dekho main jab bhi kisi character ko visit kar leta hun to uski freq kam kardeta hun agar ni kari to jo second example hai wo pass ho jaega kyunki usemein ab 2 baar search karega aur dono baar use mil jaega to wo cnt bhad dega jabki use ni bhadan tha
                cnt++;
                mp[temp]--; // isliye kam kar diya
            }
            
            i+=len;
        }
        return cnt==maxWords; // ye to check hai ki utne hi words hai ki ni
    }
public:

    // Line by line likha hun kyun kiya kya fayda
    vector<int> findSubstring(string &s,vector<string>& words) {
       
        unordered_map<string,int> mp; // ye hame log jitne words hai total unke count ke liye rakh rahe
        
        for(int i=0;i<words.size();i++){
            mp[words[i]]++; // yahan count kar liya simply
        }
        
        int k=words.size()*words[0].size(); // ye hai window ka size
        vector<int> ans;
        
        int n=s.size();
        int i=0;
        int j=0;
        string temp="";
        // O(n * No of Words * word len * log(noOfWords))
        while(j<n){ // normal sliding window shuru kari
            
            // Do stuff
            temp+=s[j];
            
            if(j-i+1==k){ // reached window end
                
                // O(No of Words * word len * log(noOfWords))
                if(isConcatenatedSubstring(temp,mp,words[0].size(),words.size())){ // why words[0].size() because I will get these length substrings and check in the set
                    
                    ans.push_back(i);
                }
                
                // Shrink the window
                temp.erase(0,1);
                i++;
            }
            j++;
        }
        return ans;
    }
};