// Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

// Example 1:
// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[20,9],[15,7]]
  
// Example 2:
// Input: root = [1]
// Output: [[1]]
  
// Example 3:
// Input: root = []
// Output: []
 
// Constraints:

// The number of nodes in the tree is in the range [0, 2000].
// -100 <= Node.val <= 100

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);
        bool flag = true; // true indicates left-to-right; false indicates right-to-left

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> level(levelSize); // Pre-allocate space for the current level
            
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();

                // Determine position to insert based on the flag
                int index = flag ? i : (levelSize - 1 - i);
                level[index] = node->val;

                // Push child nodes into the queue
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            result.push_back(level);
            flag = !flag; // Toggle the direction for the next level
        }

        return result;
    }
};
