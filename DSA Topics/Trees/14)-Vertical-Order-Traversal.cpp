class Solution {
private:
    // TC-> O(nlogn)
    // SC-> O(N)+O(N) auxillary stack space worst case mein int hi to x honge
    void inOrder(TreeNode* root,map<int,map<int,multiset<int>>> &mp,int x,int l){
        if(root==NULL) return;

        mp[x][l].insert(root->val);
        inOrder(root->left,mp,x-1,l+1);
        inOrder(root->right,mp,x+1,l+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> mp; // {x,{lvl,set}}; // why lvl because we need to sort only those elements which at the same level and the same x mutiset isliye liya kyunki kai elements ki value same ho sakti hai pq bhi le sakte
        inOrder(root,mp,0,0);
        
        vector<vector<int>> ans;
        for(auto &vec:mp){
            vector<int> temp;
            for(auto &it:vec.second){
               for(auto &node:it.second){
                  temp.push_back(node);
               }
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};