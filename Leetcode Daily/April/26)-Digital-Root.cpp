258. Add Digits

Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.
    
Approach is Digital Root :(  (Constantly adding digits untill a single digit)
    
class Solution {
public:
//     void getNewNum(int &num){
//         int n=num;
//         int sum=0;
//         while(n!=0){
//             sum+=n%10;
//             n/=10;
//         }
//         num=sum;
//     }
//     int addDigits(int num) {
        
//         while(num>=10){
//             getNewNum(num);
//         }
//         return num;
//     }
    
      int addDigits(int num) {
        
        if(num==0) return 0;
        else if(num%9==0) return 9;
        return num%9;
    }
};