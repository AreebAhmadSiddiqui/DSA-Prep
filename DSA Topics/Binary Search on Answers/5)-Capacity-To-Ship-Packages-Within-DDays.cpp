class Solution {
private:
    bool isPossible(int maxWeight,vector<int> &weights,int days){
        int day=1;
        int totalWeight=0;
        
        for(int i=0;i<weights.size();){
            if(totalWeight+weights[i]<=maxWeight){
                totalWeight+=weights[i];
                i++;
            }
            else{
                day++;
                totalWeight=0;
            }
        }
        
        return day<=days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int start=0;
        int end=0;
        
        for(int i=0;i<weights.size();i++){
            start=max(start,weights[i]);
            end+=weights[i];
        }
        
        int ans=0;
        while(start<=end){
            int mid=start+(end-start)/2;
            
            if(isPossible(mid,weights,days)){
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