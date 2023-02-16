
class Solution {
private:
    int dfs(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent,TreeNode* lastVisited){
        if(root==NULL) return 0;
        
        // check left
        int left=INT_MIN,right=INT_MIN,up=INT_MIN;
        if(root->left!=lastVisited)
            left=dfs(root->left,parent,root);
        
        // check right
        if(root->right!=lastVisited)
            right=dfs(root->right,parent,root);
        
        // check parent
        if(parent[root]!=lastVisited){
            up=dfs(parent[root],parent,root);
        }
        
        return max(left,max(right,up))+1;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        
        unordered_map<TreeNode*,TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);
        
        TreeNode* targetNode;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            
            if(node->left){
                q.push(node->left);
                parent[node->left]=node;
            }
            if(node->right){
                q.push(node->right);
                parent[node->right]=node;
            }
            if(node->val==start){
                targetNode=node;
            }
        }
        
        
        int time=-1;
        
        unordered_set<TreeNode*> visited;
        
        visited.insert(targetNode);
        q.push(targetNode);
        
        while(!q.empty()){
            
            int size=q.size();
            
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                
                if(node->left != NULL && visited.find(node->left) == visited.end()){
                    q.push(node->left);
                    visited.insert(node->left);
                }
                if(node->right != NULL && visited.find(node->right) == visited.end()){
                    q.push(node->right);
                    visited.insert(node->right);
                }
                if(parent[node] != NULL && visited.find(parent[node]) == visited.end()){
                    q.push(parent[node]);
                    visited.insert(parent[node]);
                }
            }
            
            time++;
        }
        
        return time;
        
        // return dfs(targetNode,parent,targetNode)-1;
    }
};