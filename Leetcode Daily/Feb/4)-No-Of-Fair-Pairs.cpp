Count the Number of Fair Pairs

Given a 0-indexed integer array nums of size n and two integers lower and upper, return the number of fair pairs.

A pair (i, j) is fair if:

0 <= i < j < n, and
lower <= nums[i] + nums[j] <= upper
 
class Solution {
private:
    Steps
    
    a) First sort the array why?? (Mera to dimag hi kharab ho gaya sort kaise kar diya i<j ka kya hua are bhai wo nums[i]+nums[j] chah raha to agar man lo sorting mein i aur j badal bhi gaya tab bhi nums[j]+nums[i] hi chahiye tumhe bas order alag ho gaya hai)
        
    b) Ab sab sorted hai aur tumhe pairs chahiye
    c) Tum jis index pe khade ho wahan se socho kya kar sakte (lower-x<= y <= upper-x)  x= nums[i]  ab tumhe ek aisa y ka index chahiye jo ki chahiye jo ki lower-x ke barabar ya bad ho aur upper-x ke barabar ya chota ho
    d) to lower bound and upper bound laga do
    
    int upperBound(int start,vector<int> &nums,int target){
        
        int ans=-1;
        int end=nums.size()-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]>=target){
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        
        return ans;
    }
    int lowerBound(int start,vector<int> &nums,int target){
        
        int ans=-1;
        int end=nums.size()-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]<=target){
                ans=mid;
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
        
        return ans;
    }
public: 
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans=0;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++){
            
            int getUpperBoundIndex=upperBound(i+1,nums,lower-nums[i]);
            int getLowerBoundIndex=lowerBound(i+1,nums,upper-nums[i]);
            
            if(getUpperBoundIndex==-1 || getLowerBoundIndex==-1) ans+=0; // ye wo wala case jab possible na ya ho sakta hai 
            else ans+=getLowerBoundIndex-getUpperBoundIndex+1;
        }
        
        return ans;
    }
};