STEPS

a) Hamlog kya kar ki sab nodes ko ek number assign kare de rahe to usse kya hoga ki last wala banda minus first wala banda +1 kar ke answer a jaega

b) to numbering de do ab numbering kaise doge in BT agar kisi node ka number i hai to left wale ka 2*i+1 aur right ka 2*i+2 segment trees concept


But in case of a skewed tree we might end up in an overflow condition so instead of carrying 2*i+1 and 2*i+2 we can convert them into zero and one

By taking mini of the level jo ki pehla banda hoga queueu ka and subtracting it will come into 0 to 1
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        
        if(root==NULL) return 0;
        
        queue<pair<TreeNode*,long long>> q; // {node,index}
        
        int ans=INT_MIN;
        q.push({root,0});
        while(!q.empty()){
            
            int size=q.size(),minIdx=0,maxIdx=0;
            int minIndex=q.front().second; // as this will be the first guy inserted in a queue so minimum
            
            for(int i=0;i<size;i++){
                auto it=q.front();
                q.pop();
                
                TreeNode* node=it.first;
                int idx=it.second-minIndex; // to large numbers and converting to 0 1 based indexing
                
                if(i==0){ // first guy
                    minIdx=idx;
                }
                if(i==size-1){ // last guy
                    maxIdx=idx;
                }
                
                if(node->left) q.push({node->left,2*1ll*idx+1});
                if(node->right) q.push({node->right,2*1ll*idx+2});
            }
            
            ans=max(ans,maxIdx-minIdx+1);
        }
        
        return ans;
    }
};