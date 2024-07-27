/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        // If the tree is empty, just return the empty root
        if (!root) return nullptr;

        // Initialize a queue for level-order traversal
        queue<Node*> q;
        // Start with the root node
        q.push(root);

        // Continue processing nodes level by level until the queue is empty
        while (!q.empty()) {
            // Get the number of nodes at the current level
            int size = q.size();

            // Process all nodes at the current level
            for (int i = 0; i < size; ++i) {
                // Get the front node from the queue
                Node* node = q.front();
                q.pop();

                // If this is not the last node of the current level,
                // then set its next pointer to the next node in the queue
                if (i < size - 1) {
                    node->next = q.front();
                } else {
                    // If it's the last node, set its next pointer to NULL
                    node->next = nullptr;
                }

                // Add the left child to the queue if it exists
                if (node->left) {
                    q.push(node->left);
                }

                // Add the right child to the queue if it exists
                if (node->right) {
                    q.push(node->right);
                }
            }
        }

        // Return the root node with next pointers set
        return root;
    }
};