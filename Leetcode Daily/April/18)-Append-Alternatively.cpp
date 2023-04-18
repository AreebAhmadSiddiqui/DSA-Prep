1768. Merge Strings Alternately

You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.
    
    
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0;
        int j=0;
        int n=word1.size();
        int m=word2.size();
        
        string ans="";
        while(i<n || j<m){
            if(i<n){
                ans.push_back(word1[i++]);
            }
            if(j<m){
                ans.push_back(word2[j++]);
            }
        }
        return ans;
    }
};