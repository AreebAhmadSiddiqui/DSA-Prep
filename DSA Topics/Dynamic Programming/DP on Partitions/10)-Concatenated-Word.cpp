// Steps

Ek doubt tha ki suffix ko kyun check kar rahe explicitly ham log sirf prefix ko check karein aur recursion se kah de ki tum baki ka check kar lo jaise word break 1 main kiya tha lekin bro usmein isliye kar pa rahe the kyunki usmein index se khel rahe the to jab idx end pe pahuchta tha to return karte the true yahan index se ni khel rahe

a) Har word ke liye check karo ki uska prefix aur suffix hai ki ni set main agar hai to return true
b) Agar ni to check kar ki suffix kahin kai aur words se combined to ni hai agar haan to return true
c) Agar ye bhi na ho to return false;

class Solution {
private:
    bool isAConcatenatedWord(string &word,unordered_set<string> &st,unordered_map<string,int> &dp){
        
        string prefix,suffix;
        
        
        if(dp[word]!=0) return dp[word];
        
        // O(L*(L)
        // O(L*L) -> O(L^2)
        for(int i=1;i<word.size();i++){ // O(L)
            
            // These two combined will take O(L)
            prefix=word.substr(0,i);
            suffix=word.substr(i,word.size()-i);
            
            // ~O(1) Average
            if(st.find(prefix)!=st.end() && st.find(suffix)!=st.end()){// this is a concatenated word of two words
                return dp[word]=true;
                
            }else if(st.find(prefix)!=st.end() && isAConcatenatedWord(suffix,st,dp)){ // it means the suffix is also a concatenated word
                return dp[word]=true;
            }
        }
        
        return dp[word]=false;
    }
//     bool isAConcatenatedWord(string &word,unordered_set<string> &st){
        
//         string prefix,suffix;
        
//         // O(maxLen*(maxLen+log(N)+maxLen*(maxLen+log(N)))
        
//         // O(L*(L)
//         // O(L*L) -> O(L^2)
//         for(int i=1;i<word.size();i++){ // O(L)
            
//             // These two combined will take O(L)
//             prefix=word.substr(0,i);
//             suffix=word.substr(i,word.size()-i);
            
//             // ~O(1) Average
//             if(st.find(prefix)!=st.end() && st.find(suffix)!=st.end()){// this is a concatenated word of two words
//                 return true;
                
//             }else if(st.find(prefix)!=st.end() && isAConcatenatedWord(suffix,st)){ // it means the suffix is also a concatenated word
//                 return true;
//             }
//         }
        
//         return false;
//     }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
        unordered_set<string> st(words.begin(),words.end());
        unordered_map<string,int> dp;
        vector<string> ans;
        
        // O(NL^2)
        for(auto &word:words){
            if(isAConcatenatedWord(word,st,dp)){
                ans.push_back(word);
            }
        }
        
        return ans;
    }
};