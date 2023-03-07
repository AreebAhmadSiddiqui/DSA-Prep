Minimum Time to Complete Trips

You are given an array time where time[i] denotes the time taken by the ith bus to complete one trip.

Each bus can make multiple trips successively; that is, the next trip can start immediately after completing the current trip. Also, each bus operates independently; that is, the trips of one bus do not influence the trips of any other bus.

You are also given an integer totalTrips, which denotes the number of trips all buses should make in total. Return the minimum time required for all buses to complete at least totalTrips trips.

 
// Simple BS on answers hai but upperBound tricky tha
    
class Solution {
public:
    bool isPossible(vector<int> &time,long long &maxTime,int &totalTrips){
        long long total=0;
        for(auto &it:time){
            total+= maxTime/it;
        }
        return total>=totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        
        long long start=1;
        long long end=INT_MAX;
        
        // Why min*totalTrips -> (Socho at worst case min wali bus hi sare trips karegi tum max * totalTrips bhi kar sakte ho lekin tumhe min time nikalna hai to min * totalTrips zayda fayde mand hai ultimately tumhe answer minimize karna hai)
        for(int i=0;i<time.size();i++){
            end=min(end,1ll*time[i]);
        }
        end=end*1ll*totalTrips;
        
        long long ans=-1;
        while(start<=end){
            long long mid=start+(end-start)/2;
            
            if(isPossible(time,mid,totalTrips)){
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return ans;
    }
};