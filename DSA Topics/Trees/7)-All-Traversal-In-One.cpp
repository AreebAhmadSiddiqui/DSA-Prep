public:
TC-> O(3N)
SC-> O(4N)
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> pre,in,post;
        stack<pair<TreeNode*,int>> st;
        
        st.push({root,1});
        while(!st.empty()){
            
            auto it=st.top();
            TreeNode* temp=it.first;
            int number=it.second; 
            //Example
            
//                  1
//                 / \
//                2   3
            
//             1 you will visit 1 one time then go to 2 then visit 2 , one time then null is there i.e left pre is over so 
//             2 you will comp back and visit 2 two time then go right as in inorder
//             3 if right is over then you come back to 2 again i.e 3rd time and add in postOrder
            
            
            // here the number signifies the no of times i visited the node if i vist it 1 times it is preorder and then i need to go left that is why i check only for left
            // if the number is 2 then it signifies the inorder and it means i need to print myself and go right if possible
            // and if left and right are done then my number would be 3 it means i am post order simply push myself
            st.pop();
            
            if(number==1){ // preOrder
                pre.push_back(temp->val);
                it.second++;
                st.push(it);
                if(temp->left) st.push({temp->left,1});
            }
            else if(number==2){ // inOrder
                in.push_back(temp->val);
                it.second++;
                st.push(it);
                if(temp->right) st.push({temp->right,1});
            }
            else{ // postOrder
                 post.push_back(temp->val);
            }
        }
        
        return pre;
    }