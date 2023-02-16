class Solution {
private:
    bool isPossible(int maxPoint,int k,vector<int> &nums){
        int housesRobbed=0;
        int i=0;
        int maxi=0;
        int cnt=0;
        
        // Tum jis point pe ho wahan steal karna better hai na bajae iske ki tum age jao aur check karo isliye greedily tum steal kar lo
        for(int i=0;i<nums.size();){
            if(nums[i]<=maxPoint){
                cnt++;
                i+=2;
            }else{
                housesRobbed+=cnt;
                cnt=0;
                i++;
            }
        }
        housesRobbed+=cnt;
        return housesRobbed>=k;
    }
public:
    int minCapability(vector<int>& nums, int k) {
        
        int start=1e9,end=0;
        for(int i=0;i<nums.size();i++){
            start=min(start,nums[i]);
            end=max(end,nums[i]);
        }
        
        int ans=0;
        while(start<=end){
            int mid=start+(end-start)/2;
            
            if(isPossible(mid,k,nums)){
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        
        return ans;
    }
};