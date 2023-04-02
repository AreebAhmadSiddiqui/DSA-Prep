Successful Pairs of Spells and Potions
 
You are given two positive integer arrays spells and potions, of length n and m respectively, where spells[i] represents the strength of the ith spell and potions[j] represents the strength of the jth potion.

You are also given an integer success. A spell and potion pair is considered successful if the product of their strengths is at least success.

Return an integer array pairs of length n where pairs[i] is the number of potions that will form a successful pair with the ith spell.
    
Input: spells = [5,1,3], potions = [1,2,3,4,5], success = 7
Output: [4,0,3]
Explanation:
- 0th spell: 5 * [1,2,3,4,5] = [5,10,15,20,25]. 4 pairs are successful.
- 1st spell: 1 * [1,2,3,4,5] = [1,2,3,4,5]. 0 pairs are successful.
- 2nd spell: 3 * [1,2,3,4,5] = [3,6,9,12,15]. 3 pairs are successful.
Thus, [4,0,3] is returned.
    

class Solution {
private:
    int getLowerBound(vector<int> &potions,double target){
        int n=potions.size();
        int start=0;
        int end=n-1;
        int ans=n;
        
        while(start<=end){
            int mid=start+(end-start)/2;
            
            // Han thik hai lekin mujhe chota chaiye
            // to tu answer hai lekin tujhe kam bhi to ho sakta koi
            if(potions[mid]>=target){
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return ans;
    }
public:
    Approach
        
    1) Brute to ekdum asaan hai O(n2) ki
    2) Doosra maine socha ki O(n2) se kam O(nlogn) lag sakte to socha sorting kaise lagegi
    3) Dekh bhai tum spells ko to ni ched sakte
    4) Potions mein tumhe sirf multiplication se matlab hai 
    5) To tum agar potions ko sort kardo to tumhe wo least banda chahiye jiska mutiply success se zyada ho to wo tum lower bound ya bs ka concept laga sakte ho na
    6) Bas wahi kiya aur ye dekh
        
        x-> spell[i]
        y-> value jo multiply karega
        x*y>=success (ATQ)
        
        Find y such that
        y>=success/x;
    
        tumne sort kar diya hai to tumhe min y chahiye jo multiply ho to success se zyada de agar ye zyada hai to age wale sorted hai to wo to pakka zayad hoenge
        Bas wahi nikal lo
            
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        int n=potions.size();
            
        // O(mlogm)
        sort(potions.begin(),potions.end());
        vector<int> ans;
        
        // O(nlogm)
        for(auto &spell:spells){
            
            // Double mein nikalna
            double y=(success*1.0/spell);
            
            // Wo minIdx jisse aur age sab multiple mein zyada ho
            int minIdx=getLowerBound(potions,y);
            
            // Bas push back kardo
            int cnt=n-minIdx;
            
            ans.push_back(cnt);
        }
        return ans;
    }
};