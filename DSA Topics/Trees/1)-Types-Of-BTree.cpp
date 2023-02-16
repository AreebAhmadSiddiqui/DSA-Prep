1) Full Binary Tree

Every node has either 0 nodes or 2 nodes

   1
  / \
 2   3

 2) Complete Binary Tree

 -> All levels are completely filled except the last level
 -> The last level has all nodes as left as possible

  Example 

      1              
     / \
    2   3   a ct
   / \  
  4   5       

      1
     / \
    2   3   not a ct as the last lvl nodes are not as left as possible
   / \   \
  4   5   6

      1
     /  \
    2    3  a ct as the last lvl nodes are left   
   / \   /
  4   5 6

  3) Perfect Binary Tree

  All leaf nodes are at the same level

      1
     / \
    2   3  not a pbt
   / \  
  4   5

      1
     /  \
    2    3  a pbt
   / \   / \
  4   5  6  7

  4) Balanced Binary Tree

  Height of the tree at max log(n)
  
  5) Degenerate Tree or a skewed tree

  Every node has only one child linked list
