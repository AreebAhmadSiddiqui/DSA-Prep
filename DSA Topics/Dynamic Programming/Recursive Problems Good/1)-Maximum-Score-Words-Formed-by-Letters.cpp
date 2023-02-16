// Ismein hame simple subsequence wala lagana tha

au bas ek trick thi ki haar baar jab bhi pick karo to already jo cnt present hai unhe kam kar na tha aur wapi an par backtrack
class Solution {
private:
    bool isPossible(string &word,vector<int> &lettersCnt){
        vector<int> cntArr(26,0);
        
        for(int i=0;i<word.size();i++){
            cntArr[word[i]-'a']++;
            
            if(cntArr[word[i]-'a']>lettersCnt[word[i]-'a']){
                return false;
            }
        }
        return true;
    }
    
    void change(string &word,vector<int> &lettersCnt,int choice){
        
        for(int i=0;i<word.size();i++){
            if(choice==1) lettersCnt[word[i]-'a']--;
            else lettersCnt[word[i]-'a']++;
        }
    }
    int getSum(string &a,vector<int> &score){
        int sum=0;
        
        for(auto &ch:a){
            sum+=score[ch-'a'];
        }
        return sum;
    }
    int help(int i,vector<string> &words,vector<int> &score,vector<int> &lettersCnt){
        
        if(i==words.size()) return 0;
        
        int pick=0,notPick=0;
        if(isPossible(words[i],lettersCnt)){ 
            // Decrease The cnt
            change(words[i],lettersCnt,1); // 1 for decreasing (means ye word possible hai to letter cnt ko kam kar do kyunki ye word ho gaya)
            
            int sum=getSum(words[i],score);
            pick=sum+help(i+1,words,score,lettersCnt);
            
            change(words[i],lettersCnt,0); // 0 for increasing (jo kam kiya tha use bhda do)
            // Increase the cnt (Backtrack)
        }
        notPick=0+help(i+1,words,score,lettersCnt);
        return max(pick,notPick);
    }
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        
        int n=words.size();
        vector<int> lettersCnt(26,0);
        
        for(auto ch:letters){
            lettersCnt[ch-'a']++;
        }
        return help(0,words,score,lettersCnt);
    }
};