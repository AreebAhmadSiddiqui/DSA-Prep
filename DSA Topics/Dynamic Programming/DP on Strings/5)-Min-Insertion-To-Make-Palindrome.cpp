// STEPS

a) Find the longest palindroming subs and keep it intact and just subtract the string size - lps

ex  a r e e r b // lps is 4 r e e r
    a a r e e r b b // min insertion were 2 i.e (6-4)
class Solution {
private:
    int spaceOptimised(string &s1,string &s2){
        vector<int> prev(s2.size()+1,0),curr(s2.size()+1,0);
        
       // Base Case
        for(int j=0;j<s2.size();j++) prev[j]=0;
        
        for(int i=1;i<=s1.size();i++){
            curr[0]=0;
            for(int j=1;j<=s2.size();j++){
                if(s1[i-1]==s2[j-1]){
                   curr[j]=1+prev[j-1];
                }
                else curr[j]=max(prev[j],curr[j-1]);
            }
            prev=curr;
        }
        
        return prev[s2.size()];
    }
    int longestCommonSubsequence(string text1, string text2) {
         return spaceOptimised(text1,text2);
    }
public:
    int minInsertions(string s) {
        string s1=s;
        reverse(s1.begin(),s1.end());
        
        return s.size()-longestCommonSubsequence(s,s1);
    }
};