1456. Maximum Number of Vowels in a Substring of Given Length

Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.
    
    
class Solution {
private:
    bool isVowel(char ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }
public:
    int maxVowels(string s, int k) {
        
        int maxi=0;
        int cntVowel=0;
        for(int i=0;i<k;i++){
            if(isVowel(s[i])){
                maxi++;
            }
        }
        
        
        int n=s.size();
        int i=0;
        int j=0;
        while(j<n){
            if(isVowel(s[j])){
                cntVowel++;
            }
            if(j-i+1==k){
                maxi=max(maxi,cntVowel);
                if(isVowel(s[i])){
                    cntVowel--;
                }
                i++;
            }
            j++;
        }
        return maxi;
    }
};