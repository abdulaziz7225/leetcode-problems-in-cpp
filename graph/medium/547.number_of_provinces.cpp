/*
Problem Number: 547. Number of Provinces
Difficulty Level: Medium
Link: https://leetcode.com/problems/number-of-provinces/editorial/

********************************************************************************

There are n cities. Some of them are connected, while some are not. If city a is
connected directly with city b, and city b is connected directly with city c,
then city a is connected indirectly with city c. A province is a group of
directly or indirectly connected cities and no other cities outside of the
group. You are given an n x n matrix isConnected where isConnected[i][j] = 1 if
the ith city and the jth city are directly connected, and isConnected[i][j] = 0
otherwise. Return the total number of provinces.

Example 1:
Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2

Example 2:
Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3

Constraints:
1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] is 1 or 0.
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]
*/

#include <queue>
#include <stack>
#include <vector>

using namespace std;

// Solution 1: Iterative DFS
class Solution {
  public:
    int findCircleNum(vector<vector<int>> &isConnected) {
        size = isConnected.size();
        visited.assign(size, false);

        for (int i = 0; i < size; i++) {
            if (!visited[i]) {
                provinces += 1;
                dfs(i, isConnected);
            }
        }

        return provinces;
    }

  private:
    int size;
    vector<bool> visited;
    int provinces = 0;

    void dfs(int startingNode, vector<vector<int>> &isConnected) {
        stack<int> myStack;
        myStack.push(startingNode);
        visited[startingNode] = true;

        while (!myStack.empty()) {
            int curr = myStack.top();
            myStack.pop();

            for (int neighbor = 0; neighbor < size; neighbor++) {
                if (isConnected[curr][neighbor] == 1 && !visited[neighbor]) {
                    visited[neighbor] = true;
                    myStack.push(neighbor);
                }
            }
        }
    }
};

// Time Complexity: O(n^2)
// Space Complexity: O(n)

// Solution 2: Iterative BFS
class Solution {
  public:
    int findCircleNum(vector<vector<int>> &isConnected) {
        size = isConnected.size();
        visited.assign(size, false);

        for (int i = 0; i < size; i++) {
            if (!visited[i]) {
                provinces += 1;
                bfs(i, isConnected);
            }
        }

        return provinces;
    }

  private:
    int size;
    vector<bool> visited;
    int provinces = 0;

    void bfs(int startingNode, vector<vector<int>> &isConnected) {
        queue<int> myQueue;
        myQueue.push(startingNode);
        visited[startingNode] = true;

        while (!myQueue.empty()) {
            int curr = myQueue.front();
            myQueue.pop();

            for (int neighbor = 0; neighbor < size; neighbor++) {
                if (isConnected[curr][neighbor] == 1 && !visited[neighbor]) {
                    visited[neighbor] = true;
                    myQueue.push(neighbor);
                }
            }
        }
    }
};

// Time Complexity: O(n^2)
// Space Complexity: O(n)