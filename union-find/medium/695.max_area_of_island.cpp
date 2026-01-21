/*
Problem Number: 695. Max Area of Island
Difficulty Level: Medium
Link: https://leetcode.com/problems/max-area-of-island

********************************************************************************

You are given an m x n binary matrix grid. An island is a group of 1's
(representing land) connected 4-directionally (horizontal or vertical.) You may
assume all four edges of the grid are surrounded by water. The area of an island
is the number of cells with a value 1 in the island. Return the maximum area of
an island in grid. If there is no island, return 0.

Example 1:
Input: grid = [
[0,0,1,0,0,0,0,1,0,0,0,0,0],
[0,0,0,0,0,0,0,1,1,1,0,0,0],
[0,1,1,0,1,0,0,0,0,0,0,0,0],
[0,1,0,0,1,1,0,0,1,0,1,0,0],
[0,1,0,0,1,1,0,0,1,1,1,0,0],
[0,0,0,0,0,0,0,0,0,0,1,0,0],
[0,0,0,0,0,0,0,1,1,1,0,0,0],
[0,0,0,0,0,0,0,1,1,0,0,0,0]
]
Output: 6
Explanation: The answer is not 11, because the island must be connected
4-directionally.

Example 2:
Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 50
grid[i][j] is either 0 or 1.
*/

#include <queue>
#include <stack>
#include <vector>

using namespace std;

// Solution 1: Iterative Depth-First Search with in-place modification
class Solution {
  public:
    int maxAreaOfIsland(vector<vector<int>> &grid) {
        int maxArea = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    int currArea = dfs(grid, i, j);
                    maxArea = max(maxArea, currArea);
                }
            }
        }
        return maxArea;
    }

  private:
    int dfs(vector<vector<int>> &grid, int i, int j) {
        int currArea = 1;
        stack<pair<int, int>> stack;
        stack.push({i, j});
        grid[i][j] = 0;

        while (!stack.empty()) {
            auto [row, col] = stack.top();
            stack.pop();
            vector<pair<int, int>> directions = {
                {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

            for (auto [dr, dc] : directions) {
                int r = row + dr;
                int c = col + dc;
                if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() &&
                    grid[r][c] == 1) {
                    currArea++;
                    grid[r][c] = 0;
                    stack.push({r, c});
                }
            }
        }
        return currArea;
    }
};

// n = len(rows), m = len(cols)
// Time Complexity: O(2 * n * m) ==> O(n * m)
// Space Complexity: O(n * m)

// Solution 2: Iterative Breadth-First Search with in-place modification
class Solution {
  public:
    int maxAreaOfIsland(vector<vector<int>> &grid) {
        int maxArea = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    int currArea = bfs(grid, i, j);
                    maxArea = max(maxArea, currArea);
                }
            }
        }
        return maxArea;
    }

  private:
    int bfs(vector<vector<int>> &grid, int i, int j) {
        int currArea = 1;
        queue<pair<int, int>> queue;
        queue.push({i, j});
        grid[i][j] = 0;

        while (!queue.empty()) {
            auto [row, col] = queue.front();
            queue.pop();
            vector<pair<int, int>> directions = {
                {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

            for (auto [dr, dc] : directions) {
                int r = row + dr;
                int c = col + dc;
                if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() &&
                    grid[r][c] == 1) {
                    currArea++;
                    grid[r][c] = 0;
                    queue.push({r, c});
                }
            }
        }
        return currArea;
    }
};

// n = len(rows), m = len(cols)
// Time Complexity: O(2 * n * m) ==> O(n * m)
// Space Complexity: O(n * m)