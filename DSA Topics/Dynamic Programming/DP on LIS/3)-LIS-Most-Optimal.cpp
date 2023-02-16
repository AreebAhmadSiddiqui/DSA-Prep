public:
    int findSmallestIndexGreaterThanEqualToNumsI(vector<int> &temp,int target){
        int start=0,end=temp.size()-1;
        
        while(start<end){
            int mid=start+(end-start)/2;
            
            if(target==temp[mid]) return mid;
            else if(target>temp[mid]){ 
                start=mid+1;
            }else{
                //potential answer
                end=mid;
            }
        }
        
        return end;
    }
    int lengthOfLIS(vector<int>& nums) {
        // int n=nums.size();
        // vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        // return help(n-1,n,nums,dp);
        
        // return tabulation(nums);
        
        
        // Optimised Code
        
        // BS + LIS
        
        
        vector<int> temp;
        temp.push_back(nums[0]);
        int len=1;
        
        for(int i=1;i<nums.size();i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
                len++;
            }else{ // do a bs and find the smallest index >= nums[i];
                
                int ind=findSmallestIndexGreaterThanEqualToNumsI(temp,nums[i]);
                temp[ind]=nums[i];
            }
        }
        
        return len;
    }