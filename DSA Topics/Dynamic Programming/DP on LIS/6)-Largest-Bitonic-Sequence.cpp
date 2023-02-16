
#include<bits/stdc++.h>
using namespace std;
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	        vector<int> dp1(nums.size(),1);
	        vector<int> dp2(nums.size(),1);
    
           
            for(int i=0;i<nums.size();i++){
                for(int j=0;j<i;j++){
                    if(nums[j]<nums[i] && dp1[j]+1>dp1[i]){
                        dp1[i]=dp1[j]+1;
                    }
                }   
            }
            
           
            for(int i=nums.size()-1;i>=0;i--){
                for(int j=nums.size()-1;j>i;j--){
                    if(nums[j]<nums[i] && dp2[j]+1>dp2[i]){
                        dp2[i]=dp2[j]+1;
                    }
                }
                
            }
            
            int ans=0;
            for(int i=0;i<nums.size();i++){
                ans=max(ans,dp1[i]+dp2[i]-1); // why minus 1 because a element would be counted twice
            }
            
            return ans;
	}
};