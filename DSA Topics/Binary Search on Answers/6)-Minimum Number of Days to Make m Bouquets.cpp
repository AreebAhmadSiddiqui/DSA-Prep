You are given an integer array bloomDay, an integer m and an integer k.

You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.

class Solution {
private:
    bool isPossible(int days,vector<int> &a,int m,int k){
        
        int flowerTotal=0;
        int noOfBouquet=0;
        for(int i=0;i<a.size();i++){
            if(a[i]<=days){ // consequtive flowers jo days se kam hai wo kar diya
               flowerTotal++; 
            }
            else{ 
                // jaise hi na ho wo wasie dekho kitne bouquet ban rahe
                noOfBouquet+=flowerTotal/k;
                flowerTotal=0;
            }
        }
        // ho sakta hai else mein na ae aur to ye check yahan pe bhi
        noOfBouquet+=flowerTotal/k;
        return noOfBouquet>=m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        
        int start=1,end=0;
        for(int i=0;i<bloomDay.size();i++){
            end=max(end,bloomDay[i]);
        }
        
        int ans=-1;
        
        while(start<=end){
            int mid=start+(end-start)/2;
            
            if(isPossible(mid,bloomDay,m,k)){
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