2542. Maximum Subsequence Score


You are given two 0-indexed integer arrays nums1 and nums2 of equal length n and a positive integer k. You must choose a subsequence of indices from nums1 of length k.

For chosen indices i0, i1, ..., ik - 1, your score is defined as:

The sum of the selected elements from nums1 multiplied with the minimum of the selected elements from nums2.
It can defined simply as: (nums1[i0] + nums1[i1] +...+ nums1[ik - 1]) * min(nums2[i0] , nums2[i1], ... ,nums2[ik - 1]).
Return the maximum possible score.

A subsequence of indices of an array is a set that can be derived from the set {0, 1, ..., n-1} by deleting some or no elements.

 

// Approach


a) Sort kardo Descending mein
b) Traverse karna shuru karo ye mante hue ki ye banda min hai to kya kya hoga
c) Logic lagao agar tumne descending mein sort kiya hai aur ye man ke chal rahe ho ki ye banda min hai to atleast k bande to hone hi chahiye tabhi to min ye hoga isliye k tak sabko pq mein dalte jao aur currSum mein update karte jao
d) Ab dekho tumhara paas k se zyada bande ho gae to ek banda hatana padega (Wo kaunsa hoga jo min ho obviously usko hata do aur is bande ko daldo)
e) Bas Yahi karna hai


class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int n=nums1.size();
        vector<pair<int,int>> nums(n);
        
        for(int i=0;i<nums1.size();i++){
            nums[i]={nums2[i],nums1[i]};
        }
        
        sort(nums.begin(),nums.end());
        
        long long currKSum=0;
        priority_queue<int> pq; // maxHeap ( but multiply by - for min heap)
        
        
        for(int i=n-1;i>=n-k;i--){
            currKSum+=nums[i].second;
            pq.push(-nums[i].second);
        }
        
        long long maxi=currKSum*1ll*nums[n-k].first;
        
        for(int i=n-k-1;i>=0;i--){

            // Remove the min element
            currKSum-=-pq.top();
            pq.pop();
            
            // Add this element
            currKSum+=nums[i].second;
            pq.push(-nums[i].second);
            
            maxi=max(maxi,currKSum*1ll*nums[i].first);
        }
        return maxi;
    }
};