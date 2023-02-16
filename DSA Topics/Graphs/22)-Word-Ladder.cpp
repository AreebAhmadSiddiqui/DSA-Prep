YE WALA MAINE KHUD KIYA THA ACHA LAGA

a) NODES BANA DO JO 1 charcter ke difference pe hai fir shortest distance with unit wt nikal lo
b) agar endWord map mein ni hai ya end word ki value 1e9 hi rah gayi iska matlab not possible return zero
c) otherwise return map[endWord]+1

private:
    bool unitChange(string a,string b){
        int cnt=0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]){
                cnt++;
            }
        }
        return cnt==1;
    }
    public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        // adjacency map
        map<string,vector<string>> adj;
        
        vector<string> wordList2=wordList;
        wordList2.push_back(beginWord);
        
        // O(N*N*K)  N words and K length
        for(int i=0;i<wordList2.size();i++){
            for(int j=0;j<wordList2.size();j++){
                if(i!=j){
                    if(unitChange(wordList2[i],wordList2[j])){
                        adj[wordList2[i]].push_back(wordList2[j]);
                    }
                }
            }
        }
        
        
        // Find the shortest distance between beginWord and endWord
        
        map<string,int> dist; // node,dist
        for(int i=0;i<wordList2.size();i++){
            dist[wordList2[i]]=1e9;
        }
        
        // BFS
        queue<string> q; // {node,dist}
        q.push(beginWord); //src
        dist[beginWord]=0;
        
        
        while(!q.empty()){
            string node=q.front();
            q.pop();
            
            for(auto child:adj[node]){
               if(dist[node]+1<dist[child]){
                   q.push(child);
                   dist[child]=dist[node]+1;
               }
            
            }
        }
        
        if(adj.find(endWord)==adj.end() || dist[endWord]==1e9) return 0;
        return dist[endWord]+1;
    }


// STRIVER WALA

a) Ismein ham first word se shuru kar rahe aur ek ek character ko remove kar rahe
b) Agar wo banda wordlist ya set mein hai to remove kar do isko kyunki ham log ispe dobar ni aenge aisa kyun?
c) dekho agar hamne delete ni kiya to yahi same word kuch aur bana sakte aur jo naya word bana usmein same character ko change karne pe firse yahi aega to infinitely chelga
d) isliye agar a gaya hai to q mein dal do aur delte kardo waise bhi wo mini hi hoga

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<pair<string,int>> q;  // {word,dis}
        q.push({beginWord,1});
        
        // avg -> O(n*k*26*1)  worst case -> O(n*k*26*n)
        while(!q.empty()){ // O(n)
            string word=q.front().first;
            int steps=q.front().second;
            q.pop();
            // No convert this word by changing its characters and check if it exist
            
            
            for(int i=0;i<word.size();i++){ // O(k*26*log(n))
                string tempWord=word;
                for(char ch='a';ch<='z';ch++){
                    tempWord[i]=ch;
                    if(st.find(tempWord)!=st.end()){ // it means word is there in the set
                        q.push({tempWord,steps+1}); // ek level badh gaya
                        st.erase(tempWord); // is word par wapis kyun aoge agar ae to distance badh jeaga to delete kardo
                    }
                }
            }
            
            if(word==endWord){
                return steps;
            }
        }
        return 0;
    }
};