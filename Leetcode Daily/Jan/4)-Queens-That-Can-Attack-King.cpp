class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        
        set<vector<int>> st;
        
        for(auto &vec:queens) st.insert(vec);
        
        vector<vector<int>> ans;
        
        // Main 8 loops likha tha dhattt !! ;(

        int x=king[0];
        int y=king[1];
        for(int dx=-1;dx<=1;dx++){
            for(int dy=-1;dy<=1;dy++){
                for(int k=1;k<=8;k++){
                    int newX=x+dx*k; // x+dx kyun ni kyunki usse sirf ek step age bhadega lekin tumhe to 8 steps bhadane hai isliye int k
                    int newY=y+dy*k;
                    if(newX>=0 && newX<8 && newY>=0 && newY<8 && st.find({newX,newY})!=st.end()){
                        ans.push_back({newX,newY});
                        break;
                    }
                }
            }
        }
        return ans;
    }
};