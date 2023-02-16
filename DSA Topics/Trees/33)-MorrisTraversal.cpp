// MORRIS TRAVERSAL (ammortized O(N))+ O(N)  O(1)
vector<int> inorderTraversal(TreeNode *root)
{

    vector<int> inorder;
    TreeNode *curr = root;
    while (curr != NULL)
    {

        if (curr->left == NULL)
        {
            inorder.push_back(curr->val);
            curr = curr->right;
        }
        else
        {

            // make thread by going to the right most elemnent of the left subtree
            TreeNode *temp = curr->left;
            while (temp->right && temp->right != curr)
            {
                temp = temp->right;
            }

            // Make thread
            if (temp->right == NULL)
            {
                temp->right = curr;
                preorder.push_back(curr->val); // you are coming to this node first time so preorder.push_back
                curr = curr->left;
            }
            // delete thread you are coming on curr the second time
            else
            {
                temp->right = NULL;
                inorder.push_back(curr->val); // since you are coming second time add it into inorder
                curr = curr->right;
            }
        }
    }

    return inorder;
}