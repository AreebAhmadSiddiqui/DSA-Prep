ou are given a 0-indexed array of strings words and a 2D array of integers queries.

Each query queries[i] = [li, ri] asks us to find the number of strings present in the range li to ri (both inclusive) of words that start and end with a vowel.

Return an array ans of size queries.length, where ans[i] is the answer to the ith query.

Note that the vowel letters are 'a', 'e', 'i', 'o', and 'u'.

 
class Solution {
private:
    bool satisfyCondition(string &a){
        char vowels[]={'a','e','i','o','u'};
        
        bool b1=false,b2=false;
        for(int i=0;i<5;i++){
            if(a[0]==vowels[i]) b1=true;
            if(a[a.size()-1]==vowels[i]) b2=true;
        }
        
        return b1 && b2;
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        
        int n=words.size();
        vector<int> prefix(n,0);
        
        for(int i=0;i<n;i++){
            if(satisfyCondition(words[i])){
                // cout<<words[i]<<'\n';
                prefix[i]++;
            }
        }
        
        for(int i=1;i<n;i++){
            prefix[i]+=prefix[i-1];
        }
        vector<int> ans;
        
        for(auto &query:queries){
            int l=query[0];
            int r=query[1];
            
            if(l==0) ans.push_back(prefix[r]);
            else ans.push_back(prefix[r]-prefix[l-1]);
        }
        
        return ans;
    }
};