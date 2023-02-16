// Copy Paste Mara Samjh Ni Aya Kuch ;(
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        
       
        
        int n=ideas.size();
        
        // Brute Force
        // O(n*n*1)
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 string a=ideas[i];
//                 string b=ideas[j];
//                 swap(a[0],b[0]);
                
//                 if(st.find(a)==st.end() && st.find(b)==st.end()) cnt++;
//             }
//         }
        
        
        unordered_map<char,unordered_set<string>> mp; // {map will container the suffix left after removing the character }
        
        for(auto &it:ideas) mp[it[0]].insert(it.substr(1));
        
        // O(26*26*N)
        for(char ch1='a';ch1<='z';ch1++){
            for(char ch2=ch1+1;ch2<='z';ch2++){
                
                unordered_set <string> s1 = mp[ch1], s2 = mp[ch2];
                
                int commonCharacters = 0;
                for(auto &u : s1)
                    if(s2.find(u)!=s2.end()) commonCharacters++;
                
                cnt += (long long)(s1.size()-commonCharacters)*(long long)(s2.size()-commonCharacters)*2;
            }    
        }
    
        
        return cnt;
    }
};