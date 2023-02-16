You are given an integer array nums and an integer k.

Split the array into some number of non-empty subarrays. The cost of a split is the sum of the importance value of each subarray in the split.

Let trimmed(subarray) be the version of the subarray where all numbers which appear only once are removed.

For example, trimmed([3,1,2,4,3,4]) = [3,4,3,4].
The importance value of a subarray is k + trimmed(subarray).length.

For example, if a subarray is [1,2,3,3,3,4,4], then trimmed([1,2,3,3,3,4,4]) = [3,3,3,4,4].The importance value of this subarray will be k + 5.
Return the minimum possible cost of a split of nums.

A subarray is a contiguous non-empty sequence of elements within an array.


class Solution {
private:
    int f(int i,vector<int> &nums,int k,vector<vector<int>> &trimmed,vector<int> &dp){
        if(i==nums.size()){
            return 0;
        }
        
        if(dp[i]!=-1) return dp[i];
        
        int mini=INT_MAX;
        for(int j=i;j<nums.size();j++){
            int cost=k+trimmed[i][j]+f(j+1,nums,k,trimmed,dp);
            mini=min(mini,cost);
        }
        
        return dp[i]=mini;
    }
    
    int tabulation(vector<int> &nums,int k,vector<vector<int>> &trimmed){
        vector<int> dp(nums.size()+1,0);
        
        // Top-Down  i->  0 -> n;
                     // j->  i -> n;
        
        // Base case 
        dp[nums.size()]=0;
        
        for(int i=nums.size()-1;i>=0;i--){
             int mini=INT_MAX;
            for(int j=i;j<nums.size();j++){
                int cost=k+trimmed[i][j]+dp[j+1];
                mini=min(mini,cost);
            }

            dp[i]=mini;
        }
        
        return dp[0];
    }
public:
    int minCost(vector<int>& nums, int k) {
        
        // Normal DP solution is O(N3)
        // So we need to do something about this importance value what can it be
        // Can we precompute it?
        
        vector<vector<int>> trimmed(nums.size(),vector<int> (nums.size(),0));
        
        for(int i=0;i<nums.size();i++){
            
            vector<int> mp(1001,0);
            int importanceCount=0;
            
            for(int j=i;j<nums.size();j++){
                mp[nums[j]]++;
                
                // if(mp[nums[j]]<=1) continue; // as we dont need one freq ( but this was a mistake as agar continue likha to agar koi index j baad mein aya jiska count 1 tha to skip ho jaega lekin usko apne pichle value ko lena isliye isko hata do take examle)
                
                // 1,2,1,2,1,3,3
                
//                 i=4 abhi ak importance count is 5 but jaise hi i-5 pa aya to skipe ho gaya aur trimmed[i][j] mein zero chala gaya jabki use 5 lena tha isliye dont write this line
                if(mp[nums[j]]==2){ // it means we need to count it twice as we skipped when it was one
                    importanceCount+=2;
                }else if(mp[nums[j]]>2){// simply count
                    importanceCount+=1;
                }
                
                trimmed[i][j]=importanceCount; // for subarray i...j
            }   
        }
        
        // vector<int> dp(nums.size(),-1);
        // return f(0,nums,k,trimmed,dp);
        
        return tabulation(nums,k,trimmed);
    }
};