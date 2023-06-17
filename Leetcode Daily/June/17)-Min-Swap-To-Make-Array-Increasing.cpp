1187. Make Array Strictly Increasing

Given two integer arrays arr1 and arr2, return the minimum number of operations (possibly zero) needed to make arr1 strictly increasing.

In one operation, you can choose two indices 0 <= i < arr1.length and 0 <= j < arr2.length and do the assignment arr1[i] = arr2[j].

If there is no way to make arr1 strictly increasing, return -1.
    
    
Approach

a) Sort kardo Ye to intuitive hai because sort karne se hi tum asani se banda dhoondh sakte ki isse zyda kaunsa aega
b) Agar i>prev se bada hai to ya to use chod do aur age bhad jao otherwise usse just bada dhondho
c) Agar i<=prev hai tab to just bada dhondhna hi padega
d) Bas Dp se solve kardo

class Solution {
private:
    int getUpperBound(int target,vector<int> &nums){
        int n=nums.size();
        int end=n-1;
        int start=0;
        
        int ans=n;
        while(start<=end){
            int mid=start+(end-start)/2;
            
            if(nums[mid]>target){
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return ans;
    }
    void swap(int i,int j,vector<int> &num1,vector<int> &num2){
        int t=num1[i];
        num1[i]=num2[j];
        num2[j]=t;
    }
    
    // O(n1(log(n1*n2)+log(n2))
    int help(int i,int prev,int n1,int n2,vector<int> &arr1,vector<int> &arr2,map<pair<int,int>,int> &dp){
        if(i==n1) return 0;
        
        
        if(dp.find({i,prev})!=dp.end()) return dp[{i,prev}];
        
        int noSwap=1e9;
        if(i==0 || arr1[i]>prev){
            noSwap=0+help(i+1,arr1[i],n1,n2,arr1,arr2,dp);
        }
        
        int getIdx=getUpperBound(prev,arr2);
        
        int sWap=1e9;
        
        if(getIdx!=n2){
            sWap=1+help(i+1,arr2[getIdx],n1,n2,arr1,arr2,dp);
        }
        
        return dp[{i,prev}]=min(sWap,noSwap);
    }
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        
        int n1=arr1.size();
        int n2=arr2.size();
        
        sort(arr2.begin(),arr2.end());
        map<pair<int,int>,int> dp;
        int ans=help(0,0,n1,n2,arr1,arr2,dp);
        
        return ans==1e9 ? -1 : ans;
    }
};