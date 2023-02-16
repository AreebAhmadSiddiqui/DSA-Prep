// A message containing letters from A-Z can be encoded into numbers using the following mapping:

// 'A' -> "1"
// 'B' -> "2"
// ...
// 'Z' -> "26"
// To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:

// "AAJF" with the grouping (1 1 10 6)
// "KJF" with the grouping (11 10 6)
// Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

// Given a string s containing only digits, return the number of ways to decode it.

// The test cases are generated so that the answer fits in a 32-bit integer.

class Solution {
private:
    bool isPossible(int start,int end,string &s){
        
        int charCode=stoi(s.substr(start,end-start+1));
        return charCode>=1 && charCode<=26;
    }
//     int help(int i,string &s,vector<int> &dp){
//         if(s[i]=='0') return 0; // because if leading zero aya to age na jane do decode ni kar paenge
        
//         if(i>=s.size()) return 1;
        
//         if(dp[i]!=-1) return dp[i];
        
//         int oneDigit=0,twoDigit=0;
        
//         if(isPossible(i,i,s)) oneDigit=help(i+1,s,dp);
        
//         if(i+1<s.size() && isPossible(i,i+1,s)) twoDigit=help(i+2,s,dp);
        
        
//         return dp[i]=oneDigit+twoDigit;
//     }
    
//     int tabulation(string &s){
//         int n=s.size();
//         vector<int> dp(n+2,0);
        
//         // Base Case
//         dp[n]=1;
        
//         for(int i=n-1;i>=0;i--){
//             if(s[i]=='0') dp[i]= 0;
//             else{
//                 int oneDigit=0,twoDigit=0;

//                 if(isPossible(i,i,s)) oneDigit=dp[i+1];

//                 if(i+1<s.size() && isPossible(i,i+1,s)) twoDigit=dp[i+2];

//                 dp[i]=oneDigit+twoDigit;
//             }
//         }
//         return dp[0];
//     }
    
    int spaceOptmisation(string &s){
        int n=s.size();
        int prev1,prev2,curr;
        
        // Base Case
        prev1=1;
        
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0') curr= 0;
            else{
                int oneDigit=0,twoDigit=0;

                if(isPossible(i,i,s)) oneDigit=prev1;

                if(i+1<s.size() && isPossible(i,i+1,s)) twoDigit=prev2;

                curr=oneDigit+twoDigit;
            }
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
public:
    int numDecodings(string s) {
        
        // int n=s.size();
        // vector<int> dp(n+1,-1);
        // return help(0,s,dp);
        
        // return tabulation(s);
        return spaceOptmisation(s);
    }
};