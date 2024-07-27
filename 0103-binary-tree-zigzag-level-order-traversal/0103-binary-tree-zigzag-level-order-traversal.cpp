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
        // Initialize the result vector which will store the final zigzag level order traversal
        vector<vector<int>> result;

        // If the tree is empty, return the empty result
        if (root == nullptr) {
            return result;
        }

        // Queue to perform level order traversal
        queue<TreeNode*> q;
        // Start with the root node
        q.push(root);
        // Boolean flag to track the direction of traversal
        bool leftToRight = true;

        // Continue processing nodes until the queue is empty
        while (!q.empty()) {
            // Get the number of nodes at the current level
            int size = q.size();
            // Deque to store the current level's nodes in zigzag order
            deque<int> ans;

            // Process all nodes at the current level
            for (int i = 0; i < size; ++i) {
                // Get the front node from the queue
                TreeNode* frontNode = q.front();
                q.pop();

                // Add the node's value to the deque
                // If leftToRight is true, add to the back, otherwise add to the front
                if (leftToRight) {
                    ans.push_back(frontNode->val);
                } else {
                    ans.push_front(frontNode->val);
                }

                // Add the left child to the queue if it exists
                if (frontNode->left) {
                    q.push(frontNode->left);
                }

                // Add the right child to the queue if it exists
                if (frontNode->right) {
                    q.push(frontNode->right);
                }
            }

            // Convert the deque to a vector and add to the result
            result.push_back(vector<int>(ans.begin(), ans.end()));

            // Toggle the direction for the next level
            leftToRight = !leftToRight;
        }

        // Return the final result
        return result;
    }
};

/*
vector<vector<int>> result: Stores the final zigzag order traversal.
If the root is nullptr, return the empty result vector.
Use a queue to perform level-order traversal and initialize it with the root node.
Initialize a boolean flag leftToRight to true to keep track of the direction of traversal (starts with left-to-right).
While the queue is not empty:
Get the number of nodes at the current level.
Initialize an empty deque ans to store the values of the current level.
For            }
             result.push_back(vector<int>(ans.begin(), ans.end()));
            leftToRight = !leftToRight;
        } each node at the current level:
Pop the node from the queue.
If leftToRight is true, add the node's value to the back of the deque.
If leftToRight is false, add the node's value to the front of the deque.
Add the left and right children of the node to the queue if they exist.
Convert the deque to a vector and add it to the result.
Toggle the leftToRight flag for the next level.
Return the result vector containing the zigzag level order traversal.
*/