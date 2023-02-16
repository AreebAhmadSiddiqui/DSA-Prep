class Solution {
public:
    
    // Yahan pe thora sa dikkat thi

    a) Normal BS on answers jaisa ni hai kyunki ismein hame min ka diya tha isliye jaise hi usse bada koi ho jaega ham apna cuts ko bhada denge
    b) aur answer mein check karna hai ki atlease k+1 bando ko main batega ki ni
    c) Min hai to atleast max hai to atmost return mein jo condition uski baat kar raha
    bool isPossibleToDivide(int minSum,vector<int> &sweetness,int k){

        int cuts=1;
        int total=0;
        int n=sweetness.size();
        for(int i=0;i<n;){
            total+=sweetness[i];
            i++;
            if(total>=minSum){
                cuts++;
                total=0;
            }
        }
        return cuts>=k; // atleast k partitions
    }
    int maximizeSweetness(vector<int> &sweetness, int k) {
        
        int start=INT_MAX; // min of all array when you have n-1 friedns the friends
        int end=0; // sum of all array when you have no friends

        for(int i=0;i<sweetness.size();i++){
            start=min(start,sweetness[i]);
            end+=sweetness[i];
        }

        int ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;

            if(isPossibleToDivide(mid,sweetness,k)){
                ans=mid;
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }

        return ans;
    }
};