class Solution{
    public:

    // Is question main agar negatives na ho to sliding window laga sakte variable wali
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
       unordered_map<int,int> mp; // For storing prefixes
       
       int ans=0;
       int sum=0;
       int j=0;

       // Normal subarray problems type
       while(j<N){
           sum+=A[j];
           
           if(sum==K) ans=max(ans,j+1);
           
           int prevSum=sum-K;
           
           if(mp.find(prevSum)!=mp.end()){
               ans=max(ans,j-mp[prevSum]);
           }
           
           if(mp.find(sum)==mp.end()) mp[sum]=j; // to get the max value agar har baar update karenge to distance kam ho jaega
           j++;
       }
       
       return ans;
    } 
};