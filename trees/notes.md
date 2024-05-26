# Tree

### Height or Depth of a tree

number of vertices from root node to the deepest node ( DFS problem)

**pseudo code**

if tree is empty then return 0

else then recursive call with left and right sub-tree
    
    max_depth of left subtree

    max_depth of righ  subtree
    
    max(max_depth(left-tree), max_depth(right-tree)) + 1




