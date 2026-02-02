/*
Problem Number: 22. Generate Parentheses
Difficulty Level: Medium
Link: https://leetcode.com/problems/generate-parentheses

********************************************************************************

Given n pairs of parentheses, write a function to generate all combinations of
well-formed parentheses.

Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
Input: n = 1
Output: ["()"]

Constraints:
1 <= n <= 8
*/

#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<string> generateParenthesis(int n) {
        string currString = "";
        backtrack(0, 0, currString, n);
        return result;
    }

  private:
    vector<string> result;
    void backtrack(int openP, int closedP, string &currString, int n) {
        if (openP == n && closedP == n) {
            result.push_back(currString);
            return;
        }

        if (openP < n) {
            currString.push_back('(');
            backtrack(openP + 1, closedP, currString, n);
            currString.pop_back();
        }

        if (closedP < openP) {
            currString.push_back(')');
            backtrack(openP, closedP + 1, currString, n);
            currString.pop_back();
        }
    }
};

// n = number of valid sequences
// Time Complexity: O(4^n / sqrt(n))
// Space Complexity: O(4^n / sqrt(n) + 2 * n) ==> O(4^n / sqrt(n))