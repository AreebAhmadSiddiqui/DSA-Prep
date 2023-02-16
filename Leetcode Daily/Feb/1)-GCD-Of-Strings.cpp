Given an integer array nums, return the greatest common divisor of the smallest number and largest number in nums.

The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.

class Solution {
private:
    bool canBeADivisor(int length,string &s1,string &s2){
        int m=s1.size();
        int n=s2.size();
        
        if(m%length!=0 || n%length!=0) return false; // basically it is not a divisor of someone
        
        string temp1="";
        string temp2="";
        
        string commonPrefix=s1.substr(0,length);
        int i=0;
        while(i<m){
            temp1+=commonPrefix;
            i+=length;
        }
        
        int j=0;
        while(j<n){
            temp2+=commonPrefix;
            j+=length;
        }
        
        return temp1==s1 && temp2==s2;
    }
public:
    
    // O(min(m,n)*(m+n))
    
    // Har length pe jake check karo ki is length ki susbtr banayi to kya main s1 aur s2 pa sakta hun agar haan to asnwer ni to peeche dekho shayad mile
    
//     string gcdOfStrings(string str1, string str2) {
        
//         // Take min string and for each and every length of its check it length divides both the string if so check 
//         // for both string whether this length provides the same prefix of suffix
//         // It is better to start from the end so that as soon as we get the answer we can return it because it will be the maximum
        
//         int m=str1.size();
//         int n=str2.size();
//         int minSize=min(m,n);
        
//         for(int length=minSize;length>=1;length--){
            
//             if(canBeADivisor(length,str1,str2)) return str1.substr(0,length);
//         }
        
//         return "";
//     }
    
    
    // O(log(min(m,n)))
    string gcdOfStrings(string str1, string str2) {
        
        // Agar dono string ko x divide karta hai to
        // s1= m * x (m matlab jitni baar a rhaa hai)
        // s2= n * x (n matlab wo jitni baar a rhaa hai)
        
        // s1+s2==s2+s2 to hoga hi agar ni hai iska matlab wo same prefix bhi ni share karte
        // aur agar karte hai to min factor jo dono ko divide karde wahi answer hai
        int length=gcd(str1.size(),str2.size());
        return str1+str2==str2+str1 ? str1.substr(0,length) : "";
    }
};