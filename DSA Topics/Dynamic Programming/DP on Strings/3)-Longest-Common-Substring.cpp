// Steps

a) Age se chalo peeche se ni 
b) agar match ni hua tab to chodo lekin agar match hua to apne pichle wale ka lelo sum because they are consecutive so usse pehle ho skat hai match hua ho
#include <bits/stdc++.h> 
int lcs(string &s1, string &s2){
	vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));

    // Base Case
    for (int j = 0; j < s2.size(); j++)
        dp[0][j] = 0;
    for (int i = 0; i < s1.size(); i++)
        dp[i][0] = 0;

    int ans=0;
    for (int i = 1; i <= s1.size(); i++)
    {
        for (int j = 1; j <= s2.size(); j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans=max(ans,dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }
    
    return ans;
}