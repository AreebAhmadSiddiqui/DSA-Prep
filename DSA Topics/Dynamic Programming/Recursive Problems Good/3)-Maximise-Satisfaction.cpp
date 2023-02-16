class Solution {
public:
    int maxSatisfaction(vector<int>& sat) {
        
        int n=sat.size();
        sort(sat.begin(),sat.end());
        // Sort the satisfaction as you want to maximise
        
        int currSum=0,res=0,suffixSum=0;
        for(int i=n-1;i>=0;i--){
            suffixSum+=sat[i]; //  in dono ki wajeh se max wala element kai baar ad ho sakta
            currSum+=suffixSum;//
            res=max(res,currSum);
        }
        
        return res;
    }
};