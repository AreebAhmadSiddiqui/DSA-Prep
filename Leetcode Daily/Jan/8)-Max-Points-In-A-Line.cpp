class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        
        // Sorted it because now we need not check from starting again and again
        // If you want to skip it just skip and write if(i==j) continue;
        
        // STEPS
        
        a) For every point store the slope from this point to other points
        b) and get the max of them
        c) why return ans+1 because see if there are 2 points in a line slope will be 1
        d) similarly if 3 points are on a line then slope cnt will be 2 so return cnt+1 kar rahe
        e) aur haan ek baat maine pehle slope wala map upar declare kiya tha to use galat answer a raha tha
        f) kyunki agar tumne map ko upar decalre kiya to ek line mein agar 4 points hai to sabse pehle to mp[slope] mein 3 aega fir dobara is point ke baad wala jab iteration mein aenge to mp[slope] mein 2 add hojaega to galat hai hame sirf maxiumum se matlab hai
        g) isliye har iteration mein max nikal rahe aur map ko locally declare kar rahe 
        sort(points.begin(),points.end());
        
        int maxSlopeCnt=0;

        // ~Average O(n*n*1) ~Worst O(n*n*n) So use map worst~O(n*n*logn)
        for(int i=0;i<points.size();i++){
            
            
            unordered_map<double,int> mp; // {slope,cnt}
            
            for(int j=i+1;j<points.size();j++){
                
                // if(i==j) continue; if you are not sorting
                int x1=points[i][0];
                int y1=points[i][1];
                int x2=points[j][0];
                int y2=points[j][1];
                
                double slope= x2-x1==0 ? INT_MAX : 1.0*(y2-y1)/(x2-x1)*1.0;
                
                mp[slope]++;
                maxSlopeCnt=max(maxSlopeCnt,mp[slope]);
            }
        }
        
        return maxSlopeCnt+1;
    }
};