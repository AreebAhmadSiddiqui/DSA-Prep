class Solution {
public:
// Maine ye two pointer socha lekin greedy fail ho gaya

Example 1,1000,123123,3,2,4 tumne left ko 1 pe aur right ko 4 pe rakha jo bada tha unmein whan chale gae same cheez karte gae aur dekho badi values ko miss kar diya
//     int maxScore(vector<int>& cardPoints, int k) {
       
//         int i=0;
//         int j=cardPoints.size()-1;
//         int sum=0;
//         while(i<=j && k!=0){
//             if(cardPoints[i]>cardPoints[j]){
//                 sum+=cardPoints[i];
//                 i++;
//             }else{
//                 sum+=cardPoints[j];
//                 j--;
//             }
//             k--;
//         }
//         return sum;
//     }
    

    // Yahan ek observation hai maxSumSubarray in a circual array wala quesion jaisa hi hai ye

    ismein hame kaha gaya hai ek time pe left end ya right end se sum utha sakte ho 

    to dekho

    two cases

    1) [sum ka part (not sum ka part)  sum ka part]
    2) [sum ka part (not sum ka part)]
    3) [(not sum ka part) sum ka part ]

    
    // Instead of sum ka part dhoondhna ham jo sum ka part ni hoga use dhoondh le yaani min sum subaaray
    // sum ka part wale elements k size ke hone the to ye n-k size ka hoga bas
    // ant mein totalsum-minsum kar dena
    // aur haan ek dikkat a sakti hai kyunki tum minSUm==INT_MAX kar rahe ho sakta hai k==n to minSum kabhi update hi ni hoga to uska dhyan rakhna
    
     int maxScore(vector<int>& cardPoints, int k) {
        
        int n=cardPoints.size();
        int totalSum=0;
         
        for(int i=0;i<n;i++) totalSum+=cardPoints[i];
        
        // Your aim is to find the subarray of size n-k with the min sum
        int minSum=INT_MAX;
        int i=0;
        int j=0;
        int sum=0;
        while(j<n){
            
            // Do stuff
            sum+=cardPoints[j];
            
            if(j-i+1==n-k){
                // Calculations
                
                minSum=min(minSum,sum);
                
                //Decrease the window
                sum-=cardPoints[i];
                i++;
            }
            j++;
        }
         if(minSum==INT_MAX) return totalSum;
         return totalSum-minSum;
    }
};