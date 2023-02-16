class Solution {
    // This is O(n2) solutions see in case of left skewed tree you will end up traversing the entire array n times and for n nodes n*n O(n2)
    TreeNode* help(vector<int> &preorder,int preStart,int preEnd){
        if(preStart>preEnd) return NULL;
        
        TreeNode *root=new TreeNode(preorder[preStart]);
        int i=preStart+1;
        for(;i<preorder.size();i++){
            if(preorder[i]>preorder[preStart]){
                break;
            }
        }
        root->left=help(preorder,preStart+1,i-1);
        root->right=help(preorder,i,preEnd);
        
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return help(preorder,0,preorder.size()-1);
    }

    // O(N)
private:

    // Ismein ham upperbound aur lowebound ka concept use kar rahe haan lowerbound ki zarurat ni padegi lekin rakhlo samjhne kie liye
    // aur kyun ni padegi uske answer ke liye ek tree dry run karo

    Ek baat aur yahan i ko & se pass isliye kar rahe kyunki jab bhi ham i++ kar rahe to ek value pe pahunch rahe lekin agar man lo wo value wahan valid ni hai to wapis jab return karenge to i kam ho jaega lekin hame to wahi i chahiye jo place ni ho paya

    dekho agar aisa case ho ki hame 7 dalna hai aur arrary aisa hai

    8 5 1 7 10 12

    ham 8 5 1 dal chuke ab 7 pe ae
    to 1 ke na left na right mein lagega

    lekin jaise hi upar gae ham to i 5 pe chala jaega to i+1 se wo 1 ko place karne lagega isliye galat ho jaega hame to 7 ko dekhna tha
    TreeNode* help(vector<int> &preorder,int &i,int lowerBound,int upperBound){
        if(i==preorder.size() || preorder[i]>=upperBound || preorder[i]<=lowerBound) return NULL;
         
        TreeNode* root=new TreeNode(preorder[i++]);
        root->left=help(preorder,i,lowerBound,root->val);
        root->right=help(preorder,i,root->val,upperBound);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return help(preorder,i,INT_MIN,INT_MAX);
    }
};