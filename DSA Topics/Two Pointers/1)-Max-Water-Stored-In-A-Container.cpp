class Solution {
public:
    // Steps

    a) Baaki sab to samjh a raha hoga lekin jo chota hai use hi kyun change kar rahe ho ye question hoga dimag main?

    Dekho agar left chota hai right se to two options hai agar left ko bhadya
    i) left wali value or choti ho jae to answer kam ho jaega
    ii) ya badi ho jae to answer badh sakta maybe

    Wahi baat agar right ko chalane ki baat ae to two choices wahan bhi hai

    i) agar right ko kam kiya aur choti value hui to answer kam hoga kyunki width same rahi lekin length kam ho gaya
    ii) aur agar badi value bhi ae tab bhi answer kam hoga 

    // Therefor left ko bhadane main answer badh sakta hai lekin jo max hai use kam change karne main kabhi fayda ni hoga
    int maxArea(vector<int>& height) {
        
        int ans=0;
        int left=0,right=height.size()-1;
        while(left!=right){
            ans=max(ans,(right-left)*min(height[left],height[right]));
            
            if(height[left]<height[right]){
                left++;
            }else{
                right--;
            }
        }
        
        return ans;
    }
};