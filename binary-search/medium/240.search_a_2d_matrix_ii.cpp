/*
Problem Number: 240. Search a 2D Matrix II
Difficulty Level: Medium
Link: https://leetcode.com/problems/search-a-2d-matrix-ii/

********************************************************************************

Write an efficient algorithm that searches for a value target in an m x n
integer matrix matrix. This matrix has the following properties: Integers in
each row are sorted in ascending from left to right. Integers in each column are
sorted in ascending from top to bottom.

Example 1:
Input: matrix =
[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]],
target = 5 Output: true

Example 2:
Input: matrix =
[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]],
target = 20 Output: false

Constraints:
m == matrix.length
n == matrix[i].length
1 <= n, m <= 300
-10^9 <= matrix[i][j] <= 10^9
All the integers in each row are sorted in ascending order.
All the integers in each column are sorted in ascending order.
-10^9 <= target <= 10^9
*/

#include <vector>

using namespace std;

// Solution 1: Binary Search
class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        for (int rowID = 0; rowID < n; rowID++) {
            int left = 0;
            int right = m - 1;
            int middle;

            while (left <= right) {
                middle = left + (right - left) / 2;

                if (matrix[rowID][middle] == target) {
                    return true;
                } else if (matrix[rowID][middle] < target) {
                    left = middle + 1;
                } else {
                    right = middle - 1;
                }
            }
        }
        return false;
    }
};

// n = lens(rows), m = len(columns)
// Time Complexity: O(n * log(m))
// Space Complexity: O(1)

// Solution 2: Efficient Traversal
class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int rowID = n - 1;
        int colID = 0;

        while (rowID >= 0 && colID < m) {
            if (matrix[rowID][colID] == target) {
                return true;
            } else if (matrix[rowID][colID] < target) {
                colID++;
            } else {
                rowID--;
            }
        }
        return false;
    }
};

// n = lens(rows), m = len(columns)
// Time Complexity: O(n + m)
// Space Complexity: O(1)
