class Solution {
private:
     // No need for it
//     int getMax(int i,int j,vector<int> &nums){
        
//         int maxi=0;
        
//         while(i<=j){
//             maxi=max(maxi,nums[i]);
//             i++;
//         }
        
//         return maxi;
//     }
    int f(int i,int n,int k,vector<int> &arr,vector<int> &dp){
        if(i==n) return 0;
        
        if(dp[i]!=-1) return dp[i];
        
        int maxi=-1e9;
        int maxEle=0;
        for(int j=i;j<min(n,i+k);j++){ // at most k partions
            maxEle=max(maxEle,arr[j]);
            int sum=maxEle*(j-i+1) + f(j+1,n,k,arr,dp); // i am partitionin here
            maxi=max(maxi,sum);
        }
        
        return dp[i]=maxi;
    }
    int tabulation(vector<int> &arr,int k){
        
        vector<int> dp(arr.size()+1,0);
        int n=arr.size();
        
        // Base Case
        dp[n]=0;
        
        for(int i=n-1;i>=0;i--){
            int maxi=-1e9;
            int maxEle=0;
            for(int j=i;j<min(n,i+k);j++){ // at most k partions
                maxEle=max(maxEle,arr[j]);
                int sum=maxEle*(j-i+1) + dp[j+1]; // i am partitionin here
                maxi=max(maxi,sum);
            }
            dp[i]=maxi;
        }
        
        return dp[0];
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
//         vector<int> dp(arr.size(),-1);
        
//         return f(0,arr.size(),k,arr,dp);
        
        return tabulation(arr,k);
    }
};