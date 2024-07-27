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
// class Solution {
// public:
//     int countNodes(TreeNode* root) 
//     {
//         if(root == nullptr) return 0;

//         return 1 + countNodes(root->left) +countNodes(root ->right);
//     }
// };

class Solution {
public:
    int countNodes(TreeNode* root) {
        // Base case: if the tree is empty, return 0
        if (root == nullptr) {
            return 0;
        }

        TreeNode* left = root;
        TreeNode* right = root;
        int heightL = 0;
        int heightR = 0;

        // Calculate the height of the leftmost path
        while (left != nullptr) {
            ++heightL;
            left = left->left;
        }

        // Calculate the height of the rightmost path
        while (right != nullptr) {
            ++heightR;
            right = right->right;
        }

        // If the heights of the leftmost and rightmost paths are equal, the tree is complete and full
        if (heightL == heightR) {
            // The number of nodes in a complete binary tree is 2^height - 1
            return pow(2, heightL) - 1;
        }

        // If the tree is not complete and full, recursively count the nodes in the left and right subtrees
        // and add 1 for the root node
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};