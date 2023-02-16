class Solution
{
public:
    //     int countGoodSubstrings(string s) {
    //         vector<int> hash(26,0);

    // 	    int k=3;

    // 	    int i=0;
    // 	    int j=0;
    // 	    int cnt=0;
    // 	    while(j<s.size()){

    // 	        // Do stuff
    //             hash[s[j]-'a']++;

    //             if(j-i+1==k){// reached window end

    //                 // Calculations
    //                 if(isUnique(s,hash)) cnt++;

    //                 // Shrink The window
    //                 hash[s[i]-'a']--;
    //                 i++;
    //             }
    //             j++;
    // 	    }
    //         return cnt;
    //     }

    // O(n) O(1)
    int countGoodSubstrings(string s)
    {
        if (s.size() < 3)
            return 0;

        int cnt = 0;
        char a = s[0], b = s[1];
        for (int i = 2; i < s.size(); i++)
        {
            char c = s[i];
            if (a != b && b != c && c != a)
                cnt++;
            a = b;
            b = c;
        }
        return cnt;
    }
};