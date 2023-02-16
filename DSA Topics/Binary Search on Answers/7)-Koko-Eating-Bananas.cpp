Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

class Solution {
private:
    bool canEatAllBananas(int k,vector<int> &piles,int h){
        long long hoursNeeded=0;
        
        for(int i=0;i<piles.size();i++){
            hoursNeeded+= piles[i]%k==0 ? piles[i]/k : 1+piles[i]/k; // if divisible piles[i]/k ghanta other ek ghant aur lagega
        }
        
        return hoursNeeded<=h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        // int start=1 min
        // int end=sum of all bananas when h=1
        
        int start=1;
        int end=INT_MIN;
        
        // if hr is 1 and we have to eat all then k has to be sum of its elements( ye galat kar diya maine given hr one kaise ho sakta hai bhai?? 1 ghante main sab kaise khaoge noob)
        
        // Wrong wala
        // for(int i=0;i<piles.size();i++){
        //     end+=piles[i];
        // }
        
        // Kyunki at least hr ki value piles.length to hogi hi aur sabse assan hoga ki max wala element k ho to sare kha sakta wo
        for(int i=0;i<piles.size();i++){
            end=max(end,piles[i]);
        }
        
        int k=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            
            if(canEatAllBananas(mid,piles,h)){
                k=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        
        return k;
    }
};