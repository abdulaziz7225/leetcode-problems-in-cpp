/*
Problem Number: 436. Find Right Interval
Difficulty Level: Medium
Link: https://leetcode.com/problems/find-right-interval

********************************************************************************

You are given an array of intervals, where intervals[i] = [starti, endi] and
each starti is unique. The right interval for an interval i is an interval j
such that startj >= endi and startj is minimized. Note that i may equal j.
Return an array of right interval indices for each interval i. If no right
interval exists for interval i, then put -1 at index i.

Example 1:
Input: intervals = [[1,2]]
Output: [-1]
Explanation: There is only one interval in the collection, so it outputs -1.

Example 2:
Input: intervals = [[3,4],[2,3],[1,2]]
Output: [-1,0,1]
Explanation: There is no right interval for [3,4].
The right interval for [2,3] is [3,4] since start0 = 3 is the smallest start
that is >= end1 = 3. The right interval for [1,2] is [2,3] since start1 = 2 is
the smallest start that is >= end2 = 2.

Example 3:
Input: intervals = [[1,4],[2,3],[3,4]]
Output: [-1,2,-1]
Explanation: There is no right interval for [1,4] and [3,4].
The right interval for [2,3] is [3,4] since start2 = 3 is the smallest start
that is >= end1 = 3.

Constraints:
1 <= intervals.length <= 2 * 10^4
intervals[i].length == 2
-10^6 <= start[i] <= end[i] <= 10^6
The start point of each interval is unique.
*/

#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// Solution 1: Binary Search
class Solution {
  public:
    vector<int> findRightInterval(vector<vector<int>> &intervals) {
        int n = intervals.size();

        for (int i = 0; i < n; i++) {
            starts.push_back({intervals[i][0], i});
        }
        sort(starts.begin(), starts.end());

        for (auto interval : intervals) {
            int rightInterval = customBinarySearch(intervals, interval[1]);

            if (rightInterval < n) {
                result.push_back(starts[rightInterval].second);
            } else {
                result.push_back(-1);
            }
        }
        return result;
    }

  private:
    vector<int> result;
    vector<pair<int, int>> starts;

    int customBinarySearch(vector<vector<int>> &intervals, int end) {
        int left = 0;
        int right = intervals.size();

        while (left < right) {
            int middle = left + (right - left) / 2;

            if (starts[middle].first >= end) {
                right = middle;
            } else {
                left = middle + 1;
            }
        }

        return left;
    }
};

// Time Complexity: O(2 * n * log(n)) ==> O(n * log(n))
// Space Complexity: O(3 * n) ==> O(n)

// Solution 2: Two Heaps Approach
class Solution {
  public:
    vector<int> findRightInterval(vector<vector<int>> &intervals) {
        int n = intervals.size();
        priority_queue<pair<int, int>> maxStart;
        priority_queue<pair<int, int>> maxEnd;

        vector<int> result(n, -1);
        
        for (int i = 0; i < n; i++) {
            maxStart.push({intervals[i][0], i});
            maxEnd.push({intervals[i][1], i});
        }

        for (int i = 0; i < n; i++) {
            auto [end, idx] = maxEnd.top();
            maxEnd.pop();

            if (maxStart.top().first >= end) {
                pair<int, int> bestMatch = maxStart.top();
                maxStart.pop();
                
                while (!maxStart.empty() && maxStart.top().first >= end) {
                    bestMatch = maxStart.top();
                    maxStart.pop();
                }

                result[idx] = bestMatch.second;
                maxStart.push({bestMatch});
            }
        }

        return result;
    }
};

// Time Complexity: O(4 * n * log(n)) ==> O(n * log(n))
// Space Complexity: O(3 * n) ==> O(n)
