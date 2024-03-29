Construct Quad Tree

Given a n * n matrix grid of 0's and 1's only. We want to represent the grid with a Quad-Tree.

Return the root of the Quad-Tree representing the grid.

Notice that you can assign the value of a node to True or False when isLeaf is False, and both are accepted in the answer.

A Quad-Tree is a tree data structure in which each internal node has exactly four children. Besides, each node has two attributes:

val: True if the node represents a grid of 1's or False if the node represents a grid of 0's.
isLeaf: True if the node is leaf node on the tree or False if the node has the four children.
class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;
}
We can construct a Quad-Tree from a two-dimensional area using the following steps:

If the current grid has the same value (i.e all 1's or all 0's) set isLeaf True and set val to the value of the grid and set the four children to Null and stop.
If the current grid has different values, set isLeaf to False and set val to any value and divide the current grid into four sub-grids as shown in the photo.
Recurse for each of the children with the proper sub-grid.

If you want to know more about the Quad-Tree, you can refer to the wiki.

Quad-Tree format:

The output represents the serialized format of a Quad-Tree using level order traversal, where null signifies a path terminator where no node exists below.

It is very similar to the serialization of the binary tree. The only difference is that the node is represented as a list [isLeaf, val].

If the value of isLeaf or val is True we represent it as 1 in the list [isLeaf, val] and if the value of isLeaf or val is False we represent it as 0.

 

Example 1:


Input: grid = [[0,1],[1,0]]
Output: [[0,1],[1,0],[1,1],[1,1],[1,0]]
Explanation: The explanation of this example is shown below:
Notice that 0 represnts False and 1 represents True in the photo representing the Quad-Tree.
    


Abe tum jis i aur j pe khade agar wo ho sakta hai quad tree to seedhe return kardo
otherwise recursive call maro apne charo bachon pe aur same cheez solve kar do

size/2 wala scene rahta hai
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
private:
    bool allSame(vector<vector<int>> &grid,int i,int j,int maxSize){
        
        int val=grid[i][j];
        
        for(int row=i;row<i+maxSize;row++){
            for(int col=j;col<j+maxSize;col++){
                if(grid[row][col]!=val) return false;
            }
        }
        return true;
    }
    Node* help(vector<vector<int>> &grid,int i,int j,int maxSize){
        
        if(allSame(grid,i,j,maxSize)){
            bool val=grid[i][j];
            bool isLeaf=true;
            Node* newNode=new Node(val,isLeaf);
            
            return newNode;
        }
        
        // Do the same thing for 4 sub grids
        
//         1st grid would start at [i,j]
//         2nd grid would start at [i,j+maxSize/2]
//         3rd grid would start at [i+maxSize/2,j]
//         4th grid would start at [i+maxSize/2,j+maxSize/2]
        
        Node* newNode=new Node(false,false);
        
        newNode->topLeft=help(grid,i,j,maxSize/2);
        newNode->topRight=help(grid,i,j+maxSize/2,maxSize/2);
        newNode->bottomLeft=help(grid,i+maxSize/2,j,maxSize/2);
        newNode->bottomRight=help(grid,i+maxSize/2,j+maxSize/2,maxSize/2);
        
        return newNode;
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        
        int maxSize=grid.size();
        return help(grid,0,0,maxSize);
        
    }
};