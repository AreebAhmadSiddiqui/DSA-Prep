// f(i,leftFingerPos,rightFingerPos)

// aur solve kar lo

// For calculate one d index for all the chracters and solve simply
class Solution {
private:
    int getDistance(int i,string &word,int fingerPos){
        
        if(fingerPos==26) return 0;
        int oneDIndexOfDest=word[i]-'A';
        
        int x1=oneDIndexOfDest/6;
        int y1=oneDIndexOfDest%6;
        int x2=fingerPos/6;
        int y2=fingerPos%6;
        
        return abs(x1-x2)+abs(y1-y2);
    }
//     int help(int i,string &word,int leftFinger,int rightFinger,vector<vector<vector<int>>> &dp){
        
//         if(i==word.size()) return 0;
        
//         if(dp[i][leftFinger+1][rightFinger+1]!=-1) return dp[i][leftFinger+1][rightFinger+1];
//         int leftMove=getDistance(i,word,leftFinger)+help(i+1,word,word[i]-'A',rightFinger,dp);
//         int rightMove=getDistance(i,word,rightFinger)+help(i+1,word,leftFinger,word[i]-'A',dp);
        
//         return dp[i][leftFinger+1][rightFinger+1]=min(leftMove,rightMove);
//     }
//     int tabulation(string &word){
//         int n=word.size();
//         vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (27,vector<int> (27,0)));
        
//         // Base Case
//         for(int i=0;i<27;i++){
//             for(int j=0;j<27;j++){
//                 dp[n][i][j]=0;
//             }
//         }
        
//         for(int i=n-1;i>=0;i--){
//             for(int leftFinger=0;leftFinger<=26;leftFinger++){
//                 for(int rightFinger=0;rightFinger<=26;rightFinger++){
                    
//                     int leftMove=getDistance(i,word,leftFinger)+dp[i+1][word[i]-'A'][rightFinger];
//                     int rightMove=getDistance(i,word,rightFinger)+dp[i+1][leftFinger][word[i]-'A'];

//                     dp[i][leftFinger][rightFinger]=min(leftMove,rightMove);
//                 }    
//             }
//         }
        
//         return dp[0][26][26];
//     }
      int spaceOptimisation(string &word){
        int n=word.size();
        vector<vector<int>> curr(27,vector<int> (27,0)),prev(27,vector<int> (27,0));
        
        // Base Case
        for(int i=0;i<27;i++){
            for(int j=0;j<27;j++){
                prev[i][j]=0;
            }
        }
        
        for(int i=n-1;i>=0;i--){
            for(int leftFinger=0;leftFinger<=26;leftFinger++){
                for(int rightFinger=0;rightFinger<=26;rightFinger++){
                    
                    int leftMove=getDistance(i,word,leftFinger)+prev[word[i]-'A'][rightFinger];
                    int rightMove=getDistance(i,word,rightFinger)+prev[leftFinger][word[i]-'A'];

                    curr[leftFinger][rightFinger]=min(leftMove,rightMove);
                }    
            }
            prev=curr;
        }
        
        return prev[26][26];
    }
public:
    int minimumDistance(string word) {
        
        // vector<vector<vector<int>>> dp(word.size()+1,vector<vector<int>> (27,vector<int> (27,-1)));
        // return help(0,word,-1,-1,dp);
        
        // return tabulation(word);
        return spaceOptimisation(word);
    }
};