// DFS bhi kar sakte aur iterative bhi
class Solution {
private:
    bool isLeaf(TreeNode* root){
        return root->left==NULL && root->right==NULL;
    }
//     int sumNumbers(TreeNode* root,int sum){
//         if(root==NULL) return 0;
//         if(isLeaf(root)) return sum*10+root->val;
        
//         int leftSum=sumNumbers(root->left,sum*10+root->val);
//         int rightSum=sumNumbers(root->right,sum*10+root->val);
        
//         return leftSum+rightSum;
//     }
public:
    int sumNumbers(TreeNode* root) {
        
        // Simple level order traversal kar do maine ek solution stack based bhi kiya tha i dont know why but kiya tha
        // Lvl Order Traversal;
        queue<pair<TreeNode*,int>> q; // {root,sumTilNow}
        q.push({root,0});
        int sum=0;
        
        while(!q.empty()){
            TreeNode* node=q.front().first;
            int currSum=q.front().second;
            q.pop();
            
            if(isLeaf(node)) sum+=currSum*10+node->val;
            
            if(node->left) q.push({node->left,currSum*10+node->val});
            if(node->right) q.push({node->right,currSum*10+node->val});
        }
        
        return sum;
    }
};