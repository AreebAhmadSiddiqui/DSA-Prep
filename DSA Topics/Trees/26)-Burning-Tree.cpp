STEPS

a) Ham log do tareeq se solve kar sakte parent pointer bana do
b) fir bfs bhi kar sakte aur dfs bhi
c) bfs mein visited set lena padega 
d) aur agar dfs karna hai to uska intuition yhain ki is node se maxi doori sabse door wali node ki is the answer
e) aur haan dfs wale mein ans-1 kar dena kyunki wo us node ko bhi gin lega jajhan se jalna hai

class Solution {
  private:
  
    // int dfs(Node* root,unordered_map<Node*,Node*> &parent,Node* lastVisited){
    //     if(root==NULL) return 0;
        
    //    // check left
    //     int left=INT_MIN,right=INT_MIN,up=INT_MIN;
    //     if(root->left!=lastVisited)
    //         left=dfs(root->left,parent,root);
        
    //     // check right
    //     if(root->right!=lastVisited)
    //         right=dfs(root->right,parent,root);
        
    //     // check parent
    //     if(parent[root]!=lastVisited){
    //         up=dfs(parent[root],parent,root);
    //     }
        
    //     return max(left,max(right,up))+1;
    // }
  public:
    int minTime(Node* root, int target) 
    {
        // Step 1
        
        // Create Parent Pointers
        
        unordered_map<Node*,Node*> parent;
        queue<Node*> q;
        q.push(root);
        
        Node* targetNode;
        while(!q.empty()){
            Node* node=q.front();
            q.pop();
            
            if(node->left){
                q.push(node->left);
                parent[node->left]=node;
            }
            if(node->right){
                q.push(node->right);
                parent[node->right]=node;
            }
            if(node->data==target){
                targetNode=node;
            }
        }
        
        Step 2
        
        Lets burn but what we will do is the bfs
        
        int time=-1;
        
        unordered_set<Node*> visited;
        
        visited.insert(targetNode);
        q.push(targetNode);
        
        while(!q.empty()){
            
            int size=q.size();
            
            for(int i=0;i<size;i++){
                Node* node=q.front();
                q.pop();
                
                if(node->left != NULL && visited.find(node->left) == visited.end()){
                    q.push(node->left);
                    visited.insert(node->left);
                }
                if(node->right != NULL && visited.find(node->right) == visited.end()){
                    q.push(node->right);
                    visited.insert(node->right);
                }
                if(mp[node] != NULL && visited.find(mp[node]) == visited.end()){
                    q.push(mp[node]);
                    visited.insert(mp[node]);
                }
            }
            
            time++;
        }
        
        return time;
        
        
        // return dfs(targetNode,parent,targetNode)-1;
    }
};