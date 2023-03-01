// Quick Sort TLE as worst Case is O(n2)
// class Solution {
// private:
//     int getPartition(int low,int high,vector<int> &nums){
        
//         int pivot=nums[low];
//         int i=low;
//         int j=high;
        
//         while(i<j){
            
//             while(i<j && nums[i]<=pivot) i++;
//             while(nums[j]>pivot) j--;
            
//             if(i<j) swap(nums[i],nums[j]);
//         }
        
//         swap(nums[j],nums[low]);
        
//         return j;
//     }
//     void quickSort(int low,int high,vector<int> &nums){
//         if(low<high){
//             int partition=getPartition(low,high,nums);
//             quickSort(low,partition-1,nums);
//             quickSort(partition+1,high,nums);
//         }
//     }
// public:
//     vector<int> sortArray(vector<int>& nums) {
        
//         int n=nums.size();
//         quickSort(0,n-1,nums);
//         return nums;
//     }
// };


// class Solution {
// private:
//     void merge(int low,int high,int mid,vector<int> &nums){
        
//         int i=low;
//         int j=mid+1;
//         vector<int> temp(high-low+1,0);
//         int r=0;
//         while(i<=mid && j<=high){
//             if(nums[i]<nums[j]) temp[r++]=nums[i++];
//             else temp[r++]=nums[j++];
//         }

//         while(i<=mid) temp[r++]=nums[i++];

//         while(j<=high) temp[r++]=nums[j++];

//         for(int i=low;i<=high;i++){
//             nums[i]=temp[i-low];
//         }
        
//     }
//     void mergeSort(int low,int high,vector<int> &nums){
        
//         if(low<high){
//             int mid=low+(high-low)/2;
            
//             mergeSort(low,mid,nums);
//             mergeSort(mid+1,high,nums);
//             merge(low,high,mid,nums);
//         }
//     }
// public:
//     vector<int> sortArray(vector<int>& nums) {
        
//         int n=nums.size();
        
//         mergeSort(0,n-1,nums);
        
//         return nums;
//     }
// };


// Count Sort
class Solution{
    public:
    
    // O(n+mini+maxi) O(maxi+mini)
    vector<int> sortArray(vector<int> &nums){
        
        // Get maxEle for maxSize of cnt Array
        int maxi=0;
        int mini=1e9;
        for(auto &num:nums){
            maxi=max(maxi,num);
            mini=min(mini,num);
        }
        
        mini=abs(mini);
        
        int n=maxi+mini; // Range of maxi and mini
        // Initialise the array
        vector<int> cntArr(n+1,0);
        
        
        for(auto &num:nums) cntArr[num+mini]++;
        
        
        int r=0;
        int i=0;
        
        while(r<nums.size() && i<=n){
            while(r<nums.size() && cntArr[i]!=0){
                nums[r++]=i-mini;
                cntArr[i]--;
            }
            i++;
        }
        return nums;
    }
};