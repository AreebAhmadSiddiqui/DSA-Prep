// Ismein hame * ki values ke hisab se chalna tha 
// Bas kuch if conditions extra hui baaki sab decode ways jaisa hi tha
class Solution {
private:
    int mod=1000000007;
    int getWays(int start,int end,string &s){
        
        if(s[end]=='*' && start==end){ // One digit
            return 9; // hamesha
        }
        
        if(s[end]=='*' && s[start]!='*'){ // two digit to agar pehli digit 1 ya 2 hai tabhi valid hoga
            
            int firstDigit=s[start]-'0';
            
            if(firstDigit==1) return 9; //(11-19)
            if(firstDigit==2) return 6; //(21-26)
            return 0;
        }
        
        if(s[start]=='*' && s[end]!='*'){ // {*_} wala case (ye bhi true hoga hamesha agar end 1 se 6 ke beech mein ho)
            int secondDigit=s[end]-'0';
            if(secondDigit>=0 && secondDigit<=6) return 2; // (10,20) (11,21) (12,22) .... (16,26)
            if(secondDigit>6) return 1; //(1 (>6)) -> // (17,18,19)
        }
        
        if(s[start]=='*' && s[end]=='*'){ // {**} wala case 
            
            return 15; //(11-19 and 21-26)
        }
        
        int num=stoi(s.substr(start,end-start+1));  // O(2)
        
        return num>=1 && num<=26;
    }
//     int help(int i,string &s,vector<int> &dp){
        
//         if(s[i]=='0') return 0;
//         if(i>=s.size()) return 1;
        
//         if(dp[i]!=-1) return dp[i];
//         int oneDigit=0,twoDigit=0;
        
//         // One digit
//         oneDigit=(getWays(i,i,s)%mod*1ll*help(i+1,s,dp)%mod)%mod;
        
//         // Two digit
//         if(i+1<s.size()) twoDigit=(getWays(i,i+1,s)%mod*1ll*help(i+2,s,dp)%mod)%mod;
        
//         return dp[i]=(oneDigit+twoDigit)%mod;
//     }
    
//     int tabulation(string &s){
        
//         vector<int> dp(s.size()+2,0);
        
//         // Base Case
//         dp[s.size()]=1;
        
//         for(int i=s.size()-1;i>=0;i--){
            
//             if(s[i]!='0'){
//                 int oneDigit=0,twoDigit=0;

//                 // One digit
//                 oneDigit=(getWays(i,i,s)%mod*1ll*dp[i+1]%mod)%mod;

//                 // Two digit
//                 if(i+1<s.size()) twoDigit=(getWays(i,i+1,s)%mod*1ll*dp[i+2]%mod)%mod;

//                 dp[i]=(oneDigit+twoDigit)%mod;
//             }else{
//                 dp[i]=0;
//             }
//         }
//         return dp[0];
//     }
    int spaceOptimisation(string &s){
        
        int prev1,prev2,curr;
        
        // Base Case
        prev1=1;
        
        for(int i=s.size()-1;i>=0;i--){
            
            if(s[i]!='0'){
                int oneDigit=0,twoDigit=0;

                // One digit
                oneDigit=(getWays(i,i,s)%mod*1ll*prev1%mod)%mod;

                // Two digit
                if(i+1<s.size()) twoDigit=(getWays(i,i+1,s)%mod*1ll*prev2%mod)%mod;

                curr=(oneDigit+twoDigit)%mod;
            }else{
                curr=0;
            }
            
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
public:
    int numDecodings(string s) {
        
        // vector<int> dp(s.size()+1,-1);
        // return help(0,s,dp);
        // return tabulation(s);
        return spaceOptimisation(s);
    }
};