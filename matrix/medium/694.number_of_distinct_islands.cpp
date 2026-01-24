/*
Problem Number: 694. Number of Distinct Islands
Difficulty Level: Medium
Link: https://leetcode.com/problems/number-of-distinct-islands

********************************************************************************


Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's
(representing land) connected 4-directionally (horizontal or vertical.) You may
assume all four edges of the grid are surrounded by water. Count the number of
distinct islands. An island is considered to be the same as another if and only
if one island can be translated (and not rotated or reflected) to equal the
other.


Example 1:
Input: matrix = [
[11000],
[11000],
[00011],
[00011]
]
Output: 1

Example 2:
Input: matrix = [
[11011],
[10000],
[00001],
[11011]
]
Output: 3

Constraints:
m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
*/

#include <algorithm>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// Solution 1: Ordered set
class Solution {
  public:
    int numDistinctIslands(vector<vector<int>> &grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j);
                }
            }
        }
        return uniqueIslands.size();
    }

  private:
    set<vector<pair<int, int>>> uniqueIslands;
    void dfs(vector<vector<int>> &grid, int i, int j) {
        stack<pair<int, int>> myStack;
        myStack.push({i, j});
        grid[i][j] = 0;

        vector<pair<int, int>> shape;
        shape.push_back({0, 0});
        static const vector<pair<int, int>> directions = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!myStack.empty()) {
            auto [row, col] = myStack.top();
            myStack.pop();

            for (auto [dr, dc] : directions) {
                int r = row + dr;
                int c = col + dc;

                if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() &&
                    grid[r][c] == 1) {
                    myStack.push({r, c});
                    grid[r][c] = 0;
                    shape.push_back({r - i, c - j});
                }
            }
        }
        uniqueIslands.insert(shape);
    }
};

// m = row size of matrix, n = column size of matrix
// Time Complexity: O(m * n * log(n * m))
// Space Complexity: O(m * n)

// Solution 2: Unordered set with string conversion
class Solution {
  public:
    int numDistinctIslands(vector<vector<int>> &grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j);
                }
            }
        }
        return uniqueIslands.size();
    }

  private:
    unordered_set<string> uniqueIslands;
    void dfs(vector<vector<int>> &grid, int i, int j) {
        stack<pair<int, int>> myStack;
        myStack.push({i, j});
        grid[i][j] = 0;

        string shape = "0,0;";
        static const vector<pair<int, int>> directions = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!myStack.empty()) {
            auto [row, col] = myStack.top();
            myStack.pop();

            for (auto [dr, dc] : directions) {
                int r = row + dr;
                int c = col + dc;

                if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() &&
                    grid[r][c] == 1) {
                    myStack.push({r, c});
                    grid[r][c] = 0;
                    shape += to_string(r - i) + "," + to_string(c - j) + ";";
                }
            }
        }
        uniqueIslands.insert(shape);
    }
};

// m = row size of matrix, n = column size of matrix
// Time Complexity: O(m * n )
// Space Complexity: O(m * n)
