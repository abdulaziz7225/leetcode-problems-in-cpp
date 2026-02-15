/*
Problem Number: 451. Sort Characters By Frequency
Difficulty Level: Medium
Link: https://leetcode.com/problems/sort-characters-by-frequency

********************************************************************************

Given a string s, sort it in decreasing order based on the frequency of the
characters. The frequency of a character is the number of times it appears in
the string. Return the sorted string. If there are multiple answers, return any
of them.

Example 1:
Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid
answer.

Example 2:
Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc"
are valid answers. Note that "cacaca" is incorrect, as the same characters must
be together.

Example 3:
Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.

Constraints:
1 <= s.length <= 5 * 10^5
s consists of uppercase and lowercase English letters and digits.
*/

#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// Solution 1: Sorting
class Solution {
  public:
    string frequencySort(string s) {
        unordered_map<char, int> count;
        for (char chr : s) {
            count[chr]++;
        }

        vector<pair<char, int>> freqCharPairs(count.begin(), count.end());
        sort(freqCharPairs.begin(), freqCharPairs.end(),
             [](auto &a, auto &b) { return a.second > b.second; });

        string result;
        for (auto pair : freqCharPairs) {
            result.append(pair.second, pair.first);
        }

        return result;
    }
};

// m is the number of unique characters
// Time Complexity: O(2 * n + m * log(m)) ==> O(n + m * log(m))
// Space Complexity: O(n + 2 * m) ==> O(n + m)

// Solution 2: Heap Priority Queue
class Solution {
  public:
    string frequencySort(string s) {
        unordered_map<char, int> count;
        for (char chr : s) {
            count[chr]++;
        }

        priority_queue<pair<int, char>> maxHeap;
        for (auto pair : count) {
            maxHeap.push({pair.second, pair.first});
        }

        string result;
        while (!maxHeap.empty()) {
            auto [freq, chr] = maxHeap.top();
            maxHeap.pop();
            result.append(freq, chr);
        }

        return result;
    }
};

// m is the number of unique characters
// Time Complexity: O(2 * n + 2 * m * log(m)) ==> O(n + m * log(m))
// Space Complexity: O(n + 2 * m) ==> O(n + m)

// Solution 3: Bucket Sort
class Solution {
  public:
    string frequencySort(string s) {
        unordered_map<char, int> count;
        for (char chr : s) {
            count[chr]++;
        }

        int maxFreq = 0;
        for (auto [_, freq] : count) {
            if (freq > maxFreq) {
                maxFreq = freq;
            }
        }

        vector<vector<char>> freqBucket(maxFreq + 1);
        for (auto [chr, freq] : count) {
            freqBucket[freq].push_back(chr);
        }

        string result;
        result.reserve(s.size());
        
        for (int freq = maxFreq; freq > 0; freq--) {
            for (auto chr : freqBucket[freq]) {
                result.append(freq, chr);
            }
        }
        return result;
    }
};
// m is the number of unique characters
// Time Complexity: O(2 * (n + m) + max_freq) ==> O(n + m)
// Space Complexity: O(2 * n + m) ==> O(n + m)