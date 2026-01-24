/*
Problem Number: 1559. Detect Cycles in 2D Grid
Difficulty Level: Medium
Link: https://leetcode.com/problems/detect-cycles-in-2d-grid/

********************************************************************************

Given a 2D array of characters grid of size m x n, you need to find if there
exists any cycle consisting of the same value in grid. A cycle is a path of
length 4 or more in the grid that starts and ends at the same cell. From a given
cell, you can move to one of the cells adjacent to it - in one of the four
directions (up, down, left, or right), if it has the same value of the current
cell. Also, you cannot move to the cell that you visited in your last move. For
example, the cycle (1, 1) -> (1, 2) -> (1, 1) is invalid because from (1, 2) we
visited (1, 1) which was the last visited cell. Return true if any cycle of the
same value exists in grid, otherwise, return false.

Example 1:
Input: grid =
[["a","a","a","a"],["a","b","b","a"],["a","b","b","a"],["a","a","a","a"]]
Output: true
Explanation: There are two valid cycles shown in different colors in the image
below:

Example 2:
Input: grid =
[["c","c","c","a"],["c","d","c","c"],["c","c","e","c"],["f","c","c","c"]]
Output: true
Explanation: There is only one valid cycle highlighted in the image below:

Example 3:
Input: grid = [["a","b","b"],["b","z","b"],["b","b","a"]]
Output: false

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 500
grid consists only of lowercase English letters.
*/

#include <stack>
#include <vector>

using namespace std;

struct Node {
    int row;
    int col;
    int parent_row;
    int parent_col;
};

class Solution {
  public:
    bool containsCycle(vector<vector<char>> &grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        visited.assign(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (!visited[i][j]) {
                    if (dfs(grid, i, j)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

  private:
    vector<vector<bool>> visited;
    bool dfs(vector<vector<char>> &grid, int i, int j) {
        stack<Node> myStack;
        myStack.push({i, j, -1, -1});
        visited[i][j] = true;

        static const vector<pair<int, int>> directions = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!myStack.empty()) {
            Node curr = myStack.top();
            myStack.pop();

            for (auto [dr, dc] : directions) {
                int nr = curr.row + dr;
                int nc = curr.col + dc;

                if (nr >= 0 && nr < grid.size() && nc >= 0 &&
                    nc < grid[0].size() &&
                    grid[nr][nc] == grid[curr.row][curr.col]) {
                    if (nr == curr.parent_row && nc == curr.parent_col) {
                        continue;
                    }
                    if (visited[nr][nc] == true) {
                        return true;
                    }

                    myStack.push({nr, nc, curr.row, curr.col});
                    visited[nr][nc] = true;
                }
            }
        }
        return false;
    }
};

// n = row size of matrix, m = column size of matrix
// Time Complexity: O(2 * n * m) ==> O(n * m)
// Space Complexity: O(n * m)