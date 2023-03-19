Design Add and Search Words Data Structure

Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
    

struct Node{
    Node* arr[26];
    bool fl=false;
    bool containsKey(char ch){
        return  arr[ch-'a']!=NULL;
    }
    void createNewNode(char ch,Node* newNode){
        arr[ch-'a']=newNode;
    }
    Node* getNextNode(char ch){
        return arr[ch-'a'];
    }
};
class WordDictionary {
private:
    Node* root;
public:
    WordDictionary() {
        root=new Node();
    }
    
    void addWord(string word) {
       
        Node* temp=root;
        int n=word.size();
        for(int i=0;i<n;i++){
            if(!temp->containsKey(word[i])){
                temp->createNewNode(word[i],new Node());
            }
            temp=temp->getNextNode(word[i]);
        }
        temp->fl=true;
    }
    
    // O(26*len(word))
    bool searchCharByChar(int i,string &word,Node* temp){
        // Agar last mein pahunch gaya hai to temp->fl true hona chahiye
        if(i==word.size()) return temp->fl;
    
        // agar . hai to check karo is ith trie pe jo bhi character null na ho wo wala path lo aur check karo kahin true to ni return ho raha agar ho raha islka matlab ki us path ko liya ja sakta
        if(word[i]=='.'){
            for(char ch='a';ch<='z';ch++){
                if(temp->containsKey(ch)){
                    
                    // milte hi return true kardo age jane ki zarurat ni cnt to poocha ni hai ki poora traverse kar rahe tum
                    if(searchCharByChar(i+1,word,temp->getNextNode(ch))) return true;
                }
            }
        }else{
            
            // pehle to wo exist karna chahiye aur agar ni karta hai ya fir search karne par return false ata hai to seedhe return false karo koi if lagane ki zarurat ni
            return temp->containsKey(word[i]) && searchCharByChar(i+1,word,temp->getNextNode(word[i]));
        }
        
        // yahan aega ni lekin kar lo kya hi dikkat
        return false;
    }
    bool search(string word) {
        Node* temp=root;
        return searchCharByChar(0,word,temp);
    }
};