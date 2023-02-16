STEPS

a) Yahan maine ek dummy node bana diya taki agar root bhi delete ho to dikkat na ae
b) Har node->left aur right check karo ki kahin wo key no ni hai agar hai
c) to sabse pehle left main jao aur right most banda utha lo kyunki wo dleete wali node se kam wala hoga
d) ab uske right ko dele node ke right wale se laga to aur agar left tree mein aya tha parent->left ko deleNode->left kar do
e) other wise parent->right ko delnode->right kar do
f) dono case mein same hi function hoga bas parent ka left aur right alag hoga tu uske liye function bana diya jo return karega ki kaunsa root ab parent ke left ya right mein lagega

class Solution {
private:
    TreeNode* helpDeleteNode(TreeNode* nodeToBeDeleted){
        
        if(nodeToBeDeleted->left==NULL){
            return nodeToBeDeleted->right;
            
        }
        else{
            auto temp2=nodeToBeDeleted->left;

            while(temp2->right){
                temp2=temp2->right;
            }

            temp2->right=nodeToBeDeleted->right;
            return nodeToBeDeleted->left;
        }
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* dummyNode=new TreeNode(INT_MIN);
        
        dummyNode->right=root;
        
        TreeNode* curr=dummyNode;
        
        while(curr!=NULL){
            if(curr->val<key){
                if(curr->right && curr->right->val==key){
                    auto nodeToBeDeleted=curr->right;
                    curr->right=helpDeleteNode(nodeToBeDeleted);
                    
                    delete nodeToBeDeleted;
                }
                curr=curr->right;
            }
            else{
                if(curr->left && curr->left->val==key){
                    auto nodeToBeDeleted=curr->left;
                    curr->left=helpDeleteNode(nodeToBeDeleted);
                    
                    delete nodeToBeDeleted;
                }
                curr=curr->left;
            }
        }
        return dummyNode->right;
    }
};