Count Odd Numbers in an Interval Range

Given two non-negative integers low and high. Return the count of odd numbers between low and high (inclusive).
 
class Solution {
public:
    int countOdds(int low, int high) {
        
        I calucated between ranges the odd numbers and got to this formula
        see
                                 cntOds   diff(high-low)  Observation ( If any of low or high is odd then ans is diff/2+1 otherwise diff/2)
        4   5  6  7  8              2       4                4/2
        4   5  6  7  8  9           3       5                5/2+1
        5  6  7  8  9               3       4                4/2+1
        5  6  7  8  9    10         3       5                5/2+1
        int diff=high-low;
        if(low%2==0 && high%2==0) return diff/2;
        return diff/2+1;
    }
};