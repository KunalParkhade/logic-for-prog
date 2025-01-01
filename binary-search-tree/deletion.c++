//LeetCode No. 450
// # Intuition
// To delete a node from a Binary Search Tree (BST), we need to maintain the BST properties. The goal is to ensure that the left subtree of any node contains values less than the node, and the right subtree contains values greater. Deletion depends on whether the node is a leaf, has one child, or has two children.
// 1. If the node to delete is a leaf, simply remove it.
// 2. If the node has one child, replace it with its child.
// 3. If the node has two children, find the in-order successor (the smallest node in the right subtree), replace the node's value with the successor's value, and delete the successor recursively.

// # Approach
// 1. Base Case: If the root is `nullptr`, return `nullptr` as the tree is empty.
// 2. Traverse:
//     - If the key is less than the current node's value, move to the left subtree.
//     - If the key is greater, move to the right subtree.
// 3. Match Found:
//     - If the node is found, handle the three cases:
//         1. Leaf Node: Directly delete it.
//         2. One Child: Replace the node with its non-`nullptr` child.
//         3. Two Children:
//             - Find the in-order successor.
//             - Replace the node's value with the successor's value.
//             - Recursively delete the successor.
// 4. Return the modified tree after deletion.

// # Complexity
// - Time complexity:
// The traversal to find the node and the successor takes $$O(h)$$, where $$h$$ is the height of the BST.
//     - Best case (balanced BST): $$O(log n)$$.
//     - Worst case (skewed BST): $$O(n)$$.

// - Space complexity:
// The recursion stack requires $$O(h)$$ space.
//     - Best case (balanced BST): $$O(log n)$$.
//     - Worst case (skewed BST): $$O(n)$$.

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
    TreeNode* inorderSuccessor(TreeNode* curr){
        curr = curr->right;

        while(curr!=nullptr && curr->left!=nullptr){
            curr=curr->left;
        }

        return curr;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr) return nullptr;

        if (key < root->val){
            root->left = deleteNode(root->left, key);
        }
        else if(key > root->val){
            root->right = deleteNode(root->right, key);
        }
        else
        {
            if(root->left == nullptr){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            else if(root->right == nullptr){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            else{
                TreeNode* successor = inorderSuccessor(root);
                root->val=successor->val;
                root->right = deleteNode(root->right, successor->val);
            }
        }
        return root;
    }
};
