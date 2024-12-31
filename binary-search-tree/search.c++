// # Intuition
// The problem involves searching for a value in a Binary Search Tree (BST). A BST has a property that for any node, values in the left subtree are smaller, and values in the right subtree are larger. This property allows us to efficiently navigate the tree to find the desired value.

// Initially, the thought is to compare the target value with the root:
// 1. If it matches the root, return the root.
// 2. If it's smaller, move to the left child.
// 3. If it's larger, move to the right child.

// This logic can be implemented recursively (naturally matching the tree's structure) or iteratively (avoiding the overhead of recursive calls).

// # Approach
// ## Recursive Way:
// 1. Base Case:
//     - If the current node is `nullptr`, the value is not present in the tree, so return `nullptr`.
//     - If the value of the current node matches the target, return the current node.
// 2. Recursive Step:
//     - If the target value is smaller than the current node's value, recursively search the left subtree.
//     - If the target value is larger than the current node's value, recursively search the right subtree.

// ## Iterative Way:
// 1. Start from the root and use a loop to traverse the tree.
// 2. At each step:
//     - If the current node is `nullptr`, the value is not found, return `nullptr`.
//     - If the value of the current node matches the target, return the current node.
//     - If the target value is smaller than the current node's value, move to the left child.
//     - If the target value is larger than the current node's value, move to the right child.

// This approach avoids recursion and uses constant space for the call stack.

// # Complexity
// - Time complexity: $$O(h)$$ where ℎ is the height of the tree. In the worst case (unbalanced tree), $$h = n$$, and in the best case (balanced tree), $$h=logn$$

// - Space complexity:
//     - Recursive Approach: $$O(h)$$ due to the recursive call stack.
//     - Iterative Approach: $$O(1)$$ as it doesn't use additional memory for recursion.

// # Code
// ```cpp []
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        //Recursive way
        if(root==nullptr || root->val==val){
            return root;
        }

        if(root->val < val) return searchBST(root->right, val);

        return searchBST(root->left, val);

        //Iterative way
        //while(root!=nullptr){
        //    if(root->val == val){
        //        return root;
        //    }
        //    else if(root->val < val){
        //        root = root->right;
        //    }
        //    else{
        //        return root;
        //    }
        //}
        //return nullptr;
    }
};
```
