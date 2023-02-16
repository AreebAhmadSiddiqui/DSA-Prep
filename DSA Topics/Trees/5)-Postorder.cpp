class Solution
{

    TC->O(N)
    SC->O(h) or
    O(logn) but in worst case O(n) skewed
    private:
    void help(TreeNode *root, vector<int> &ans)
    {
        if (root == NULL)
            return;

        help(root->left, ans);
        help(root->right, ans);
        ans.push_back(root->val);
    }

public : vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        help(root, ans);
        return ans;
    }

    // Iterative Postorder with 2 stack

    For all those struggling with intuition, it took me a while to figure it out but here it goes : In postorder, what we do ? If we are at node N, then we traverse the left and right child of the node, and after that, we push N, right ? Here we do the same thing using two stacks s1 and s2.S1 stores the left and right child, and s2 stores the node.When we take the top of s1 and assign it to s2, we are basically saying : "hey, deal with this node after treating its left and right child" cause stack is a lifo structure, so when we push the top of s1 to s2 and then we push the nodes of children of N to s1, we are doing the same thing as recursion i e.first looking for left and right child, and then looking at the parent node.Also, in s1, we add in left then right, so that in s2, it comes back as right then left and while popping from s2, it comes back in left then right again, i.e.it retains order.Hope this helped !!!!

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       public : vector<int> postorderTraversal(TreeNode * root)
    {

        if (root == NULL)
            return {};
        vector<int> ans;

        stack<TreeNode *> st1, st2;
        st1.push(root);

        // Post order -> Left Right Root

        // so in the end we want root
        // then right of root then left of root
        // i.e why we put tempRoot->left condition first
        while (!st1.empty())
        {
            TreeNode *tempRoot = st1.top();
            st1.pop();
            // It is basically a recursion step

            // hey keep the root node at i will deal it at the last so put in st2 so that it remains at the last
            st2.push(tempRoot);

            // if your left child is there lets explore it
            if (tempRoot->left)
                st1.push(tempRoot->left);

            // if your right child is there lets explore it
            if (tempRoot->right)
                st1.push(tempRoot->right);
        }

        while (!st2.empty())
        {
            ans.push_back(st2.top()->val);
            st2.pop();
        }

        return ans;
    }

    TC-> O(2N)
    SC-> O(N)
    public:
    vector<int> postorderTraversal(TreeNode* root) {
        
        if(root==NULL) return {};
        vector<int> ans;
        
        stack<TreeNode*> st;
        
        while(root!=NULL || !st.empty()){
            if(root!=NULL){
                st.push(root);
                root=root->left;
            }   
            // root is null
            else{
                TreeNode* temp=st.top()->right;
                if(temp==NULL){// it means i am a leaf node
                    
                    temp=st.top();
                    st.pop();
                    ans.push_back(temp->val);
                    
                    // No i need to go back to the root
                    while(!st.empty() && temp==st.top()->right){
                        temp=st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                }
                else{
                    root=temp;
                }
            }
        }
        return ans;
    }
}