/*
Problem Number: 509. Fibonacci Number
Difficulty Level: Easy
Link: https://leetcode.com/problems/fibonacci-number

********************************************************************************

The Fibonacci numbers, commonly denoted F(n) form a sequence, called the
Fibonacci sequence, such that each number is the sum of the two preceding ones,
starting from 0 and 1. That is, F(0) = 0, F(1) = 1 F(n) = F(n - 1) + F(n - 2),
for n > 1. Given n, calculate F(n).

Example 1:
Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.

Example 2:
Input: n = 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.

Example 3:
Input: n = 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.

Constraints:
0 <= n <= 30
*/

#include <iostream>
#include <vector>

using namespace std;

// Solution 1: Tabulation approach with storing
class Solution {
  public:
    int fib(int n) {
        if (n <= 1) {
            return n;
        }

        vector<int> fibSeq(n + 1);
        fibSeq.at(0) = 0;
        fibSeq.at(1) = 1;

        for (int i = 2; i <= n; i++) {
            fibSeq.at(i) = fibSeq.at(i - 1) + fibSeq.at(i - 2);
        }

        return fibSeq.at(n);
    }
};
// Time Complexity: O(n)
// Space Complexity: O(n)

// Solution 2: Tabulation approach without storing
class Solution {
  public:
    int fib(int n) {
        if (n <= 1) {
            return n;
        }

        int prev = 0;
        int curr = 1;

        for (int i = 2; i <= n; i++) {
            int temp = prev;
            prev = curr;
            curr = temp + curr;
        }

        return curr;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1)

// Solution 3: Memoization(Top-Down) approach
class Solution {
  public:
    int fib(int n) {
        if (n < 2) {
            return n;
        }

        vector<int> dp(n + 1, -1);
        dp.at(0) = 0;
        dp.at(1) = 1;

        return helper(n, dp);
    }

  private:
    int helper(int n, vector<int> &dp) {
        if (dp.at(n) != -1) {
            return dp.at(n);
        }
        dp.at(n) = helper(n - 1, dp) + helper(n - 2, dp);
        return dp.at(n);
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)
