String Compression

Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.
    

class Solution {
public:
    int compress(vector<char>& chars) {
        
        int n=chars.size();
        int i=0;
        int j=0;
        int cnt=0;
        int ans=0;
        int startIdx=0;
        
        // O(n+log(cnt))
        while(j<=n){

            // equal to n tak isliye laya agar na lata to else wala condition neeche bhi likni padti
            if(j!=n && chars[i]==chars[j]){
                cnt++;
                j++;
            }else{
                ans+=1; // for character
                
                chars[startIdx++]=chars[i];
                // For the cnt
                if(cnt>1){ // 1 size wale ko add ni karna na isliye
                    
                    // log(cnt)
                    string x=to_string(cnt);
                    
                    //log(cnt)
                    for(int k=0;k<x.size();k++){
                        chars[startIdx++]=x[k];
                        ans++;
                    }
                }
                if(j==n) break;
                i=j;
                cnt=0;
            }
        }
        return ans;
    }
};