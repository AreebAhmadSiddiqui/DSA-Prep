/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    // Seedhe seedhe bfs karte jao bas visited mein old node or new node ko rakho taki agar dooabr visited wala case ae to ni node na bana do jo previous node ka pointer hai use hi use kar lo
    
    Node* cloneGraph(Node* node) {
        
        if(node==NULL) return NULL;
        Node* rootNode=new Node(node->val);
        queue<pair<Node*,Node*>> q; //{initialNode,newNode};
        q.push({node,rootNode});
        unordered_map<Node*,Node*> vis;
        vis[node]=rootNode;
        
        while(!q.empty()){
            
            Node* oriNode=q.front().first;
            Node* copyNode=q.front().second;
            q.pop();
            
            for(auto &child:oriNode->neighbors){
                
                if(vis.find(child)!=vis.end()) {
                    copyNode->neighbors.push_back(vis[child]);
                    continue;
                }
                
                Node* newChildNode=new Node(child->val);
                copyNode->neighbors.push_back(newChildNode);
                
                q.push({child,newChildNode});
                vis[child]=newChildNode;
            }
        }
        return rootNode;
    }
};