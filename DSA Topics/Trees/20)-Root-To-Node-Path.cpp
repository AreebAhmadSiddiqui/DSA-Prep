
Steps

a) Dono left ya right subtree mein agar koi tru return karta hai to immediately true return kardo
b) otherwise pop karo aur peehce jao return false karke
bool help(TreeNode* root,int dest,vector<int> &path){
    if(root==NULL) return false;
    
    path.push_back(root->val);
    
    if(root->val==dest){
        return true;
    }
    
    if(help(root->left,dest,path) || help(root->right,dest,path)){ // we got our answer
        return true;
    }
    
    path.pop_back();
    return false;
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> path;
    
    help(A,B,path);
    
    return path;
}