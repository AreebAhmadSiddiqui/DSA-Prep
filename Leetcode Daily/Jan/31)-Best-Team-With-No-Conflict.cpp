Question

You are the manager of a basketball team. For the upcoming tournament, you want to choose the team with the highest overall score. The score of the team is the sum of scores of all the players in the team.

However, the basketball team is not allowed to have conflicts. A conflict exists if a younger player has a strictly higher score than an older player. A conflict does not occur between players of the same age.

Given two lists, scores and ages, where each scores[i] and ages[i] represents the score and age of the ith player, respectively, return the highest overall score of all possible basketball teams.


Thought Process

a) Maine jab soch raha tha to maine ye notice kiya hame bahut sare combinations try karne hai to recursion to lagega hi
b) Fir socha ki prevInd se kaam ban jaega lekin fir dimaag main aya ki sirf prev ko hi ni man sakte criteria jo pehle a chuka unhe bhi dekhna padega to wo n 2 square ho jaega
c) Fir socha sort kardun to age ke basis pe ? fir dimag chala ki agar sort kar diya tab ages to badi hi hongi sirf score prev wale se bada hai ki ni ye check karna padega bas fir yahi kar diya aur simple dp thi wo laga di

d) ek galti kari thi ki struct bana hai aur sirf ages wale object ko sort kar rhaa tha maan lo ki sare age same hai tab to use koi conflict ni aega to agar age same hai to score ke basis pe sort kar do kyunki usse kya hoga score sortt ho jaenge aur hame fir wahi wali condition se currScroe>= prevScore se baat ban jaegi warna kai conditions lagani pad rahi thi mujhe

(b) Wale ka example jisse pata chala ki ye (b) ni lagega

score=[4,9,6,8]
age=[4,2,1,3]  yahan dekho maine peche se chlana start kiya pehle score 8 ho gaya aur prevage 3 ab 6 pe aya wo 8 se kam hai age bhi kam hai to le liya ab 9 pe aya to 6 se zyada hai aur age bhi zyada to use bhi le liya lekin 9 ko ni lena tha na kyunki wo zyada to hai leikin 8 wali age usse zyada to conflict aega team mein

struct Data{
    int score,age;
    Data(int s,int a){
        score=s;
        age=a;
    }
};
class Solution {
private:
//     int help(int i,int prevInd,vector<Data> &persons,vector<vector<int>> &dp){
//         int n=persons.size();
//         if(i==n) return 0;
        
//         if(dp[i][prevInd]!=-1) return dp[i][prevInd];
        
//         int currScore=persons[i].score;
//         int prevScore= prevInd!=n ? persons[prevInd].score : 0;
        
//         int pick=0,notPick=0;
//         if(currScore>=prevScore){
//             pick=currScore+help(i+1,i,persons,dp);
//         }
//         notPick=0+help(i+1,prevInd,persons,dp);
        
//         return max(pick,notPick);
//     }
//     int tabulation(vector<int>& scores, vector<int>& ages){
//         int n=scores.size();
//         vector<Data> persons;
        
//         for(int i=0;i<n;i++){
//             persons.push_back(Data(scores[i],ages[i]));
//         }
        
//         sort(persons.begin(),persons.end(),comp);
//         vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        
//         // Base Case
//         for(int prevInd=0;prevInd<=n;prevInd++) dp[n][prevInd]=0;
        
//         for(int i=n-1;i>=0;i--){
//             for(int prevInd=0;prevInd<=n;prevInd++){
//                 int currScore=persons[i].score;
//                 int prevScore= prevInd!=n ? persons[prevInd].score : 0;

//                 int pick=0,notPick=0;
//                 if(currScore>=prevScore){
//                     pick=currScore+dp[i+1][i];
//                 }
//                 notPick=0+dp[i+1][prevInd];

//                 dp[i][prevInd]= max(pick,notPick);
//             }
//         }
        
//         return dp[0][n];
//     }
    
    int spaceOptimisation(vector<int>& scores, vector<int>& ages){
        int n=scores.size();
        vector<Data> persons;
        
        for(int i=0;i<n;i++){
            persons.push_back(Data(scores[i],ages[i]));
        }
        
        sort(persons.begin(),persons.end(),comp);
        vector<int> prev(n+1,0),curr(n+1,0);
        
        // Base Case
        for(int prevInd=0;prevInd<=n;prevInd++) prev[prevInd]=0;
        
        for(int i=n-1;i>=0;i--){
            for(int prevInd=0;prevInd<=n;prevInd++){
                int currScore=persons[i].score;
                int prevScore= prevInd!=n ? persons[prevInd].score : 0;

                int pick=0,notPick=0;
                if(currScore>=prevScore){
                    pick=currScore+prev[i];
                }
                notPick=0+prev[prevInd];

                curr[prevInd]= max(pick,notPick);
            }
            prev=curr;
        }
        
        return prev[n];
    }
public:
    static bool comp(Data &a,Data &b){
        return a.age==b.age ? a.score<b.score : a.age<b.age;
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
//         int n=scores.size();
//         vector<Data> persons;
        
//         for(int i=0;i<n;i++){
//             persons.push_back(Data(scores[i],ages[i]));
//         }
        
//         sort(persons.begin(),persons.end(),comp);
//         vector<vector<int>> dp(n,vector<int> (n+1,-1));
//         // for(int i=0;i<n;i++){
//         //     cout<<persons[i].age<<" "<<persons[i].score<<'\n';
//         // }
//         return help(0,n,persons,dp);
        // return tabulation(scores,ages);
        return spaceOptimisation(scores,ages);
    }
};