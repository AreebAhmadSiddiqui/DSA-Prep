// Main String Stream Hai


class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string code="";
        
        if(root==NULL) return code;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            
            if(node==NULL) {
                code+="n/";  
                continue;
            }
            
            code+=to_string(node->val);
            code+="/";
            
            q.push(node->left);
            q.push(node->right);
        }
        
        return code;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        if(data.size()==0) return NULL;
        
        queue<TreeNode*> q;
        
        stringstream ss(data); 
        string str;
        getline(ss,str,'/');
        TreeNode* root=new TreeNode(stoi(str));
        q.push(root);
        
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            
            getline(ss,str,'/');
            
            if(str!="n"){ //left
                TreeNode* leftChild=new TreeNode(stoi(str));
                q.push(leftChild);
                node->left=leftChild;
            }
            
            getline(ss,str,'/');
            if(str!="n"){
                TreeNode* rightChild=new TreeNode(stoi(str));
                q.push(rightChild);
                node->right=rightChild;
            }
        }
        
        return root;
    }
};