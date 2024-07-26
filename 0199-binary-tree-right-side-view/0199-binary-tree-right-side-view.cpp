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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result; // This will store the right side view of the tree
        if (root == nullptr) { // If the tree is empty, return an empty result
            return result;
        }

        queue<TreeNode*> q; // Queue to help with level-order traversal
        q.push(root); // Start with the root node
        
        // While there are nodes to process
        while (!q.empty()) {
            int levelsize = q.size(); // Number of nodes at the current level
            // Traverse all nodes in the current level
            for (int i = 0; i < levelsize; ++i) {
                TreeNode* node = q.front(); // Get the front node in the queue
                q.pop(); // Remove the node from the queue
                
                // If it's the last node in this level, add it to the result
                if (i == levelsize - 1) {
                    result.push_back(node->val);
                }

                // Add the left child to the queue if it exists
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                // Add the right child to the queue if it exists
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
        }
        return result; // Return the collected right side view
   
    }
};