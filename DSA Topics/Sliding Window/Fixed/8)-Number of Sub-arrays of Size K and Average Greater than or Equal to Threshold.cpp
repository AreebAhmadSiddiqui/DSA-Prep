class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        
        int cnt=0;
        int j=0;
        int i=0;
        int sum=0;
        while(j<arr.size()){
            
            // Do stuff
            sum+=arr[j];
            
            if(j-i+1==k){
                
                // Cal
                if(sum>=threshold*k){ // to avoid converting to double
                    cnt++;
                }
                
                // Shrink window
                sum-=arr[i];
                i++;
            }
            j++;
        }
        
        return cnt;
    }
};