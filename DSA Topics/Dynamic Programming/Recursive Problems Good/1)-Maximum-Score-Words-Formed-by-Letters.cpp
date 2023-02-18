Maximum Score Words Formed by Letters

Given a list of words, list of  single letters (might be repeating) and score of every character.

Return the maximum score of any valid set of words formed by using the given letters (words[i] cannot be used two or more times).

It is not necessary to use all characters in letters and each letter can only be used once. Score of letters 'a', 'b', 'c', ... ,'z' is given by score[0], score[1], ... , score[25] respectively.
    
Input: words = ["dog","cat","dad","good"], letters = ["a","a","c","d","d","d","g","o","o"], score = [1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0]
Output: 23

Explanation:
Score  a=1, c=9, d=5, g=3, o=2
Given letters, we can form the words "dad" (5+1+5) and "good" (3+2+2+5) with a score of 23.
Words "dad" and "dog" only get a score of 21.   

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
            change(words[i],lettersCnt,1); // 1 for decreasing
            
            int sum=getSum(words[i],score);
            pick=sum+help(i+1,words,score,lettersCnt);
            
            change(words[i],lettersCnt,0); // 0 for increasing
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