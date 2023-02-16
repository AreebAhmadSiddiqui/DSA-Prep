class Solution {

private:
    bool isLeaf(TreeNode *node){
        return node->left==NULL && node->right==NULL;
    }
    void help(TreeNode* root,vector<string> &ans,string path){
        if(root==NULL) return;
        
        if(isLeaf(root)){
            string st=to_string(root->val);
            path+=st;
            ans.push_back(path);
            return;
        }
        
       
        path=path+to_string(root->val);
        help(root->left,ans,path+"->");
        help(root->right,ans,path+"->");
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        help(root,ans,"");
        return ans;
    }
};