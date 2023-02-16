class Solution {
private:
//     int help(int i,int availWidth,int currMaxHeight,vector<vector<int>>& books,int shelfWidth,vector<vector<int>> &dp){
//         if(i==books.size()) return currMaxHeight;
        
//         int sameShelf=1e9,nextShelf=1e9;
        
//         if(dp[i][availWidth]!=-1) return dp[i][availWidth];
//         int bookWidth=books[i][0];
//         int bookHeight=books[i][1];
//         if(availWidth-bookWidth>=0){
//             sameShelf=help(i+1,availWidth-bookWidth,max(currMaxHeight,bookHeight),books,shelfWidth,dp);
//         }
    // Maine agle shlef pe rakh diya hai isliye available width kam ho raha aur curr height book height ke barabar
//         nextShelf=currMaxHeight+help(i+1,shelfWidth-bookWidth,bookHeight,books,shelfWidth,dp);
        
//         return dp[i][availWidth]=min(sameShelf,nextShelf);
        
//     }
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        
        // int n=books.size();
        // vector<vector<int>> dp(n+1,vector<int> (shelfWidth+1,-1));
        // return help(0,shelfWidth,0,books,shelfWidth,dp); // {i,currWidth,currMaxHeight}
        
        return tabulation(books,shelfWidth);
    }
};