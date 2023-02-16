class Solution {
public:
    
    // Aur haan ye dhyan dena ki subseq ni subset poocha hai to sort karna hi padega
    bool hasDifferenceOfOne(string &a,string &b){ // a is bada b is chota
        if(a.size()-b.size()!=1) return false;
        
        cout<<a<<" "<<b<<'\n';
        int i=0;
        int j=0;
        while(i<a.size()){  // consider abc and ab  here j would be at 2 and i=2 so it will return false isliye j<b.size() ko neeche le lo
            if(j<b.size() && a[i]==b[j]){
                i++;
                j++;
            }
            else i++; // only bigger one
        }
        cout<<i<<" "<<j<<'\n';
        return i==a.size() && j==b.size();
    }
    static bool comp(string &a,string &b){
         return a.size()<b.size();
    }
    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(),words.end(),comp);
        vector<int> dp(words.size(),1);
        
        int ans=0;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<i;j++){
                if(hasDifferenceOfOne(words[i],words[j]) && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                }
            }
            ans=max(ans,dp[i]);
        }
        
        return ans;
    }
};