class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res; // Resultant vector to store the spiral order
        if (matrix.empty()) return res; // Return empty result if the matrix is empty

        int top = 0; // Initializing the top boundary
        int bottom = matrix.size() - 1; // Initializing the bottom boundary
        int left = 0; // Initializing the left boundary
        int right = matrix[0].size() - 1; // Initializing the right boundary

        // Loop until the boundaries overlap
        while (top <= bottom && left <= right) {
            // Traverse from left to right along the top boundary
            for (int i = left; i <= right; ++i) {
                res.push_back(matrix[top][i]);
            }
            ++top; // Move the top boundary down

            // Traverse from top to bottom along the right boundary
            for (int i = top; i <= bottom; ++i) {
                res.push_back(matrix[i][right]);
            }
            --right; // Move the right boundary left

            // Traverse from right to left along the bottom boundary, if within boundaries
            if (top <= bottom) {
                for (int i = right; i >= left; --i) {
                    res.push_back(matrix[bottom][i]);
                }
                --bottom; // Move the bottom boundary up
            }

            // Traverse from bottom to top along the left boundary, if within boundaries
            if (left <= right) {
                for (int i = bottom; i >= top; --i) {
                    res.push_back(matrix[i][left]);
                }
                ++left; // Move the left boundary right
            }
        }

        return res; // Return the spiral order
    }
};
