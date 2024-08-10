#include <vector>
#include <iostream>

class Solution {
public:
    // DFS to mark the visited parts of the grid
    void dfs(std::vector<std::vector<int>>& grid, int i, int j) {
        int n = grid.size();
        // Check bounds and if the current cell is already visited
        if (i < 0 || j < 0 || i >= n || j >= n || grid[i][j] == 1)
            return;

        // Mark the current cell as visited
        grid[i][j] = 1;

        // Visit all 4 neighboring cells
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }

    int regionsBySlashes(std::vector<std::string>& grid) {
        int n = grid.size();
        // Create a new grid that is 3 times larger to represent sub-regions
        std::vector<std::vector<int>> expandedGrid(n * 3, std::vector<int>(n * 3, 0));

        // Fill the expanded grid based on slashes
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '/') {
                    expandedGrid[i * 3][j * 3 + 2] = 1;
                    expandedGrid[i * 3 + 1][j * 3 + 1] = 1;
                    expandedGrid[i * 3 + 2][j * 3] = 1;
                } else if (grid[i][j] == '\\') {
                    expandedGrid[i * 3][j * 3] = 1;
                    expandedGrid[i * 3 + 1][j * 3 + 1] = 1;
                    expandedGrid[i * 3 + 2][j * 3 + 2] = 1;
                }
            }
        }

        int regions = 0;
        // Count the regions using DFS
        for (int i = 0; i < n * 3; ++i) {
            for (int j = 0; j < n * 3; ++j) {
                if (expandedGrid[i][j] == 0) {
                    dfs(expandedGrid, i, j);
                    regions++;
                }
            }
        }

        return regions;
    }
};
