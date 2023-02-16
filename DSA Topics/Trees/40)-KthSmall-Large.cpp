class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        
        // Morris inorder traversal aur jab bhi ham kisi node pe visi karenge tab cnt++ kar dena aur jaise hi cnt==k wo kth smallest hoga
        // For largest count no of nodes and calculate n-k-1 smallest element or you can do reverse in order right root left and find k the largest
        int cnt=0,ans=-1;
        TreeNode* curr=root;
        while (curr != NULL)
        {

        if (curr->left == NULL)
        {
            cnt++;
            if(cnt==k) {
                ans=curr->val;
            }
            curr = curr->right;
        }
        else
        {
            TreeNode *temp = curr->left;
            while (temp->right && temp->right != curr)
            {
                temp = temp->right;
            }
            
            if (temp->right == NULL)
            {
                temp->right = curr;
                curr = curr->left;
            }
            else
            {
                temp->right = NULL;
                cnt++;
                if(cnt==k) {
                    ans=curr->val;
                }
                curr = curr->right;
                }
            }
        }
        
        return ans;
    }
};



// Largest in One Pass you can do morris as well reverse morris
class Solution
{
    public:
    int kthLargest(Node *root, int k)
    {
        vector<int> ans;
        stack<Node*> st;
        int cnt=0;
        while(root!=NULL || !st.empty()){
            
            // Left subtree exhauted print the root which is at the stack top
            if(root==NULL){
                root=st.top();
                st.pop();
                // ans.push_back(root->data);
                cnt++;
                if(cnt==k) return root->data;
                root=root->left;
            }
            else{
                st.push(root);
                root=root->right;
            }
        }
        
        return -1;
    }
};