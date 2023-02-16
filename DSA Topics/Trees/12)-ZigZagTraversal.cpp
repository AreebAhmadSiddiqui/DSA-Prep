/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    // TC-> O(2N) reverse operation ki wajeh se
    // SC-> O(N+N)
//     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//         vector<vector<int>> ans;
        
//         if(root==NULL) return ans;
//     	queue<TreeNode*> q;
//     	q.push(root);
//     	int flag=0; // 0- l->r 1-> r->l;
//     	while(!q.empty()){
//     	    int size=q.size();
//     	    vector<int> temp;
//     	    for(int i=0;i<size;i++){
//     	        TreeNode* tempNode=q.front();
//     	        q.pop();
//     	        temp.push_back(tempNode->val);
                    
//     	        if(tempNode->left) q.push(tempNode->left);
//     	        if(tempNode->right) q.push(tempNode->right);
//     	    }
//             if(flag==0){ // left to right
//                 ans.push_back(temp);
//             } 
//             else{
//                 reverse(temp.begin(),temp.end());
//                 ans.push_back(temp);
//             }
//             flag=1-flag;
//     	}
//     	return ans;
//     }
    
    
     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        if(root==NULL) return ans;
    	queue<TreeNode*> q;
    	q.push(root);
    	
         int flag=0; // 0- l->r 1-> r->l;
         
    	while(!q.empty()){
    	    int size=q.size();
    	    vector<int> temp(size,0);
    	    for(int i=0;i<size;i++){
    	        TreeNode* tempNode=q.front();
    	        q.pop();
    	        
                // if it is left to right insert from 1st index
                // if it is right to left insert from last index
                
                if(flag==0){  // left to right
                    temp[i]=tempNode->val;
                }else{
                    temp[size-i-1]=tempNode->val;
                }
                    
    	        if(tempNode->left) q.push(tempNode->left);
    	        if(tempNode->right) q.push(tempNode->right);
    	    }
            
            ans.push_back(temp);
            flag=1-flag;
    	}
    	return ans;
    }
};