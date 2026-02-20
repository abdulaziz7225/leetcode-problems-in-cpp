/*
Problem Number: 621. Task Scheduler
Difficulty Level: Medium
Link: https://leetcode.com/problems/task-scheduler/

********************************************************************************

You are given an array of CPU tasks, each labeled with a letter from A to Z, and
a number n. Each CPU interval can be idle or allow the completion of one task.
Tasks can be completed in any order, but there's a constraint: there has to be a
gap of at least n intervals between two tasks with the same label. Return the
minimum number of CPU intervals required to complete all tasks.

Example 1:
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.
After completing task A, you must wait two intervals before doing A again. The
same applies to task B. In the 3rd interval, neither A nor B can be done, so you
idle. By the 4th interval, you can do A again as 2 intervals have passed.

Example 2:
Input: tasks = ["A","C","A","B","D","B"], n = 1
Output: 6
Explanation: A possible sequence is: A -> B -> C -> D -> A -> B.
With a cooling interval of 1, you can repeat a task after just one other task.

Example 3:
Input: tasks = ["A","A","A", "B","B","B"], n = 3
Output: 10
Explanation: A possible sequence is: A -> B -> idle -> idle -> A -> B -> idle ->
idle -> A -> B. There are only two types of tasks, A and B, which need to be
separated by 3 intervals. This leads to idling twice between repetitions of
these tasks.

Constraints:
1 <= tasks.length <= 10^4
tasks[i] is an uppercase English letter.
0 <= n <= 100
*/

#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    int leastInterval(vector<char> &tasks, int n) {
        unordered_map<char, int> count;
        for (char task : tasks) {
            count[task]++;
        }

        priority_queue<int> maxHeap;
        for (auto [_, freq] : count) {
            maxHeap.push(freq);
        }

        int time = 0;
        // queue stores pairs of {remaining_frequency, available_time}
        queue<pair<int, int>> cooldownQueue;

        while (!maxHeap.empty() || !cooldownQueue.empty()) {
            time++;

            if (!maxHeap.empty()) {
                int freq = maxHeap.top() - 1;
                maxHeap.pop();

                if (freq > 0) {
                    cooldownQueue.push({freq, time + n});
                }
            }

            if (!cooldownQueue.empty() &&
                cooldownQueue.front().second == time) {
                maxHeap.push(cooldownQueue.front().first);
                cooldownQueue.pop();
            }
        }
        return time;
    }
};

// m = len(tasks), k = number of unique characters
// Time Complexity: O(m + n * m) ==> O(n * m)
// Space Complexity: O(3 * k) ==> O(k)