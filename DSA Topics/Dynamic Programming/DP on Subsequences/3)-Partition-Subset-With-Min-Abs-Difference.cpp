class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    
	    int totalSum=0;
	    for(int i=0;i<n;i++){
	        totalSum+=arr[i];
	    }
	    
	    vector<vector<int>> dp(n,vector<int> (totalSum+1,0));
	    
	    //Tabulation
	      
        // Base case
        if (arr[0] <= totalSum) dp[0][arr[0]] = 1;
        
        for(int i=1;i<n;i++){
            for(int k=0;k<=totalSum;k++){
                bool pick=false;
                if(k-arr[i]>=0) pick=dp[i-1][k-arr[i]];
                bool notPick=dp[i-1][k];
                
                dp[i][k]=pick || notPick;
            }
        }
	    
	    int ans=INT_MAX;
	    
	    for(int i=0;i<=totalSum;i++){
	        if(dp[n-1][i]){
	            int s1=i;
	            int s2=totalSum-i;
	            ans=min(ans,abs(s1-s2));
	        }
	    }
	    
	    return ans;
	} 
};