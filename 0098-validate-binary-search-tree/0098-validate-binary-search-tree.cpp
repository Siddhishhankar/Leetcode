class Solution {
public:
    // Helper function to validate the BST
    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MIN, LONG_MAX);
    }

private:
    // Recursive function to validate the tree
    bool validate(TreeNode* node, long min, long max) {
        // An empty tree is a valid BST
        if (node == nullptr) {
            return true;
        }

        // The current node's value must be within the range defined by min and max
        if (node->val <= min || node->val >= max) {
            return false;
        }

        // Recursively validate the left subtree and right subtree
        // For the left child, the max value it can take is node->val
        // For the right child, the min value it can take is node->val
        return validate(node->left, min, node->val) && validate(node->right, node->val, max);
    }
};