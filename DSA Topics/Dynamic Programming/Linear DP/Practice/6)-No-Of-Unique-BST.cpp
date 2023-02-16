Let's start by trying to solve the problem in Brute-Force manner. To form structurally unique BST consisting of n nodes, we can start by taking any of the node 1...n as the root node. Let the chosen root node be i. Then, we have a BST where the root node is i, the left child consist of all nodes from 1...i-1 (since left sub-tree must have only less than root's value) and right child consist of all nodes from i+1...n.

	
              1            1                   2                    3               3
	           \            \                 / \                  /               /
    	        3             2              1   3                2               1
               /               \                                 /                 \
              2                 3                              1                    2
                     i = 1                   i = 2                       i = 3           
(i = root node)
Now, we need to realize that the number of structurally unique BST formable with nodes having value i+1...n is equal to the number of structurally unique BST formable with nodes having value i+1-i...n-i = 1...n-i. Why? Because we only need to find BST which are structurally unique irrespective of their values and we can form an equal number of them with nodes from 1...n or 2...n+1 or n...2n-1 and so on. So, the number only depends on number of nodes using which BST is to be formed.

Now, when we choose i as root node, we will have nodes from 1...i-1 (i-1 nodes in total) in left sub-tree and nodes from i+1...n (n-i nodes in total) in the right side. We can then form numTrees(i-1) BSTs for left sub-tree and numTrees(n-i) BSTs for the right sub-tree. The total number of structurally unique BSTs formed having root i will be equal to product of these two, i.e, numTrees(i-1) * numTrees(n-i). The same can be followed recursively till we reach base case - numTrees(0) = numTrees(1) = 1 because we can form only a single empty BST and single node BST in these cases respectively.

The final answer will be summation of answers considering all 1...n as root nodes.

           3                          2                         1               
          / \                        / \                      /   \      
numTrees(2) numTrees(0)    numTrees(1) numTrees(1)   numTrees(0) numTrees(2)              
         i = 3                      i = 2                     i = 1           
		 
                      i
	=>              /   \ 
         numTrees(i-1)	numTrees(n-i)

class Solution {
private:
    long long nCr(int n,int r){
        
        long long ans=1;
        for(int i=1;i<=r;i++){
            ans=ans*(n-(i-1))/i;
        }
        return ans;
    }
//     int help(int i,vector<int> &dp){  // { For curr Subtree I have i nodes}
//         if(i==0) return 1;
        
//         if(dp[i]!=-1) return dp[i];
        
//         int sum=0;
//         for(int k=1;k<=i;k++){
//             sum+=help(k-1,dp)*help(i-k,dp);
//         }
//         return dp[i]=sum;
//     }
    
//     int tabulation(int n){
//         vector<int> dp(n+1,0);
        
//         // Base Case
//         dp[0]=1;
        
//         for(int i=1;i<=n;i++){
//             int sum=0;
//             for(int k=1;k<=i;k++){
//                 sum+=dp[k-1]*dp[i-k];
//             }
//             dp[i]=sum;
//         }
//         return dp[n];
//     }
public:
    int numTrees(int n) {


        // Aur haan n nodes hai wo ho kuch bhi sakti matlab unki values kuch bhi ho sakti hai 

        // vector<int> dp(n+1,-1);
        // return help(n,dp);
        
        // return tabulation(n);
        
        // return nCr(2*n,n)/(n+1);
        
        long long ans=1;
        int prev=1; // for C0
        for(int i=1;i<=n;i++){
            // Cn = (4n-2)*(Cn-1)/(n+1)
            
            ans=((4*i-2)*1ll*prev)/(i+1);
            
            prev=ans;
        }
        
        return ans;
    }
};

Applications Of Catlan Number:

(Ek bandi ka video hai wo dekh lena)
(Ya fir sumeet sir ka)
1) Number of possible Binary Search Trees with n keys.
2) Number of expressions containing n pairs of parentheses which are correctly matched. For n = 3, possible expressions are ((())), ()(()), ()()(), (())(), (()()).
3) Number of ways a convex polygon of n+2 sides can split into triangles by connecting vertices. 
4) Number of full binary trees (A rooted binary tree is full if every vertex has either two children or no children) with n+1 leaves.
5) Number of different Unlabeled Binary Trees can be there with n nodes.
6) The number of paths with 2n steps on a rectangular grid from bottom left, i.e., (n-1, 0) to top right (0, n-1) that do not cross above the main diagonal.
7) Number of ways to insert n pairs of parentheses in a word of n+1 letters, e.g., for n=2 there are 2 ways: ((ab)c) or (a(bc)). For n=3 there are 5 ways, ((ab)(cd)), (((ab)c)d), ((a(bc))d), (a((bc)d)), (a(b(cd))).
8) Number of noncrossing partitions of the set {1, …, 2n} in which every block is of size 2. A partition is noncrossing if and only if in its planar diagram, the blocks are disjoint (i.e. don’t cross). For example, below two are crossing and non-crossing partitions of {1, 2, 3, 4, 5, 6, 7, 8, 9}.  The partition {{1, 5, 7},  {2, 3, 8}, {4, 6}, {9}} is crossing and partition {{1, 5, 7}, {2, 3}, {4}, {6}, {8, 9}} is non-crossing. 
9) Number of Dyck words of length 2n. A Dyck word is a string consisting of n X’s and n Y’s such that no initial segment of the string has more Y’s than X’s.  For example, the following are the Dyck words of length 6: XXXYYY     XYXXYY     XYXYXY     XXYYXY     XXYXYY.
10) Number of ways to tile a stairstep shape of height n with n rectangles. The following figure illustrates the case n = 4: 
11) Number of ways to connect the points on a circle disjoint chords.  This is similar to point 3 above.
12) Number of ways to form a “mountain ranges” with n upstrokes and n down-strokes that all stay above the original line.The mountain range interpretation is that the mountains will never go below the horizon.