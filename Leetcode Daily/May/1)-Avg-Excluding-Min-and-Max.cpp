1491. Average Salary Excluding the min and max


You are given an array of unique integers salary where salary[i] is the salary of the ith employee.

Return the average salary of employees excluding the minimum and maximum salary. Answers within 10-5 of the actual answer will be accepted.
    

class Solution {
public:
    double average(vector<int>& salary) {
        
        double ans=0.0;
        
        int n=salary.size();
        double maxi=0,mini=salary[0];
        for(auto &it:salary){
            maxi=max(maxi,it*1.0);
            mini=min(mini,it*1.0);
            ans+=it;
        }
        ans-=(maxi+mini);
        
        return ans/(n-2);
    }
};