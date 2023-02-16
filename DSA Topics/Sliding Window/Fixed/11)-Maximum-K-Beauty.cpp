class Solution {
public:
    int divisorSubstrings(int num, int k) {
        
        string nums=to_string(num);
        int cnt=0;
        int i=0;
        int j=0;
        string n="";
        while(j<nums.size()){
            
            // DO stuff
            n+=nums[j];
            
            if(j-i+1==k){ // window reached
                
                // calculations
                int number=stoi(n);
                if(number!=0 && num%number==0) cnt++;
                
                // Shrink window
                n.erase(0,1); // starting from 1 erase 1 length
                i++;
            }
            j++;
        }
        return cnt;
    }
};