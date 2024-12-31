## LCA Optimized Approach
In this method we are assuming that both nodes are present in the tree, if one is present and other is not then it returns the present node as LCA.
If none are present then it returns NULL.

1. If node is same as node1 or node2, we return the current node as LCA.
2. If its left subtree has one node & the right subtree has the other, then current node will be LCA.
3. If its subtree has both the node, then LCA will also be in the subtree, check for LCA in below subtree.
