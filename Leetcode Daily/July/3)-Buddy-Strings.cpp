859. Buddy Strings

Given two strings s and goal, return true if you can swap two letters in s so the result is equal to goal, otherwise, return false.

Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at s[i] and s[j].

For example, swapping at indices 0 and 2 in "abcd" results in "cbad".
    
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        
        int cnt=0;
        int n=s.size();
        int m=goal.size();
        
        if(n!=m) return false;
        
        vector<int> cntArr(26,0);
        if(s==goal){
            // There should be atleast two same characters to swap
            for(auto &it:s) cntArr[it-'a']++;
            
            for(auto &it:cntArr) if(it>=2) return true;
        }else{
            
            // There should be two indices where the characters are not matching
            vector<int> diff;
            for(int i=0;i<n;i++){
                if(s[i]!=goal[i]) diff.push_back(i);
            }
            
            return diff.size()==2 && s[diff[0]]==goal[diff[1]] && s[diff[1]]==goal[diff[0]];
        }
        
        return false;
    }
};