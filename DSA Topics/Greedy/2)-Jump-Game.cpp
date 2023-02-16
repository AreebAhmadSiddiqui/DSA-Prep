Dekho agar ham kisi bhi time kisi index pe ae jo ki max se zayda ho gaya iska matlab meere peeche koi bhi banda aisa ni ho jo ki maxJump ko mujhse age le jae to return false

baaaki to hamesha pahunch hi jaega agar 0 na ho to 

1 , 2, 2, 0,0,1   (is mein dekho ham 1 se 2 ja sakte hai 2 se pehle 0 se aur doosre 2 se doosre zero pe lekin usse zyada ni ja pae to jab ham last 1 pe aenge to return false karna padega kyunki peeche koi bhi banda ni hai to yahan tak a pae)  lekin agar doosre 2 ko 3 kar diya tab return true hoga
    2
   / \
  2   \
 /     \       1
1       \     /
         0__ 0
class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int maxReachableIndex=0;
        int currPos=0;
        
        while(currPos<nums.size()){
            
            if(currPos>maxReachableIndex) return false;
            int reachableIndexFromCurrPos=currPos+nums[currPos];
            
            maxReachableIndex=max(maxReachableIndex,reachableIndexFromCurrPos);
            currPos++;
        }
        
        return true;
    }
};