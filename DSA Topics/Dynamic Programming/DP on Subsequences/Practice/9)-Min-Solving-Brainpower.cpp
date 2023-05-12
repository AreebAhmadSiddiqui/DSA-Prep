2140. Solving Questions With Brainpower

You are given a 0-indexed 2D integer array questions where questions[i] = [pointsi, brainpoweri].

The array describes the questions of an exam, where you have to process the questions in order (i.e., starting from question 0) and make a decision whether to solve or skip each question. Solving question i will earn you pointsi points but you will be unable to solve each of the next brainpoweri questions. If you skip question i, you get to make the decision on the next question.

For example, given questions = [[3, 2], [4, 3], [4, 4], [2, 5]]:
If question 0 is solved, you will earn 3 points but you will be unable to solve questions 1 and 2.
If instead, question 0 is skipped and question 1 is solved, you will earn 4 points but you will be unable to solve questions 2 and 3.
Return the maximum points you can earn for the exam.
    
    
class Solution {
private:
//     long long help(int i,int n,vector<vector<int>>& questions,vector<long long> &dp){
//         if(i>=n) return 0;
        
//         if(dp[i]!=-1) return dp[i];
        
//         int points=questions[i][0];
//         int skip=questions[i][1];
        
        // Points + (kuch hai -> Agar is kuch ki value i>=n hua to zero hai isliye points to add karne hi padta hai )
//         long long pick=points+help(i+skip+1,n,questions,dp);
//         long long notPick=0+help(i+1,n,questions,dp);
        
//         return dp[i]=max(pick,notPick);
//     }
    
//     long long tabulation(vector<vector<int>>& questions) {
//         int n=questions.size();
//         vector<long long> dp(n+2,0);
        
//         // Base Case Done
        
//         for(int i=n-1;i>=0;i--){
            
//             int points=questions[i][0];
//             int skip=questions[i][1];

    // Points to le hi loge lekin age jaoge ki ni wo depend karega i+skip+1 ki value pe
//             long long pick=points+(i+skip+1<=n ? dp[i+skip+1] : 0);
//             long long notPick=0+dp[i+1];

//             dp[i]=max(pick,notPick);
//         }
//         return dp[0];
//     }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        
        // int n=questions.size();
        // vector<long long> dp(n+1,-1);
        // return help(0,n,questions,dp);
        return tabulation(questions);
    }
};