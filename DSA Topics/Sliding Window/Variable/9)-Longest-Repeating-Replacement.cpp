You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

 
class Solution {
private:
    int getMostFrequentElementCnt(vector<int> &charCnt){
        
        int maxi=0;
        for(int i=0;i<26;i++){
            maxi=max(maxi,charCnt[i]);
        }
        return maxi;
    }
public:
    int characterReplacement(string &s, int k) {
        
       
        // In our subarray we can flip k elements baaki jo elements hai wo same hone chahiye
        // We need to find max Subarray size with at most k flips and the other elements should be unique
        // For getting the flipCount how can we get it
        
        // Window Size - mostFrequentElementCnt = flips we did (Kyunki jo sabse zyda bar a raha hai use rahne do aur jo kam baar a reh unhe jo zyada a raha hai usmein change kardo)
        
        int i=0;
        int j=0;
        int ans=0;
        int n=s.size();
        vector<int> charCnt(26,0);
        
//         // O(n*26+n*26)
//         while(j<n){
            
//             // Do stuff
//             charCnt[s[j]-'A']++;
            
//             int mostFrequentElementCnt=getMostFrequentElementCnt(charCnt);
//             int windowSize=j-i+1;
            
//             if(windowSize-mostFrequentElementCnt<=k){ // it is okay we can add
//                 ans=max(ans,windowSize);
//             }else{ // we definitely wanna remove
                
//                 while(windowSize-mostFrequentElementCnt>k){
//                     charCnt[s[i]-'A']--;
//                     mostFrequentElementCnt=getMostFrequentElementCnt(charCnt);
//                     i++;
//                     windowSize=j-i+1;
//                 }
//             }
//             j++;
//         }
        
        // O(same Tc But more readable)
        while(j<n){
            
            // Do stuff
            charCnt[s[j]-'A']++;
            
            if((j-i+1)-getMostFrequentElementCnt(charCnt)>k){
                charCnt[s[i]-'A']--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        
        return ans;
    }
};