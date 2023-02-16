
// You are given a string s of lowercase English letters and a 2D integer array shifts where shifts[i] = [starti, endi, directioni]. For every i, shift the characters in s from the index starti to the index endi (inclusive) forward if directioni = 1, or shift the characters backward if directioni = 0.

// Shifting a character forward means replacing it with the next letter in the alphabet (wrapping around so that 'z' becomes 'a'). Similarly, shifting a character backward means replacing it with the previous letter in the alphabet (wrapping around so that 'a' becomes 'z').

// Return the final string after all such shifts to s are applied.

Steps

a) Start aur end diya hai usmein sabhi ko increase karna hai ye padhte hi idea lag gaya ki prefix sum wala hai l pe +1 aur r+1 pe -1
b) bas ismein ek aur cheez add hai ki dir bhi diya hai dir agar zero hai to decrement karn hai warna increment to simpley 1 case mein jo karte ho wo kar do aur 0 case mein l ko -1 aur r+1 ko +1
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        string ans="";
        
        vector<int> prefix(s.size()+1,0);
        
        for(auto &vec:shifts){
            int start=vec[0];
            int end=vec[1];
            int dir=vec[2];
            
            if(dir==1){
                prefix[start]++;
                prefix[end+1]--;
            }else{
                prefix[start]--;
                prefix[end+1]++;
            }
        }
        
        for(int i=1;i<prefix.size();i++){
            prefix[i]=prefix[i]+prefix[i-1];
        }
        
        for(int i=0;i<prefix.size()-1;i++){
            int ascii=(s[i]-'a'+prefix[i])%26; // for handling values greater than 25
            if(ascii<0) ascii+=26; // for handling negative values
            
            ans+=(ascii+'a');
        }
        return ans;
    }
};