1318. Minimum Flips to Make a OR b Equal to c

Given 3 positives numbers a, b and c. Return the minimum flips required in some bits of a and b to make ( a OR b == c ). (bitwise OR operation).
Flip operation consists of change any single bit 1 to 0 or change the bit 0 to 1 in their binary representation.
    
Approach

a) Bhai last se first tak ao
b) agar zero hai to dono zero honge to zero flip aur agar dono one hue to 2 flips otherwise 1 flip
c) agar one hai to dono mein se koi bhi ek one hua to zero flips aur agar dono zero hue to 1 flip

class Solution {
private:
    int getFlips(int a,int b,int c){
        if(c==0){
            return a==0 && b==0 ? 0 : a==1 && b==1 ? 2 : 1;
        }else{
            return !(a==1 || b==1);
        }
        return 0;
    }
public:
    int minFlips(int a, int b, int c) {
        
        int minFlipCnt=0;
        
        while(c!=0 || a!=0 || b!=0){
            
            int lastBitA = a==0 ? 0 : a&1;
            int lastBitB = b==0 ? 0 : b&1;
            int lastBitC = c==0 ? 0 : c&1;
            
            minFlipCnt+=getFlips(lastBitA,lastBitB,lastBitC);
            
            c>>=1;
            a>>=1;
            b>>=1;
        }
        
        return minFlipCnt;
    }
};