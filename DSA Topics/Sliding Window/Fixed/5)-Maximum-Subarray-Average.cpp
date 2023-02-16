class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum=0;
        
        int i=0;
        int j=0;
        double ans=-100005;
        while(j<nums.size()){
            
            // Do stuff
            sum+=nums[j];
            if(j-i+1==k){ // reached the window threshold
                
                
                // Calculate answer
                double avg=sum/k*1.0;
                ans=max(ans,avg);
                //Decrease window
                sum-=nums[i];
                i++;
            }
            j++;
        }
        
        return ans;
    }
};