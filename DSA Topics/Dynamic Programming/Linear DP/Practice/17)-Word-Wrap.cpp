Steps

a) Ek dum same hai filling book case shelf wale jaise usmein height nikalni thi ismein width
b) dekho ham words ko place karenge to 1 space chodenge
c) first word ko to place karna hi hai to use place kar do aur avail width ko maxWi-words[0].size() initialise kar do
d) agar aisa na karta hun bahut conditions lagani padengi messy ho jaega code
e) Ba har i pe two choices ya to same level pe rakho ya fir doosre level pe

Ham log ye staretegy follow karenge _word (space fir word) kyunki isse ho jaega end wali space ki bhi jhanjhat ni
f) main is level pe tab hi rakh sakta hun jab wordlen<=availWi-1 ( -1 kyun because space fir word rakhoge to available space mein se - 1 kar dena)
g) agar rakh sakte ho to rakh do new avail width ko availwi-wordlen-1 kar do
h) aur agar maan lo yahan ni rakh sakte to next lvl pe rakho to space kitni chodi avail width jitni aur ab ni space jo bachegi wo hogi max width- wor len (yahan -1 kyun ni because yahan tum word ko sabse pehle rakh rahe usse pehle space ni hai na) ( first word pe word pattern follow karo uske baad _ word (space word pattern))

#include <bits/stdc++.h> 
// int help(int i,vector<string> &words,int availWidth,int n,int maxWidth,vector<vector<int>> &dp){
//     // Base Case
//     if(i==n) return (int)pow(availWidth,3);

//     if(dp[i][availWidth]!=-1) return dp[i][availWidth];
//     int wordLength=words[i].size();

//     int placeCurrentLevel=1e9,placeNextLevel=1e9;
//     if(wordLength<=availWidth-1) placeCurrentLevel=0+help(i+1,words,availWidth-wordLength-1,n,maxWidth,dp); // -1 space jo chodi hai uske liye
//     placeNextLevel=(int)pow(availWidth,3)+help(i+1,words,maxWidth-wordLength,n,maxWidth,dp);

//     return dp[i][availWidth]=min(placeCurrentLevel,placeNextLevel);
// }
// int tabulation(vector<string> &words,int m,int n){
//     vector<vector<int>> dp(n+1,vector<int> (m+1,1e9));

//     int maxWidth=m;
//     // Base Case
//     for(int availWidth=0;availWidth<=m;availWidth++){
//         dp[n][availWidth]=(int)pow(availWidth,3);
//     }

//     for(int i=n-1;i>=1;i--){
//         for(int availWidth=0;availWidth<=m;availWidth++){
//             int wordLength=words[i].size();

//             int placeCurrentLevel = 1e9, placeNextLevel = 1e9;
//             if (wordLength <= availWidth - 1) placeCurrentLevel = 0+dp[i + 1][availWidth - wordLength - 1]; // -1 jo word ke beeche mein space jo chodi hai uske liye
//             placeNextLevel =(int)pow(availWidth, 3) + dp[i + 1][ maxWidth - wordLength];
            
//             dp[i][availWidth] = min(placeCurrentLevel, placeNextLevel);
//         }
//     }

//     return dp[1][m-words[0].size()];
// }

int spaceOptimisation(vector<string> &words,int m,int n){
    vector<int> next(m+1,1e9),curr(m+1,1e9);

    int maxWidth=m;
    // Base Case
    for(int availWidth=0;availWidth<=m;availWidth++){
        next[availWidth]=(int)pow(availWidth,3);
    }

    for(int i=n-1;i>=1;i--){
        for(int availWidth=0;availWidth<=m;availWidth++){
            int wordLength=words[i].size();

            int placeCurrentLevel = 1e9, placeNextLevel = 1e9;
            if (wordLength <= availWidth - 1) placeCurrentLevel = 0+next[availWidth - wordLength - 1]; // -1 jo word ke beeche mein space jo chodi hai uske liye
            placeNextLevel =(int)pow(availWidth, 3) +next[ maxWidth - wordLength];
            
            curr[availWidth] = min(placeCurrentLevel, placeNextLevel);
        }
        next=curr;
    }

    return next[m-words[0].size()];
}
int wordWrap(vector<string> words,int m,int n)
{
    // vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
	// return help(1,words,m-words[0].size(),n,m,dp);

    // return tabulation(words,m,n);
    return spaceOptimisation(words,m,n);
}