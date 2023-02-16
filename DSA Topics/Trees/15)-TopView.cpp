class Solution
{
    
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    
    // TC -> O(NlogN)
    // Sc -> O(N+N)
    vector<int> topView(Node *root)
    {
        map<int,Node*> mp; // {x,node};
        queue<pair<Node*,int>> q; // {node,x};
        q.push({root,0});
        
        
        while(!q.empty()){
            Node* node=q.front().first;
            int x=q.front().second;
            q.pop();
            
            if(mp.find(x)==mp.end()){
                mp[x]=node;
            }
            
            if(node->left) q.push({node->left,x-1});
            if(node->right) q.push({node->right,x+1});
        }
        
        vector<int> ans;
        for(auto &vec:mp){
            int x=vec.first;
            Node* node=vec.second;
            ans.push_back(node->data);
        }
        
        return ans;
    }
};