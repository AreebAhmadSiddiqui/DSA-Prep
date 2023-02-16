Steps

a) Brute to hoga ki tum vlidate bst karo har node ki liye aur agar true ae to number of nodes us subtree mein count kar lo lekin wo zyada time lega

b) Yahan pe ham kar rahe ki koi agar mujhe left ka max de de aur right ka min to mein ji node pe khada hun use bata sakta ki valid hai ki ni
c) bas yahi karna pehle left fir right aur ant mein root ko process kar na hai to use postorder
d) agar koi leaf node ae to wo bst hogi 1 size ki return {1,val,val} {size,minOfSubtree,maxOfSubtree} for every node

e) man lo ki null ho gaya to left tree ka max int min le lo aur right tree ka min int max le lo taki valid rahe aur size 0

f) ab apni node ki validity check kar lo agar hai tab to size of left + size of right + main( yani + 1) aur leftMax mein tum dono ka min aur rightMin mein tum dono ka max 

g) aur agar apni node valid ni hai to aise number pass kar do ki kabhi answer na ae size would be max(left,right) aur leftMax=INT_MAX, rightMIn=INT_MIN

class Solution{
    public:
    vector<int> helper(Node* root){
        if(root==NULL) return {0,INT_MAX,INT_MIN};
        
        if(root->left==NULL && root->right==NULL) return {1,root->data,root->data};
        
        vector<int> left=helper(root->left);
        vector<int> right=helper(root->right);
        
        if(root->data<=left[2] || root->data>=right[1]) return {max(left[0],right[0]),INT_MIN,INT_MAX};
        
        return {left[0]+right[0]+1,min(root->data,left[1]),max(root->data,right[2])};
        // Ham log upar min auur max kyun kar rahe min to left[1] hi hoga aur right ka max right[2] hi hoga kyun??? are bhai upar dekho base case bhi to likha hai
        // jab null ho root tab to min main int_max, aur max mein int min return ho rha hai agar tumne upar min() aur max of ni likha to yahi chale jaenge upar root ke taraf lekin ye to galata ho jaega na isliye aisa kar rahe
    }
    int largestBst(Node *root)
    {

    	vector<int> ds=helper(root);
    	
    	return ds[0];
    }
};