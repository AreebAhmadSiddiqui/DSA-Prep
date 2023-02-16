class Solution {
private:
    bool checkIfPossible(int maxSum,vector<int> &nums,int k){
         int partitions=1; // partition one se shuru karna raht hai bro hamesha bhool jate ho
         int total=0;
         for(int i=0;i<nums.size();){
             if(total+nums[i]<=maxSum){
                 total+=nums[i];
                 i++; // aur ye wala scene bhi dekha karo kyunki jab ni sum ni accomodate ho paega to hame jis i pe ni accomodate hua use firse use karna padega na otherwise total=num[i] kar do lekin wo acha ni lagta
             }
             else{
                 // increase partitions
                 partitions++;
                 total=0;
             }
         }
        
        return partitions<=k;  // ya to k ya to k se kam k se kam ka matlab hai sum zyada hai to kam kardo
    }
public:
    int splitArray(vector<int>& nums, int k) {
        
        // start= max elemnt of array because at max k=n-1 it means when every element is a partition itself then the max is the answer
        // end= sum of all elements of the array because when k=1 it means only one subarry exist
            
        int start=0,end=0;
        for(int i=0;i<nums.size();i++){
            start=max(start,nums[i]);
            end+=nums[i];
        }
        
        // O(n*log(sum(array)-max(arr)))
        int ans=-1;
        //BS
        while(start<=end){
            int mid=start+(end-start)/2;
            
            // check if using this maxSum we can get atmost k partitions
            
            if(checkIfPossible(mid,nums,k)){ // if possible we have to minimize
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        
        return ans;
    }
};