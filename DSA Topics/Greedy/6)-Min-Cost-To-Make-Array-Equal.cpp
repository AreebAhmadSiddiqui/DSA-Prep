2448. Minimum Cost to Make Array Equal

You are given two 0-indexed arrays nums and cost consisting each of n positive integers.

You can do the following operation any number of times:

Increase or decrease any element of the array nums by 1.
The cost of doing one operation on the ith element is cost[i].

Return the minimum total cost such that all the elements of the array nums become equal.

 
    
class Solution {
private:
    long long getCost(vector<pair<int,int>> &temp,long long no){
        long long sum=0;
        int n=temp.size();
        
        for(int i=0;i<n;i++){
            int val=temp[i].first;
            sum=sum+abs(1ll*val-1ll*no)*1ll*temp[i].second;
        }
        
        return sum;
    }
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        
        vector<pair<int,int>> temp;
        
        long long n=nums.size();
        long long totalElements=0;
        for(int i=0;i<n;i++) {
            temp.push_back({nums[i],cost[i]});
            totalElements=totalElements+1ll*cost[i];
        }
        
        sort(temp.begin(),temp.end());
        
        long long optimalNumberPos=(totalElements+1)/2;
        
        int midNumber=0;
        long long i=0;
        long long optimalNo=temp[0].first;
        long long total=0;
        while(total< optimalNumberPos && i<n){
            total+=1ll*temp[i].second;
            optimalNo=temp[i].first;
            i++;
        }
        long long minCostt=getCost(temp,optimalNo);
        return minCostt;
    }
};