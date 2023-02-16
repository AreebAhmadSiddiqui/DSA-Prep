int height(struct Node* node){
         
         
         // lvl order check

         TC -> O(n) 
         SC -> O(n) worst case

         if(node==NULL) return 0;
         queue<Node*> q;
         int ans=0;
         q.push(node);
         while(!q.empty()){
             
             int size=q.size();
             
             for(int i=0;i<size;i++){
                 Node* temp=q.front();
                 q.pop();
                 
                 if(temp->left) q.push(temp->left);
                 if(temp->right) q.push(temp->right);
             }
             ans++;
         }
         
         return ans;
        
        
        // Recursive
        
        TC -> O(n) 
        SC -> O(n) worst case
        if(node==NULL) return 0;
        
        return 1+max(height(node->left),height(node->right));
    }