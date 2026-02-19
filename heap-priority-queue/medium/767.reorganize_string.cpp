/*
Problem Number: 767. Reorganize String
Difficulty Level: Medium
Link: https://leetcode.com/problems/reorganize-string/

********************************************************************************

Given a string s, rearrange the characters of s so that any two adjacent
characters are not the same. Return any possible rearrangement of s or return ""
if not possible.

Example 1:
Input: s = "aab"
Output: "aba"

Example 2:
Input: s = "aaab"
Output: ""

Constraints:
1 <= s.length <= 500
s consists of lowercase English letters.
*/

#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    string reorganizeString(string s) {
        unordered_map<char, int> count;
        for (char currChar : s) {
            count[currChar]++;
        }

        priority_queue<pair<int, char>> maxHeap;
        for (auto [currChar, freq] : count) {
            maxHeap.push({freq, currChar});
        }

        int prevFreq = 0;
        char prevChar;
        string result;
        result.reserve(s.size());

        while (!maxHeap.empty()) {
            auto [freq, currChar] = maxHeap.top();
            maxHeap.pop();
            result += currChar;

            if (prevFreq > 0) {
                maxHeap.push({prevFreq, prevChar});
            }

            freq--;
            prevFreq = freq;
            prevChar = currChar;
        }

        if (result.size() != s.size()) {
            return "";
        }
        return result;
    }
};

// n = len(s), m = number of unique characters
// Time Complexity: O(n + (n + m) * log(m)) ==> O(n * log(m))
// Space Complexity: O(n + 2 * m) ==> O(n)