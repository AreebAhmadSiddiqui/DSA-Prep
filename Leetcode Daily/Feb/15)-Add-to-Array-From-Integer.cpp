Add to Array-Form of Integer

The array-form of an integer num is an array representing its digits in left to right order.

For example, for num = 1321, the array form is [1,3,2,1].
Given num, the array-form of an integer, and an integer k, return the array-form of the integer num + k.
    
Approach

Simply jaisa addition karte ho carry ko leke waise kar diya karo aur haan dhyan rakhna aise case mein loop mein hi kar diya karo warna multipli loops likhne padte hai ganda lagta hai 

Carry ko na bhoola karo last mein noob


class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        int carry=0;
        int i=num.size()-1;
        
        // O(max(n,log10k))
        while(i>=0 || k!=0){
            int sum=0;
            if(i>=0) sum+=num[i];
            if(k!=0) sum+=k%10;
            
            sum+=carry;
            ans.push_back(sum%10);
            carry=sum/10;
            
            i--;
            k/=10;
        }
        
        if(carry!=0) ans.push_back(carry);
        
        // O(max(n,log10k))
        reverse(ans.begin(),ans.end());
        return ans;
    }
};