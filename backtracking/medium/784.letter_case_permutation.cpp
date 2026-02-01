/*
Problem Number: 784. Letter Case Permutation
Difficulty Level: Medium
Link: https://leetcode.com/problems/letter-case-permutation

********************************************************************************

Given a string s, you can transform every letter individually to be lowercase or
uppercase to create another string. Return a list of all possible strings we
could create. Return the output in any order.

Example 1:
Input: s = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]

Example 2:
Input: s = "3z4"
Output: ["3z4","3Z4"]

Constraints:
1 <= s.length <= 12
s consists of lowercase English letters, uppercase English letters, and digits.
*/

#include <cctype>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<string> letterCasePermutation(string s) {
        vector<string> result = {s};

        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                continue;
            }

            int n = result.size();
            for (int k = 0; k < n; k++) {
                string permutation = result[k];

                if (isupper(permutation[i])) {
                    permutation[i] = tolower(permutation[i]);
                } else {
                    permutation[i] = toupper(permutation[i]);
                }

                result.push_back(permutation);
            }
        }
        return result;
    }
};
// Time Complexity: O(n * 2^n)
// Space Complexity: O(n * 2^n)