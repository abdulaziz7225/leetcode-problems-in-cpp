/*
Problem Number: 241. Different Ways to Add Parentheses
Difficulty Level: Medium
Link: https://leetcode.com/problems/different-ways-to-add-parentheses

********************************************************************************

Given a string expression of numbers and operators, return all possible results
from computing all the different possible ways to group numbers and operators.
You may return the answer in any order. The test cases are generated such that
the output values fit in a 32-bit integer and the number of different results
does not exceed 104.

Example 1:
Input: expression = "2-1-1"
Output: [0,2]
Explanation:
((2-1)-1) = 0
(2-(1-1)) = 2

Example 2:
Input: expression = "2*3-4*5"
Output: [-34,-14,-10,-10,10]
Explanation:
(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10

Constraints:
1 <= expression.length <= 20
expression consists of digits and the operator '+', '-', and '*'.
All the integer values in the input expression are in the range [0, 99].
The integer values in the input expression do not have a leading '-' or '+'
denoting the sign.
*/

#include <cctype>
#include <string>
#include <vector>

using namespace std;

// Solution 1: Recursion
class Solution {
  public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> results;

        if (expression.empty()) {
            return results;
        }

        if (expression.size() == 1 ||
            (expression.size() == 2 && isdigit(expression[0]))) {
            results.push_back(stoi(expression));
            return results;
        }

        for (int index = 0; index < expression.size(); index++) {
            char currChar = expression[index];

            if (isdigit(currChar)) {
                continue;
            }
            vector<int> leftResults =
                diffWaysToCompute(expression.substr(0, index));
            vector<int> rightResults =
                diffWaysToCompute(expression.substr(index + 1));

            for (int leftValue : leftResults) {
                for (int rightValue : rightResults) {
                    if (currChar == '+') {
                        results.push_back(leftValue + rightValue);
                    } else if (currChar == '-') {
                        results.push_back(leftValue - rightValue);
                    } else if (currChar == '*') {
                        results.push_back(leftValue * rightValue);
                    }
                }
            }
        }
        return results;
    }
};

// Time Complexity: O(n * 2^n)
// Space Complexity: O(2^n)

// Solution 2: Memoization
class Solution {
  public:
    vector<int> diffWaysToCompute(string expression) {
        int n = expression.size();
        memo.assign(n, vector<vector<int>>(n));
        return computeResults(expression, 0, n - 1);
    }

  private:
    vector<vector<vector<int>>> memo;

    vector<int> computeResults(string &expression, int start, int end) {
        if (!memo[start][end].empty()) {
            return memo[start][end];
        }

        vector<int> results;

        if (start == end || (end - start == 1 && isdigit(expression[start]))) {
            string sub = expression.substr(start, end - start + 1);
            results.push_back(stoi(sub));
            return results;
        }

        for (int index = start; index <= end; index++) {
            char currChar = expression[index];

            if (isdigit(currChar)) {
                continue;
            }

            vector<int> leftResults =
                computeResults(expression, start, index - 1);
            vector<int> rightResults =
                computeResults(expression, index + 1, end);

            for (int leftValue : leftResults) {
                for (int rightValue : rightResults) {
                    if (currChar == '+') {
                        results.push_back(leftValue + rightValue);
                    } else if (currChar == '-') {
                        results.push_back(leftValue - rightValue);
                    } else if (currChar == '*') {
                        results.push_back(leftValue * rightValue);
                    }
                }
            }
        }

        memo[start][end] = results;
        return results;
    }
};

// Time Complexity: O(n * 2^n)
// Space Complexity: O(n^2 * 2^n)