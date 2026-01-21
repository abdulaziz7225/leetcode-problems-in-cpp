/*
Problem Number: 200. Number of Islands
Difficulty Level: Medium
Link: https://leetcode.com/problems/number-of-islands

********************************************************************************

Given an m x n 2D binary grid grid which represents a map of '1's (land) and
'0's (water), return the number of islands. An island is surrounded by water and
is formed by connecting adjacent lands horizontally or vertically. You may
assume all four edges of the grid are all surrounded by water.

Example 1:
Input: grid = [
["1","1","1","1","0"],
["1","1","0","1","0"],
["1","1","0","0","0"],
["0","0","0","0","0"]
]
Output: 1

Example 2:
Input: grid = [
["1","1","0","0","0"],
["1","1","0","0","0"],
["0","0","1","0","0"],
["0","0","0","1","1"]
]
Output: 3

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.
*/

#include <queue>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// Solution 1: Recursive Depth-First Search with in-place modification
class Solution {
  public:
    int numIslands(vector<vector<char>> &grid) {
        int numberOfIslands = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    numberOfIslands++;
                    dfs(grid, i, j);
                }
            }
        }

        return numberOfIslands;
    }

  private:
    void dfs(vector<vector<char>> &grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
            return;
        }

        if (grid[i][j] == '0') {
            return;
        }

        grid[i][j] = '0';

        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
    }
};

// n = len(rows), m = len(cols)
// Time Complexity: O(2 * n * m) ==> O(n * m)
// Space Complexity: O(n * m)

// Solution 2: Iterative Depth-First Search with set data structure
class Solution {
  public:
    int numIslands(vector<vector<char>> &grid) {
        int numberOfIslands = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1' &&
                    !visited.count(to_string(i) + "," + to_string(j))) {
                    numberOfIslands++;
                    dfs(grid, i, j);
                }
            }
        }
        return numberOfIslands;
    }

  private:
    unordered_set<string> visited;

    void dfs(vector<vector<char>> &grid, int i, int j) {
        stack<pair<int, int>> stack;
        visited.insert(to_string(i) + "," + to_string(j));
        stack.push({i, j});

        while (!stack.empty()) {
            auto [row, col] = stack.top();
            stack.pop();
            vector<pair<int, int>> directions = {
                {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

            for (auto [dr, dc] : directions) {
                int r = row + dr;
                int c = col + dc;
                if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() &&
                    grid[r][c] == '1' &&
                    !visited.count(to_string(r) + "," + to_string(c))) {
                    stack.push({r, c});
                    visited.insert(to_string(r) + "," + to_string(c));
                }
            }
        }
    }
};

// n = len(rows), m = len(cols)
// Time Complexity: O(2 * n * m) ==> O(n * m)
// Space Complexity: O(n * m)

// Solution 3: Iterative Depth-First Search with in-place modification
class Solution {
  public:
    int numIslands(vector<vector<char>> &grid) {
        int numberOfIslands = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    numberOfIslands++;
                    dfs(grid, i, j);
                }
            }
        }
        return numberOfIslands;
    }

  private:
    void dfs(vector<vector<char>> &grid, int i, int j) {
        stack<pair<int, int>> stack;
        grid[i][j] = '0';
        stack.push({i, j});

        while (!stack.empty()) {
            auto [row, col] = stack.top();
            stack.pop();
            vector<pair<int, int>> directions = {
                {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

            for (auto [dr, dc] : directions) {
                int r = row + dr;
                int c = col + dc;

                if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() &&
                    grid[r][c] == '1') {
                    stack.push({r, c});
                    grid[r][c] = '0';
                }
            }
        }
    }
};

// n = len(rows), m = len(cols)
// Time Complexity: O(2 * n * m) ==> O(n * m)
// Space Complexity: O(n * m)

// Solution 4: Iterative Breadth-First Search with set data structure
class Solution {
  public:
    int numIslands(vector<vector<char>> &grid) {
        int numberOfIslands = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1' &&
                    !visited.count(to_string(i) + "," + to_string(j))) {
                    numberOfIslands++;
                    bfs(grid, i, j);
                }
            }
        }
        return numberOfIslands;
    }

  private:
    unordered_set<string> visited;

    void bfs(vector<vector<char>> &grid, int i, int j) {
        queue<pair<int, int>> queue;
        visited.insert(to_string(i) + "," + to_string(j));
        queue.push({i, j});

        while (!queue.empty()) {
            auto [row, col] = queue.front();
            queue.pop();
            vector<pair<int, int>> directions = {
                {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

            for (auto [dr, dc] : directions) {
                int r = row + dr;
                int c = col + dc;
                if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() &&
                    grid[r][c] == '1' &&
                    !visited.count(to_string(r) + "," + to_string(c))) {
                    queue.push({r, c});
                    visited.insert(to_string(r) + "," + to_string(c));
                }
            }
        }
    }
};

// n = len(rows), m = len(cols)
// Time Complexity: O(2 * n * m) ==> O(n * m)
// Space Complexity: O(n * m)

// Solution 5: Iterative Breadth-First Search with in-place modification
class Solution {
  public:
    int numIslands(vector<vector<char>> &grid) {
        int numberOfIslands = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    numberOfIslands++;
                    bfs(grid, i, j);
                }
            }
        }
        return numberOfIslands;
    }

  private:
    void bfs(vector<vector<char>> &grid, int i, int j) {
        queue<pair<int, int>> queue;
        grid[i][j] = '0';
        queue.push({i, j});

        while (!queue.empty()) {
            auto [row, col] = queue.front();
            queue.pop();
            vector<pair<int, int>> directions = {
                {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

            for (auto [dr, dc] : directions) {
                int r = row + dr;
                int c = col + dc;
                if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() &&
                    grid[r][c] == '1') {
                    queue.push({r, c});
                    grid[r][c] = '0';
                }
            }
        }
    }
};

// n = len(rows), m = len(cols)
// Time Complexity: O(2 * n * m) ==> O(n * m)
// Space Complexity: O(n * m)
