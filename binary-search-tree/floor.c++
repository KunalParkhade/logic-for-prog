// You are given a BST(Binary Search Tree) with n number of nodes and value x. your task is to find the greatest value node of the BST which is smaller than or equal to x.
// Note: when x is smaller than the smallest node of BST then returns -1.

// Example:

// Input:
// n = 7               2
//                      \
//                       81
//                     /     \
//                  42       87
//                    \       \
//                     66      90
//                    /
//                  45
// x = 87
// Output:
// 87
// Explanation:
// 87 is present in tree so floor will be 87.
// Example 2:

// Input:
// n = 4                     6
//                            \
//                             8
//                           /   \
//                         7       9
// x = 11
// Output:
// 9
// Your Task:-
// You don't need to read input or print anything. Complete the function floor() which takes the integer n and BST and integer x returns the floor value.

// Constraint:
// 1 <= Noda data <= 109
// 1 <= n <= 105

// Expected Time Complexity: O(height of tree)
// Expected Space Complexity: O(height of tree)

class Solution {
public:
    int floor(Node* root, int x) {
        int result=-1;
        if(root==nullptr) return -1;

        if(root->data==x){
          return root->data;
        }
        else if(root->data<x){
          int floorinRightsubtree = floor(root->right, x);
          return (floorinRightsubtree==-1)?root->data:floorinRightsubtree;
        }
        else{
          return floor(root->left, x);
        }

      return result;
    }
};
