Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.

Return the maximum product you can get.
class Solution {
public:
    int integerBreak(int n) {
        if(n<=3) return n-1;
        
        
        if(n%3==0) return pow(3,n/3);
        else if(n%3==1) return pow(3,n/3-1)*4;
        return pow(3,n/3)*2;
        
        Explanation
            
        // 2->  1,1
        // 3->  2,1
        // 4->  2,2
        // 5->  3,2
        // 6->  3,3
        // 7->  3,4
        // 8->  3,3,2
        // 9->  3,3,3
        // 10-> 3,3,4
        // 11-> 3,3,3,2
    }
};