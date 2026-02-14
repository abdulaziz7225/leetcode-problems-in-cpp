/*
Problem Number: 1167. Minimum Cost to Connect Sticks
Difficulty Level: Medium
Link: https://leetcode.com/problems/minimum-cost-to-connect-sticks/

********************************************************************************

You have some sticks with positive integer lengths. You can connect any two
sticks of lengths X and Y into one stick by paying a cost of X + Y.  You perform
this action until there is one stick remaining. Return the minimum cost of
connecting all the given sticks into one stick in this way.


Example 1:
Input: sticks = [2,4,3]
Output: 14

Example 2:
Input: sticks = [1,8,3,5]
Output: 30

Constraints:
1 <= sticks.length <= 10^4
1 <= sticks[i] <= 10^4
*/

#include <queue>
#include <vector>

using namespace std;

class Solution {
  public:
    int connectSticks(vector<int> &sticks) {
        priority_queue<int, vector<int>, greater<int>> minHeap(sticks.begin(),
                                                               sticks.end());
        int totalCost = 0;

        while (minHeap.size() > 1) {
            int first = minHeap.top();
            minHeap.pop();
            int second = minHeap.top();
            minHeap.pop();

            int combinedCost = first + second;
            totalCost += combinedCost;

            minHeap.push(combinedCost);
        }
        return totalCost;
    }
};

// Time Complexity: O(n + 2 * n * log(n)) ==> O(n * log(n))
// Space Complexity: O(1)
