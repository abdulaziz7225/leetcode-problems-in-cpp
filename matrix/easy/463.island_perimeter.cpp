/*
Problem Number: 463. Island Perimeter
Difficulty Level: Easy
Link: https://leetcode.com/problems/island-perimeter/

********************************************************************************

You are given row x col grid representing a map where grid[i][j] = 1
represents land and grid[i][j] = 0 represents water. Grid cells are connected
horizontally/vertically (not diagonally). The grid is completely surrounded by
water, and there is exactly one island (i.e., one or more connected land cells).
The island doesn't have "lakes", meaning the water inside isn't connected to the
water around the island. One cell is a square with side length 1. The grid is
rectangular, width and height don't exceed 100. Determine the perimeter of the
island.

Example 1:
Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
Output: 16
Explanation: The perimeter is the 16 yellow stripes in the image above.

Example 2:
Input: grid = [[1]]
Output: 4

Example 3:
Input: grid = [[1,0]]
Output: 4

Constraints:
row == grid.length
col == grid[i].length
1 <= row, col <= 100
grid[i][j] is 0 or 1.
There is exactly one island in grid.
*/

#include <vector>

using namespace std;

// Solution 1: Recursive Depth-First Search with in-place modification
class Solution {
  public:
    int islandPerimeter(vector<vector<int>> &grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j);
                    return perimeter;
                }
            }
        }
        return perimeter;
    }

  private:
    int perimeter = 0;
    void dfs(vector<vector<int>> &grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
            grid[i][j] == 0) {
            perimeter += 1;
            return;
        }
        if (grid[i][j] == -1) {
            return;
        }

        grid[i][j] = -1;

        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
    }
};

// n = len(rows), m = len(cols)
// Time Complexity: O(n * m)
// Space Complexity: O(n * m)

// Solution 2: Optimized Approach
class Solution {
  public:
    int islandPerimeter(vector<vector<int>> &grid) {
        int perimeter = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    perimeter += 4;

                    if (i > 0 && grid[i - 1][j] == 1) {
                        perimeter -= 2;
                    }
                    if (j > 0 && grid[i][j - 1] == 1) {
                        perimeter -= 2;
                    }
                }
            }
        }
        return perimeter;
    }
};

// n = len(rows), m = len(cols)
// Time Complexity: O(n * m)
// Space Complexity: O(1)
