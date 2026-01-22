/*
Problem Number: 1254. Number of Closed Islands
Difficulty Level: Medium
Link: https://leetcode.com/problems/number-of-closed-islands/

********************************************************************************

Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal
4-directionally connected group of 0s and a closed island is an island
totally (all left, top, right, bottom) surrounded by 1s. Return the number of
closed islands.

Example 1:
Input: grid = [
[1,1,1,1,1,1,1,0],
[1,0,0,0,0,1,1,0],
[1,0,1,0,1,1,1,0],
[1,0,0,0,0,1,0,1],
[1,1,1,1,1,1,1,0]
]
Output: 2
Explanation:
Islands in gray are closed because they are completely surrounded by water
(group of 1s).

Example 2:
Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
Output: 1

Example 3:
Input: grid = [
[1,1,1,1,1,1,1],
[1,0,0,0,0,0,1],
[1,0,1,1,1,0,1],
[1,0,1,0,1,0,1],
[1,0,1,1,1,0,1],
[1,0,0,0,0,0,1],
[1,1,1,1,1,1,1]
]
Output: 2

Constraints:
1 <= grid.length, grid[0].length <= 100
0 <= grid[i][j] <=1
*/

#include <stack>
#include <vector>

using namespace std;

class Solution {
  public:
    int closedIsland(vector<vector<int>> &grid) {
        int closedIslands = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    closedIslands += dfs(grid, i, j);
                }
            }
        }
        return closedIslands;
    }

  private:
    bool dfs(vector<vector<int>> &grid, int i, int j) {
        bool isClosed = true;
        stack<pair<int, int>> stack;
        stack.push({i, j});
        grid[i][j] = 1;

        while (!stack.empty()) {
            auto [row, col] = stack.top();
            stack.pop();

            if (row == 0 || row == grid.size() - 1 || col == 0 ||
                col == grid[0].size() - 1) {
                isClosed = false;
            }

            vector<pair<int, int>> directions = {
                {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

            for (auto [dr, dc] : directions) {
                int r = row + dr;
                int c = col + dc;
                if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() &&
                    grid[r][c] == 0) {
                    grid[r][c] = 1;
                    stack.push({r, c});
                }
            }
        }

        return isClosed;
    }
};