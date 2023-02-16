STEPS

a) Yahan pe ham kya kar rahe dekho
b) pehle ke sare zero ko skip kar do unko change karke koi fayda ni kyunki wo already monotone mein hai
c) lekin agar one aya to use cnt karo kyunki ho sakta hai zero ko flip karne se ache one ko flip kar dein
d) aur agar zero aya hai cntOne 0 ni hai iska matlab ye potential canditate hai flip ka
e) to isko count karo aur agar ki samy zero ko flip karna zyada ho jae one ko flip karne se to one ko flip kar do yan flip count mein min le lo
f) Take example 

// 0101100011000 and dry run it
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        
        int oneCount=0;
        int flipCount=0;
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                
                if(oneCount==0) continue; // skip the initial zeroes
                
                else flipCount++;
            }
            
            else oneCount++;
            
            if(flipCount>oneCount) flipCount=oneCount;
        }
        
        return flipCount;
    }
};