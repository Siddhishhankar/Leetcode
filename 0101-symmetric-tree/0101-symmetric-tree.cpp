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
    bool isSymmetric(TreeNode* root) {
        // If the tree is empty, it is symmetric
        if (root == nullptr) {
            return true;
        }

        // Initialize a queue to hold pairs of nodes
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);

        while (!q.empty()) {
            // Get the next pair of nodes from the queue
            TreeNode* t1 = q.front();
            q.pop();
            TreeNode* t2 = q.front();
            q.pop();

            // If both nodes are null, continue to the next pair
            if (t1 == nullptr && t2 == nullptr) {
                continue;
            }

            // If only one of the nodes is null, the tree is not symmetric
            if (t1 == nullptr || t2 == nullptr) {
                return false;
            }

            // If the values of the nodes are different, the tree is not symmetric
            if (t1->val != t2->val) {
                return false;
            }

            // Push the children of the nodes into the queue in a mirrored fashion
            q.push(t1->left);
            q.push(t2->right);
            q.push(t1->right);
            q.push(t2->left);
        }

        // If we have processed all pairs and found no mismatches, the tree is symmetric
        return true;
    }
};


































// class Solution {
// public:
//     // Main function to check if the tree is symmetric
//     bool isSymmetric(TreeNode* root) {
//         // An empty tree is symmetric
//         if (root == nullptr) {
//             return true;
//         }
//         // Use a helper function to compare the left and right subtrees
//         return isMirror(root->left, root->right);
//     }
    
// private:
//     // Helper function to check if two trees are mirrors of each other
//     bool isMirror(TreeNode* t1, TreeNode* t2) {
//         // If both nodes are null, they are mirrors
//         if (t1 == nullptr && t2 == nullptr) {
//             return true;
//         }
//         // If only one of the nodes is null, they are not mirrors
//         if (t1 == nullptr || t2 == nullptr) {
//             return false;
//         }
//         // The current nodes must have the same value
//         // And the left subtree of t1 must be a mirror of the right subtree of t2
//         // And the right subtree of t1 must be a mirror of the left subtree of t2
//         return (t1->val == t2->val) && 
//                isMirror(t1->right, t2->left) && 
//                isMirror(t1->left, t2->right);
//     }
// };