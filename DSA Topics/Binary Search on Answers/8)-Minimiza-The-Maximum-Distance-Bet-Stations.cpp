We have an horizontal number line. On that number line, we have gas stations at positions stations[0], stations[1], ..., stations[N-1], where N = size of the stations array. Now, we add K more gas stations so that D, the maximum distance between adjacent gas stations, is minimized. We have to find the smallest possible value of D. Find the answer exactly to 2 decimal places.

class Solution {
private:
// Ham log nikal rahe ki is dist pe kitne stations rakh paunga

example

agar man lo ek station hai 10 aur doosra 16 pe to agar mujhe 1 ke distance pe rakhna hai to kitne pe rakh paunga answers is 16-10 / 1
similary for 2 16-10/2 bas aise hi karna hai
  bool isPossible(double maxDis,vector<int> &stations,int k){
      
      int totalStations=0; // within maxDis 
      
      for(int i=0;i<stations.size()-1;i++){
          int difference=stations[i+1]-stations[i];
          totalStations+=(int)(difference/maxDis);
      }
      
      return totalStations<=k;
  }
  public:
    double findSmallestMaxDist(vector<int> &stations, int K){
        
        // Since start and end are the differences between any two station so min would be 0 and max would the last - the first
        double start=0;
        int n=stations.size();
        double end=stations[n-1]-stations[0];
        
        double ans=-1;
        while(end-start>1e-6){
            double mid=start+(end-start)/2;
            
            if(isPossible(mid,stations,K)){
                ans=mid;
                end=mid;
            }
            else{
                start=mid;
            }
        }
        
        return ans;
    }
};