You are given two 0-indexed binary strings s and target of the same length n. You can do the following operation on s any number of times:

Choose two different indices i and j where 0 <= i, j < n.
Simultaneously, replace s[i] with (s[i] OR s[j]) and s[j] with (s[i] XOR s[j]).
For example, if s = "0110", you can choose i = 0 and j = 2, then simultaneously replace s[0] with (s[0] OR s[2] = 0 OR 1 = 1), and s[2] with (s[0] XOR s[2] = 0 XOR 1 = 1), so we will have s = "1110".

Return true if you can make the string s equal to target, or false otherwise.

class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        
        s t    xor orz
        0 0     0  0
        1 0     1  1
        1 1     0  1
            
        // It means we can create a zero or a one if we have atleast one 1;
        // It doesn't matter if we have a zero or not even if we have all ones we can convert them to 1 and 0
            
        // But if we have zeros then we cannot convert it into one
        // So you just need to check if your source has zero one and target zero one
        // if not then return false else return true
        int cntOneInSource=0,cntOneInTarget=0;
        
        for(auto ch:s){
            if(ch=='1') cntOneInSource++;
        }
        
        for(auto ch:target){
            if(ch=='1') cntOneInTarget++;
        }
        
        if(cntOneInSource==0 && cntOneInTarget!=0 || cntOneInSource!=0 && cntOneInTarget==0) return false;
        return true;
    }
};