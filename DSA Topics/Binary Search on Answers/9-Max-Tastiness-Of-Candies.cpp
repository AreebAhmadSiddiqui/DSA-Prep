class Solution {
private:
    bool isPossible(int minTastiness,vector<int> &price,int k){
        int elements=1;
        int prev=0;
        for(int i=1;i<price.size();i++){
            if(price[i]-price[prev]>=minTastiness){
                elements++;
                prev=i;
            }
        }
        return elements>=k;
    }
public:
    int maximumTastiness(vector<int>& price, int k) {
        
        sort(price.begin(),price.end());
        // Why sort?
        
        // Dekho isko sort isliye kiya taaki hame ek uniform search space mil jae
        
        // Man lo maine x min ko rakha
        
//         aur array sorted hai to main check kar raha ki a[i]-a[prev]>=minTastiness hai kya agaar maan lo ni hai to prev se lekar i tak bhi to ni hoga kyunki sort kiya hai a[prev] ko jaise hi bhadoge ans aur kam hoga isliye use lena ki koi zarurat ni 
        int start=0;
        int end=price[price.size()-1]-price[0];
        
        int ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            
            if(isPossible(mid,price,k)){ // agar main is answer ko rakh ke >=k candies rakh sakta hun to agar maine kam kiya to definitely is wale answer se badenhi hi 
                ans=mid;
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
        
        return ans;
    }
};