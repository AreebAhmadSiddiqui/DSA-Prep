class Solution {
public:
    n of rows = 3

    noOfJump=3-1 * 2 = 4
    PAYPALISHIRING
    (indx)
    
    From 0 P plus 4 distacne a plus 4 distance h plus 4 distance n
    From 2 Y plus 4 I plus 4  10 r
    For 1 (middle rows basically) plus 4 is valid but in between index is taken by (j+noOfJump-(2*i)) for i==1 

    1 for a then 1+4-2 = 3 P then 5 for L then 5+4-(2)=7 S and so onn
   (0) P     (4)A      (8)H       (12)N
   (1) A (3)P (5)L (7)S(9)I (11)I (13)G
   (2) Y     (6)I      (10)R
    string convert(string s, int numRows) {
        
        if(numRows==1) return s;
        
        string ans="";
        
        int noOfJumps=(numRows-1)*2;
        
        // O(rows*n)
        for(int i=0;i<numRows;i++){
            for(int j=i;j<s.size();j+=noOfJumps){
                
                ans+=s[j];
                
                if(i>0 && i<numRows-1 && j+noOfJumps-i*2<s.size()){
                    ans+=s[j+noOfJumps-i*2];
                }
            }
        }
        
        return ans;
    }
};