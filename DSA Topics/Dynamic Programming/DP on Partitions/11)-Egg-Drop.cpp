// Dekho

a) Pehle to pepcoding and aditha verma ka dekh lena agar bhool jao to
b) Manager ceo wali analogy

ceo ne manager se kaha ki tum mujhe ye project gauranteed kitne time mein kara ke doge
to manager kaise karega? aise karega

man lo p1 p2 p3 people hai uske paas
    Best Time Worst Time
p1    bx1         wx1
p2    bx2         wx2
p3    bx3         wx3

tumhe in logon mein se pick karna hai ek banda jo kaam karke de lekin tumhe gauranteed kaam karana hai to kaise karge>
a) p1,p2 p3 ye sab best time mein bhi kar sakte aur worst mein bhi leekin agar gauranteed work karana hai to worst case le lo in logon ka kyunki isse bura to ni hoga ab un logon ki worst time ka min le lo usse ye hoga agar wo sare apna sabse beekar kaam bhi karein aur bahut time lagae taab bhi ye jo min aya hai utne mein to gauranteed work ho jaega


To ham wahi karte ki egg ko k se drop karaane par wo survive kar sakta aur break bhi to in dono mein se max le lo aur fir un sabka min le lo +1 zarur kar dena


b) Aur rahi baat Binary search ki wo bhi laga sakte ho kyunki tumhe worst case handle karna hai to break aur survive mein jo bhi max ho uske paas chale jao 

class Solution {
private:
    // Exponential
//     int help(int e,int f){
//         if(f==1 || f==0) return f;
//         if(e==1) return f; // worst case main
        
//         int ans=INT_MAX;
//         for(int k=1;k<=f;k++){
            
//             // if egg breaks at kth floor then definitely at k+1,k+2 it will break
//             int eggBreak=help(e-1,k-1);
//             // if egg survives at kth floor then definitelt it will survive anywhere below it
//             int eggSurvives=help(e,f-k);
            
//             // Why max because hame gauranteed chahiye ki ye answer hai to ham dekhenge jo mere bande max de de unmein se min le lo
//             // manager ceo wali analogy
//             ans=min(ans,max(eggBreak,eggSurvives)+1); // why plus 1 because 1 attempt to liya na
//         }
        
//         return ans;
//     }
    
//     int help(int e,int f,vector<vector<int>> &dp){
//         if(f==1 || f==0) return f;
//         if(e==1) return f; // worst case main
        
//         if(dp[e][f]!=-1) return dp[e][f];
        
//         int ans=INT_MAX;
//         for(int k=1;k<=f;k++){
            
//             // if egg breaks at kth floor then definitely at k+1,k+2 it will break
//             int eggBreak=help(e-1,k-1,dp);
//             // if egg survives at kth floor then definitelt it will survive anywhere below it
//             int eggSurvives=help(e,f-k,dp);
            
//             // Why max because hame gauranteed chahiye ki ye answer hai to ham dekhenge jo mere bande max de de unmein se min le lo
//             // manager ceo wali analogy
//             ans=min(ans,max(eggBreak,eggSurvives)+1); // why plus 1 because 1 attempt to liya na
//         }
        
//         return dp[e][f]=ans;
//     }
    
//     int tabulation(int e,int f){
        
//         vector<vector<int>> dp(e+1,vector<int> (f+1,0));
        
//         // Base Case
//         for(int i=0;i<=e;i++){
//             dp[i][1]=1;
//             dp[i][0]=0;
//         }
        
//         for(int i=0;i<=f;i++) dp[1][i]=i; // worst case main
        
        
//         for(int i=2;i<=e;i++){
//             for(int j=2;j<=f;j++){
//                 int ans=INT_MAX;
//                 for(int k=1;k<=j;k++){

//                     // if egg breaks at kth floor then definitely at k+1,k+2 it will break
//                     int eggBreak=dp[i-1][k-1];
//                     // if egg survives at kth floor then definitelt it will survive anywhere below it
//                     int eggSurvives=dp[i][j-k];

//                     // Why max because hame gauranteed chahiye ki ye answer hai to ham dekhenge jo mere bande max de de unmein se min le lo
//                     // manager ceo wali analogy
//                     ans=min(ans,max(eggBreak,eggSurvives)+1); // why plus 1 because 1 attempt to liya na
//                 }
//                 dp[i][j]=ans;
//            }
//         }
        
//         return dp[e][f];
//     }
    
    int tabulation(int e,int f){
        
        vector<vector<int>> dp(e+1,vector<int> (f+1,0));
        
        // Base Case
        for(int i=0;i<=e;i++){
            dp[i][1]=1;
            dp[i][0]=0;
        }
        
        for(int i=0;i<=f;i++) dp[1][i]=i; // worst case main
        
        
        for(int i=2;i<=e;i++){
            for(int j=2;j<=f;j++){
                int ans=INT_MAX;
                
                int start=1,end=j;
                while(start<=end){
                    
                    int k=start+(end-start)/2;
                    // if egg breaks at kth floor then definitely at k+1,k+2 it will break
                    int eggBreak=dp[i-1][k-1];
                    // if egg survives at kth floor then definitelt it will survive anywhere below it
                    int eggSurvives=dp[i][j-k];

                    // Why max because hame gauranteed chahiye ki ye answer hai to ham dekhenge jo mere bande max de de unmein se min le lo
                    // manager ceo wali analogy
                    ans=min(ans,max(eggBreak,eggSurvives)+1); // why plus 1 because 1 attempt to liya na
                    
                    if(eggBreak<eggSurvives){ // we want worst case so jo max ho uske paas chale jao
                        start=k+1;
                    }else{
                        end=k-1;
                    }
                }
                dp[i][j]=ans;
           }
        }
        
        return dp[e][f];
    }
public:
    int superEggDrop(int k, int n) {
        // vector<vector<int>> dp(k+1,vector<int> (n+1,-1));
        // return help(k,n,dp);
        
        return tabulation(k,n);
    }
};