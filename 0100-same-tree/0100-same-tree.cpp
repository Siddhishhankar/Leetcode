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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Base case 1: Both nodes are null, which means we've reached the end of both branches simultaneously
        if (p == nullptr && q == nullptr) {
            return true;  // Both trees are empty or we've reached the end of both trees
        }

        // Base case 2: One of the nodes is null and the other is not, meaning the trees are different
        if (p == nullptr && q != nullptr) {
            return false;  // One tree has more nodes than the other
        }
        
        if (p != nullptr && q == nullptr) {
            return false;  // One tree has more nodes than the other
        }

        // Recursively check the left subtree
        bool left = isSameTree(p->left, q->left);
        
        // Recursively check the right subtree
        bool right = isSameTree(p->right, q->right);

        // Check the value of the current nodes
        bool value = p->val == q->val;

        // If both left and right subtrees are identical and the current nodes have the same value
        if (left && right && value) {
            return true;  // The trees are identical up to this node
        } else {
            return false;  // The trees differ at this node
        }
    }
};