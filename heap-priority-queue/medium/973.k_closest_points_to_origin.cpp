/*
Problem Number: 973. K Closest Points to Origin
Difficulty Level: Medium
Link: https://leetcode.com/problems/k-closest-points-to-origin

********************************************************************************

Given an array of points where points[i] = [xi, yi] represents a point on the
X-Y plane and an integer k, return the k closest points to the origin (0, 0).
The distance between two points on the X-Y plane is the Euclidean distance
(i.e., √(x1 - x2)2 + (y1 - y2)2). You may return the answer in any order. The
answer is guaranteed to be unique (except for the order that it is in).

Example 1:
Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest k = 1 points from the origin, so the answer is just
[[-2,2]].

Example 2:
Input: points = [[3,3],[5,-1],[-2,4]], k = 2
Output: [[3,3],[-2,4]]
Explanation: The answer [[-2,4],[3,3]] would also be accepted.

Constraints:
1 <= k <= points.length <= 10^4
-10^4 <= xi, yi <= 10^4
*/

#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>

using namespace std;

// Solution 1: Heap Priority Queue
class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
        priority_queue<pair<int, int>> maxHeap;
        vector<vector<int>> result;

        for (int index = 0; index < points.size(); index++) {
            int x = points[index][0];
            int y = points[index][1];
            int distance = x * x + y * y;

            maxHeap.push({distance, index});
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        while (!maxHeap.empty()) {
            result.push_back(points[maxHeap.top().second]);
            maxHeap.pop();
        }
        return result;
    }
};

// Time Complexity: O(n * log(k) + k * log(k)) ==> O(n * log(k))
// Space Complexity: O(2 * k) ==> O(k)

// Solution 2: Built-in Quickselect Algorithm
class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
        auto closer = [](const vector<int> &a, const vector<int> &b) {
            return (a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]);
        };

        nth_element(points.begin(), points.begin() + k, points.end(), closer);
        vector<vector<int>> result(points.begin(), points.begin() + k);
        return result;
    }
};

// In older implementations, Quickselect could hit O(n^2) if the pivot
// selection was poor. However, modern C++ compilers use Introselect, which
// detects if the partition depth is too deep and switches to a Heap-based
// selection to guarantee a worst-case of O(n * log(n))
// Time Complexity: O(n * log(n))
// Space Complexity: O(k)

// TODO: Solution 3: Custom Quickselect Algorithm