class Solution {
private:

    int n=s.size();
    // O(n*n*n)

    // Steps

    a) Yahan pe bhi ham graph with maximum apples wale jaisa karenge
    b) apne neeche walon se solve kar wa lo aur wo jo answer de unhe apne mein add kar lo

    vector<string> help(int i,string &s,unordered_set<string> &st,unordered_map<int,vector<string>> &dp){
        
        if(i==s.size()){
            return {""}; // agar ye i==s.size() pahuncha to seedhe {""} return kar do koi dikkat ni
        }
        
        if(dp.find(i)!=dp.end()) return dp[i];
        
        vector<string> result;
        
        string prefix="";
        for(int j=i;j<s.size();j++){

            prefix+=s[j]; // har i-j tak ka prefix nikalo aur check karo
            if(st.find(prefix)!=st.end()){
                vector<string> temp= help(j+1,s,st,dp); // agar match kar gaya to age recursion call kar do
                for(auto &word:temp){ // ye loop aur yahan jo kar rahe uska ye significanc ehai ki hamne kaha bhai to apne neeche se jo bhi laya hai wo mujhe de de main bhi usmein add ho jata hun aur main return kar do apne upar wale ko wo baad mein add ho jaega mujhse pehle
                    result.push_back(prefix+ (word.size()==0 ? "" : " ")+word);

                    // Example dekho

                    // s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]

                    // manlo wo dog ko last mein check kiya aur j=i+1 kiya to return {""} aya okk
                    // fir tum kya rahe jo bhi result leke aya hai is case mein {""}

                    // tum use iterate karo aur apne currentPrefix mein add kar do yani dog+"" return {"dog"}

                    // ab tum return karoge to wahan sand hoga prefix mein to yahna aega {"sand dog"}

                    // isko upar prefix mein cat hoga to res mein {"cat sand dog"}

                    // ab i=3 yani s[i]=s pe jaega aur prefix mein cats ho jaega to ultimately {"and dog"} return hoke aega

                    // ab result mein {"cat sand dog","cats and dog"} ho jaega aur return hoga kyunki age ko matching ni hai
                }
            }
        }
        return dp[i]=result;
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        unordered_map<int,vector<string>> dp;
        return help(0,s,st,dp);
        
    }
};