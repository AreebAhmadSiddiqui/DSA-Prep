struct TrieNode{
    vector<TrieNode*> arr;
    bool fl;
    
    TrieNode(){
        arr.resize(26);
        fl=false;
    }
    bool containsKey(char ch){
        return arr[ch-'a']!=NULL;
    }
    void put(char ch,TrieNode* temp){
        arr[ch-'a']=temp;
    }
    TrieNode* get(char ch){
        return arr[ch-'a'];
    }
};
class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node=root;
        int n=word.size();
        for(int i=0;i<n;i++){
            if(!node->containsKey(word[i])){
                // Create a new TriePointer
                node->put(word[i],new TrieNode());
            }
            node=node->get(word[i]);
        }
        node->fl=true;
    }
    
    bool search(string word) {
        
        TrieNode* node=root;
        int n=word.size();
        for(int i=0;i<n;i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node=node->get(word[i]);
        }
        // last value should be flag==true;
        
        return node->fl;
    }
    
    bool startsWith(string word) {
        TrieNode* node=root;
        int n=word.size();
        for(int i=0;i<n;i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node=node->get(word[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */