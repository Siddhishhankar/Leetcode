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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;  // Initialize the diameter to zero
        // Call the main function that also keeps track of the diameter
        heightAndDiameter(root, diameter);
        return diameter;
    }

private:
    // This function calculates the height of the tree and updates the diameter
    int heightAndDiameter(TreeNode* node, int& diameter) {
        if (node == nullptr) {
            return 0;  // If the node is null, its height is 0
        }

        // Recursively calculate the height of the left subtree
        int leftHeight = heightAndDiameter(node->left, diameter);
        // Recursively calculate the height of the right subtree
        int rightHeight = heightAndDiameter(node->right, diameter);

        // Update the diameter at this node. The diameter is the maximum value
        // between the current diameter and the sum of the heights of the left
        // and right subtrees.
        diameter = max(diameter, leftHeight + rightHeight);

        // Return the height of the node. The height is the maximum height of
        // its subtrees plus one for the current node.
        return max(leftHeight, rightHeight) + 1;
    }
};