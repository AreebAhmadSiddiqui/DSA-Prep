You have a bomb to defuse, and your time is running out! Your informer will provide you with a circular array code of length of n and a key k.

To decrypt the code, you must replace every number. All the numbers are replaced simultaneously.

If k > 0, replace the ith number with the sum of the next k numbers.
If k < 0, replace the ith number with the sum of the previous k numbers.
If k == 0, replace the ith number with 0.
As code is circular, the next element of code[n-1] is code[0], and the previous element of code[0] is code[n-1].

Given the circular array code and an integer key k, return the decrypted code to defuse the bomb!

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        
        int n=code.size();
        vector<int> ans(n,0);
        if(k==0) return ans;
        
        int sign = k > 0 ? 1 : -1;
        
        k*=sign;
        int sum=0;
        int i=0;
        int j=0;
        while(j<2*n){
            
            // Do stuff
            sum+=code[j%n];
            
            if(j-i+1==k){// reached window end
                
                //Calculations
                if(sign < 0){ // means previous sum
                    // Agar sign negative hoga iska matlab ye sum ham j+1th guy ko dena hai
                    ans[(j+1)%n]=sum;
                }else{
                    // Agar sign positive hoga iska matlab ye sum ham i-1th guy ko dena hai (i-1 neg bhi ho sakt to use handle karne ke liye +n kar diya)
                    ans[(i-1+n)%n]=sum;
                }
                
                // Shrink Window
                sum-=code[i%n];
                i++;
            }
            j++;
        }
        
        return ans;
    }
};