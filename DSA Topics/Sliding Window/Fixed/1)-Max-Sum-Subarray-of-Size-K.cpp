class Solution{   
public:
    long maximumSumSubarray(int k, vector<int> &Arr , int n){
        long sum=0;
        for(int i=0;i<k;i++){
            sum+=Arr[i];
        }
        
        long maxi=sum;
        
        for(int i=k;i<n;i++){
            sum-=Arr[i-k];
            sum+=Arr[i];
            if(maxi<sum) maxi=sum;
        }
        return maxi;
    }
};