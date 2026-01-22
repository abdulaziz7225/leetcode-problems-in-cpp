/*
Problem Number: 733. Flood Fill
Difficulty Level: Easy
Link: https://leetcode.com/problems/flood-fill/

********************************************************************************

You are given an image represented by an m x n grid of integers image, where
image[i][j] represents the pixel value of the image. You are also given three
integers sr, sc, and color. Your task is to perform a flood fill on the image
starting from the pixel image[sr][sc]. To perform a flood fill: Begin with the
starting pixel and change its color to color. Perform the same process for each
pixel that is directly adjacent (pixels that share a side with the original
pixel, either horizontally or vertically) and shares the same color as the
starting pixel. Keep repeating this process by checking neighboring pixels of
the updated pixels and modifying their color if it matches the original color of
the starting pixel. The process stops when there are no more adjacent pixels of
the original color to update. Return the modified image after performing the
flood fill.

Example 1:
Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation:
From the center of the image with position (sr, sc) = (1, 1) (i.e., the red
pixel), all pixels connected by a path of the same color as the starting pixel
(i.e., the blue pixels) are colored with the new color. Note the bottom corner
is not colored 2, because it is not horizontally or vertically connected to the
starting pixel.

Example 2:
Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
Output: [[0,0,0],[0,0,0]]
Explanation:
The starting pixel is already colored with 0, which is the same as the target
color. Therefore, no changes are made to the image.

Constraints:
m == image.length
n == image[i].length
1 <= m, n <= 50
0 <= image[i][j], color < 216
0 <= sr < m
0 <= sc < n
*/

#include <stack>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                  int color) {
        int initialColor = image[sr][sc];
        if (initialColor == color) {
            return image;
        }

        stack<pair<int, int>> stack;
        stack.push({sr, sc});
        image[sr][sc] = color;

        while (!stack.empty()) {
            auto [row, col] = stack.top();
            stack.pop();
            vector<pair<int, int>> directions = {
                {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

            for (auto [dr, dc] : directions) {
                int r = row + dr;
                int c = col + dc;
                if (r >= 0 && r < image.size() && c >= 0 &&
                    c < image[0].size() && image[r][c] == initialColor) {
                    image[r][c] = color;
                    stack.push({r, c});
                }
            }
        }
        return image;
    }
};

// n = len(rows), m = len(cols)
// Time Complexity: O(n * m)
// Space Complexity: O(1)
