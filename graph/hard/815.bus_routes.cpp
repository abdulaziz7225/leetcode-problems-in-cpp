/*
Problem Number: 815. Bus Routes
Difficulty Level: Hard
Link: https://leetcode.com/problems/bus-routes

********************************************************************************

You are given an array routes representing bus routes where routes[i] is a bus
route that the ith bus repeats forever. For example, if routes[0] = [1, 5, 7],
this means that the 0th bus travels in the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7
-> 1 -> ... forever. You will start at the bus stop source (You are not on any
bus initially), and you want to go to the bus stop target. You can travel
between bus stops by buses only. Return the least number of buses you must take
to travel from source to target. Return -1 if it is not possible.

Example 1:
Input: routes = [[1,2,7],[3,6,7]], source = 1, target = 6
Output: 2
Explanation: The best strategy is take the first bus to the bus stop 7, then
take the second bus to the bus stop 6.

Example 2:
Input: routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target =
12 Output: -1

Constraints:
1 <= routes.length <= 500.
1 <= routes[i].length <= 10^5
All the values of routes[i] are unique.
sum(routes[i].length) <= 10^5
0 <= routes[i][j] < 10^6
0 <= source, target < 10^6
*/

#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
  public:
    int numBusesToDestination(vector<vector<int>> &routes, int source,
                              int target) {
        if (source == target) {
            return 0;
        }

        unordered_map<int, vector<int>> stopToBuses;
        for (int busID = 0; busID < routes.size(); busID++) {
            for (auto stop : routes[busID]) {
                stopToBuses[stop].push_back(busID);
            }
        }

        return bfs(routes, stopToBuses, source, target);
    }

  private:
    int bfs(vector<vector<int>> &routes,
            unordered_map<int, vector<int>> &stopToBuses, int source,
            int target) {
        queue<int> queue;

        unordered_set<int> takenBuses;
        unordered_set<int> visitedStops;
        visitedStops.insert(source);

        for (auto busID : stopToBuses[source]) {
            queue.push(busID);
            takenBuses.insert(busID);
        }

        int busCount = 1;

        while (!queue.empty()) {
            int levelSize = queue.size();
            for (int i = 0; i < levelSize; i++) {
                int busID = queue.front();
                queue.pop();

                for (auto currBusStop : routes[busID]) {
                    if (currBusStop == target) {
                        return busCount;
                    }

                    if (visitedStops.count(currBusStop)) {
                        continue;
                    }

                    visitedStops.insert(currBusStop);

                    for (auto nextBusID : stopToBuses[currBusStop]) {
                        if (!takenBuses.count(nextBusID)) {
                            queue.push(nextBusID);
                            takenBuses.insert(nextBusID);
                        }
                    }
                }
            }
            busCount++;
        }

        return -1;
    }
};

// n = total number of bus stops across all routes
// m = total number of unique bus stops in the graph
// b = total number of buses
// Time Complexity: O(n + m)
// Space Complexity: O(n)