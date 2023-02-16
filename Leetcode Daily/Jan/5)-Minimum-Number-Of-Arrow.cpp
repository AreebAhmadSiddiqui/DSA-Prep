Steps

a) Maine ye dimag lagaya ki main set wise rakhta hai agar koi ballon mere andar a sakta hai to use include kar lo kyunki in sabhi ko marne mein sirf ek arrow lagega
b) aur agar na include kar paya to doosra set shuru kardo basically arrow cnt badha do
c) maine kiya ki jo starting point a raha hai wo agar mere pichle end point se kam hai tab main include kar sakta hun
d) aur fir naya start kya hoga? naya start hoga max(start,pichla start) kyunki dekho visualise karo agar ham kai balloons ko ek mein kar rahe hain to aur start time sort kar hi diya hai to age ana wale start times bade hi honge to unhe lo kyunki pehle le liya uski koi value ni kyunki naya wala start se ballon ki width choti ho rahi aur hame wahi spot chhaiye jahan marne par kai balloons ek saath path jaen
e) same cheez end ke sath karni min(end,currEnd) lena kyunki usi se width chooti ho gi aur tumhara answer aega
f) Diagram bana ke dekhne agar ni samjh aya to waise khud kiya tha to samjh a jana chahiye
g) Gdrive pe dala hai test case dekhlena agar na samjh ae to khud se zarur karna please

class Solution {
public:
    
    O(nlogn)
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        
        int arrowCnt=1;
        int currStart=INT_MIN,currEnd=INT_MAX;
        
        for(int i=0;i<points.size();i++){
            int start=points[i][0];
            int end=points[i][1];
            
            // Include in my current set
            if(start<=currEnd){
                currStart=max(currStart,start); // ye likhne ki zarurat ni kyunki start to bada hi hoga currStart se kyunki sort kar diya hai tumne
                currEnd=min(currEnd,end); 
            }
            // Now i need another set
            else{
                currStart=start;
                currEnd=end;
                arrowCnt++;
            }
            
        }
        
        return arrowCnt;
    }
};