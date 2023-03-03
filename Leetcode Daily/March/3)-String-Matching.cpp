 // Rabin Karp
 // KMP
  
// ye sab lagana ismein

// Ye to brute force hai
 Find the Index of the First Occurrence in a String

 class Solution {
    public:
    int strStr(string haystack, string needle) {
        int n=needle.size();
        
        int i=0;

        // O(N * 2M)
        while(i+n<=haystack.size()){

            // O(M)
            string s=haystack.substr(i,n);
            
            // O(M)
            if(s==needle) return i;
            i++;
        }
        
        return -1;
    }
};