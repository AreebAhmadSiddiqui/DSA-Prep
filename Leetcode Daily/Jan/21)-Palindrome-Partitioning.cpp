class Solution {
private:
    bool isPalindrome(int i,int j,string &s){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void help(int i,string &s,vector<vector<string>> &ans,vector<string> &ds){
        if(i==s.size()){
            ans.push_back(ds);
            return;
        }
        
        for(int k=i;k<s.size();k++){
            if(isPalindrome(i,k,s)){
                ds.push_back(s.substr(i,k-i+1));
                help(k+1,s,ans,ds);
                ds.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> ans;
        vector<string> ds;
        help(0,s,ans,ds);
        
        return ans;
    }
};