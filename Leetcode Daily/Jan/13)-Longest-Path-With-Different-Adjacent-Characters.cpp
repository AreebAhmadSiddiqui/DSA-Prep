Pehli baat to mashallah khud se lagbhag kar diya tha bas ek galti thi wo abhi batata hun

a) Ye ek dum same problem hai diameter of a binary tree with a condition ki adjacent same ni honi chahiye
b) binary tree mein to asan tha ki mujhe lete hue mere agal bagal se kitna bada path banega
c) Wahan asan isliye tha kyunki usmein hamein left aur right do hi options the yahan pe hame kai options hai to ham kya kare max kab aega jab tumhare pass max aur second max ho haina??
d) Bas wahi nikalna hai max aur second max nikal lo aur ans mein store kar lo ek ans variable mein
e) aur jo bhi maxPath tha is node se use return kar do
f) main ek galti kar raha tha ki maine seedhe max(maxPath,maxPathSum+secondMaxPathSum) return kar raha tha lekin ye to galat hai na
g) iska matlab hai ki tum is node pe jo pathsum last mein return hua hoga usmein se max le rahe ye to koi sense hi ni bana raha
h) asal mein tumhe return sirf maxPathSum karna tha kyunki uska matlab is node se jo maxpath sum hai wo return kardo aur upar wala dekh lega ki kya karna
e) Hamne yahan pe dobar edge ni banai are kya fayda tum graph traverse thori na kar rahe ho seedhe seedhe ek baar jaoge aur jab dfs ho jaega tab calc karoge agar doosri edge rakhte to parent pointer aur visited wala chakkar ho jata to kya hi fayda aur yaad rakhna hamesha tree agar aise diya hai to do edge zyadatar ni bati aur agar bana bhi di to parent to ek hi hoga kyunki tree hai to kahin aur se wapis to aoge ni ispe lekin fir bhi kya hi fayda

class Solution {
private:
    int dfs(int node,vector<int> adj[],string &s,int &ans){
        
        int pathSum=0,maxPathSum=0,secondMaxPathSum=0;
        
        // Traverse its children
        for(auto child:adj[node]){
            
            // agar wo log adjacent colour ke hain tab 1 + kar do other wise 0+ se karo dfs haan ye karne ki zarurat ni thi tum seedhe dfs pass karo aur ye wali condition mein +1 kar do lekin ye zyada readable hai
            if(s[node]!=s[child]){
                
                // tumhare pass pathSum aya hoga 
                pathSum=1+dfs(child,adj,s,ans);
                
                // ab tumhe inmein se max aur secondMax nikalna hai nikal lo
                if(pathSum>=maxPathSum){
                    secondMaxPathSum=maxPathSum;
                    maxPathSum=pathSum;
                }
                else if(pathSum>secondMaxPathSum){
                    secondMaxPathSum=pathSum;
                }
            }
            else pathSum=0+dfs(child,adj,s,ans);

            // ham lo max aur second max yahan kyun ni kiya sirf s[node]!=s[child] mein kyun kiye because ham max aur second max sirf usi node ke liye nikalenge jinke children adjacent hai baaki ki liye thori na nikaloge kyunki agar ye node path mein hi ni hai to isko kyun lena
        }
        
        ans=max(ans,maxPathSum+secondMaxPathSum);
        return maxPathSum;
    }
public:
    int longestPath(vector<int>& parent, string s) {
            
        int n=parent.size();
        vector<int> adj[n];
       
        // Hamne yahan pe dobar edge ni banai are kya fayda tum graph traverse thori na kar rahe ho seedhe seedhe ek baar jaoge aur jab dfs ho jaega tab calc karoge agar doosri edge rakhte to parent pointer aur visited wala chakkar ho jata to kya hi fayda aur yaad rakhna hamesha tree agar aise diya hai to do edge zyadatar ni bati aur agar bana bhi di to parent to ek hi hoga kyunki tree hai to kahin aur se wapis to aoge ni ispe lekin fir bhi kya hi fayda
        for(int i=1;i<n;i++){
            int v=i;
            int u=parent[i];
            
            adj[u].push_back(v);
        }
        
        int ans=0;
        dfs(0,adj,s,ans); //{startNode,adj,s,ans}
        
        return ans+1;
    }
};