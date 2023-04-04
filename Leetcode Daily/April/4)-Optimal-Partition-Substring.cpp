Optimal Partition of String

Given a string s, partition the string into one or more substrings such that the characters in each substring are unique. That is, no letter appears in a single substring more than once.

Return the minimum number of substrings in such a partition.

Note that each character should belong to exactly one substring in a partition.
    
    
Approach

1) Dekh bhai tujhe minimum karna hai to tu jitna max substring le sakta hai jismein koi repeat na ho wohi to lega
2) To bas greedy laga do simply

class Solution {
public:
    int partitionString(string s) {
        
        vector<int> hash(26,0);
        
        int i=0;
        int j=0;
        int n=s.size();
        int cnt=1;
        while(j<n){
            
            // Do cal
            char ch=s[j];
            hash[ch-'a']++;
            
            if(hash[ch-'a']>1){

                // Jaise hi repeat hua cnt bhada do 
                cnt++;
                
                // aur sare hash ko minus kar do
                // Zero na karna directly kyunki curr j wala bhi zero ho jaega to use to rakhna hai na kyunki age j++ ho raha isliye
                // Ni to agar zero kar rahe ho to j ki condition alag se lagani padegi 
                // template lekin aisa ni kahta na isliye tum bhi na karo

                
                while(i<j){
                    hash[s[i]-'a']--;
                    i++;
                }
            }
            j++;
        }
        return cnt;
    }
};