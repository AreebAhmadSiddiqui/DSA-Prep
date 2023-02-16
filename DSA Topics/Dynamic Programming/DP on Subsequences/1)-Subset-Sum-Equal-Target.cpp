Steps
a) Further space optimised bhi ho sakta hai aur dhyan dena agar target a[0] se kam ho gaya to dikkat aegi line base case mein
class Solution{   
private:
    bool help(int i,int sum,vector<int> &arr,vector<vector<int>> &dp){
        if(i==0){
            return sum==arr[0];
        }
        
        if(dp[i][sum]!=-1) return dp[i][sum];
        
        bool pick=help(i-1,sum-arr[i],arr,dp);
        bool notPick=help(i-1,sum,arr,dp);
        
        return  dp[i][sum]=pick || notPick;
    }
    bool tabulation(vector<int>arr, int sum){
        vector<vector<int>> dp(arr.size(),vector<int> (sum+1,0));
        
        // Base case
        if (arr[0] <= sum)
            dp[arr[0]] = 1;
        
        for(int i=1;i<arr.size();i++){
            for(int k=0;k<=sum;k++){
                bool pick=false;
                if(k-arr[i]>=0) pick=dp[i-1][k-arr[i]];
                bool notPick=dp[i-1][k];
                
                dp[i][k]=pick || notPick;
            }
        }
        
        return dp[arr.size()-1][sum];
        
    }
    bool spaceOptimised(vector<int>arr, int sum){
        vector<int> prev(sum+1,0),curr(sum+1,0);
        
        // Base case
        if (arr[0] <= sum)
            prev[arr[0]] = 1;
        
        for(int i=1;i<arr.size();i++){
            for(int k=0;k<=sum;k++){
                bool pick=false;
                if(k-arr[i]>=0) pick=prev[k-arr[i]];
                bool notPick=prev[k];
                
                curr[k]=pick || notPick;
            }
            prev=curr;
        }
        
        return prev[sum];
        
    }
    bool furtherSpaceOptimised(vector<int>arr, int sum){
        vector<int> prev(sum+1,0);
        
        // Base case
        if (arr[0] <= sum)
            prev[arr[0]] = 1;
        
        for(int i=1;i<arr.size();i++){
            for(int k=sum;k>=0;k--){
                bool pick=false;
                if(k-arr[i]>=0) pick=prev[k-arr[i]];
                bool notPick=prev[k];
                
                prev[k]=pick || notPick;
            }
        }
        
        return prev[sum];
        
    }
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // vector<vector<int>> dp(arr.size(),vector<int> (sum+1,-1));
        // return help(arr.size()-1,sum,arr,dp);
        
        // return tabulation(arr,sum);
        return spaceOptimised(arr,sum);
    }
};