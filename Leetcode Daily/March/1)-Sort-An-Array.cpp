Quick Sort TLE as worst Case is O(n2)

class Solution {
private:
    int getPartition(int low,int high,vector<int> &nums){
        
        int pivot=nums[low];
        int i=low;
        int j=high;
        
        while(i<j){
            
            while(i<j && nums[i]<=pivot) i++;
            while(nums[j]>pivot) j--; // yahan dhyan dena i<j ni lagana i dont know why jaba lagata hun to error ata hai
            
            if(i<j) swap(nums[i],nums[j]);
        }
        
        swap(nums[j],nums[low]);
        
        return j;
    }
    void quickSort(int low,int high,vector<int> &nums){
        if(low<high){
            int partition=getPartition(low,high,nums);
            quickSort(low,partition-1,nums);
            quickSort(partition+1,high,nums);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        
        int n=nums.size();
        quickSort(0,n-1,nums);
        return nums;
    }
};


class Solution {
private:
    void merge(int low,int high,int mid,vector<int> &nums){
        
        int i=low;
        int j=mid+1;
        vector<int> temp(high-low+1,0);
        int r=0;
        while(i<=mid && j<=high){
            if(nums[i]<nums[j]) temp[r++]=nums[i++];
            else temp[r++]=nums[j++];
        }

        while(i<=mid) temp[r++]=nums[i++];

        while(j<=high) temp[r++]=nums[j++];

        for(int i=low;i<=high;i++){
            nums[i]=temp[i-low];
        }
        
    }
    void mergeSort(int low,int high,vector<int> &nums){
        
        if(low<high){
            int mid=low+(high-low)/2;
            
            mergeSort(low,mid,nums);
            mergeSort(mid+1,high,nums);
            merge(low,high,mid,nums);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        
        int n=nums.size();
        
        mergeSort(0,n-1,nums);
        
        return nums;
    }
};