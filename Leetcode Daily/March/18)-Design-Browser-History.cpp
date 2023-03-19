// struct Node{
//     string url;
//     Node* prev,*next;
    
//     Node(string _url){
//         url=_url;
//         prev=NULL;
//         next=NULL;
//     }
// };
// class BrowserHistory {
// private:
//     Node* head,*temp;
// public:
//     BrowserHistory(string homepage) {
//         head=new Node(homepage);
//         temp=head;
//     }
    
//     void visit(string url) {
//         Node* newNode=new Node(url);
//         temp->next=newNode;
//         newNode->prev=temp;
//         temp=newNode;
//     }
    
//     string back(int steps) {
//         while(temp->prev!=NULL && steps>0){
//             temp=temp->prev;
//             steps--;
//         }
        
//         return temp->url;
//     }
    
//     string forward(int steps) {
//         while(temp->next!=NULL && steps>0){
//             temp=temp->next;
//             steps--;
//         }
//         return temp->url;
//     }
// };
class BrowserHistory {
private:
    vector<string> history;
    int currPos,lastPos;
public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        currPos=0;
        lastPos=0;
    }
    
    void visit(string url) {
        // Array ke end mein add ho ya fir hamne kuch back operation perform kiye uske baad ye url visit kiya
        currPos+=1;
        if(history.size()>currPos){ // we need to add new url
            history[currPos]=url;
        }else{
            history.push_back(url);
        }
        lastPos=currPos;
    }
    
    string back(int steps) {
        
        currPos=max(0,currPos-steps);
        return history[currPos];
    }
    
    string forward(int steps) {
        
        int n=history.size()-1;
        currPos=min(lastPos,currPos+steps);
        return history[currPos];
    }
};