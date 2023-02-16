// Har word ko i index pe break karo aur check karo ki kahin ye contain to ni hai agar hai to uske age wala bhi contain hona chahiye to recursively uspe check laga do

// Kuch points dimag mein honge doubt I mean

// tabulation mein bhi dhyan rakhna ki dp[i]=0 turant hi na kardena ya to condition laga ke karna ya fir uska hata do kyunki initially to zero se hi initialise kar rahe
class Solution {
private:
    int help(int i,string &s,unordered_set<string> &st,vector<int> &dp){
        
        if(i==s.size()) return 1; // why return 1 dekho yahan pe kab aega jab string exhaust ho gayi hogi aur ispe ane ka matlab jab string exhaust hui to wo st mein thi kyunki and condition hai to pehle wali agar false hui to yahan aega hi ni
        
        if(dp[i]!=-1) return dp[i];
        
        string prefix="";
        for(int j=i;j<s.size();j++){
            
            // mat lo dict={'keet'}
            // word = 'keet'

            prefix+=s[j]; // is prefix pe keet aega jab j=0..s.size() tak aya to st.find tru ho jaega aur j+1 yani j=size() chala jaega to use 1 hi to return karaoge agar ni karaya to dp[i]=1 hoga hi ni
            if(st.find(prefix)!=st.end() && help(j+1,s,st,dp)){ // is case baat kar raha
                return dp[i]=1;
            }
        }
        return dp[i]=0;
    }
    
    int tabulation(string s, vector<string>& wordDict){
        
        int n=s.size();
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        vector<int> dp(s.size()+1,0);
        
        dp[s.size()]=1;
        
        for(int i=n-1;i>=0;i--){
            string temp="";
            for(int j=i;j<s.size();j++){
                temp+=s[j];
                if(st.find(temp)!=st.end() && dp[j+1]){
                    dp[i]=1;
                }
            }
            // dp[i]=0; ye na likho kyunki agar maan lo wo update ho gaya wahan i to tum yahan use firse zero kar doge dekho recursion mein bhi return kar jate the jaise hi true hota tha 
        }
        
        return dp[0];
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        // For every i 
        
        // Check if the word till i is in the wordDict and same goes for the string from i+1
        
        
//         unordered_set<string> st(wordDict.begin(),wordDict.end());
//         vector<int> dp(s.size(),-1);
        
//         return help(0,s,st,dp);
        
        return tabulation(s,wordDict);
    }
};