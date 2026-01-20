/*
Problem Number: 146. LRU Cache
Difficulty Level: Medium
Link: https://leetcode.com/problems/lru-cache

********************************************************************************

Design a data structure that follows the constraints of a Least Recently Used
(LRU) cache. Implement the LRUCache class: LRUCache(int capacity) Initialize the
LRU cache with positive size capacity. int get(int key) Return the value of the
key if the key exists, otherwise return -1. void put(int key, int value) Update
the value of the key if the key exists. Otherwise, add the key-value pair to the
cache. If the number of keys exceeds the capacity from this operation, evict the
least recently used key. The functions get and put must each run in O(1) average
time complexity.

Example 1:
Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]
Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4

Constraints:
1 <= capacity <= 3000
0 <= key <= 10^4
0 <= value <= 10^5
At most 2 * 10^5 calls will be made to get and put.
*/

#include <unordered_map>

using namespace std;

class Node {
  public:
    int key;
    int val;
    Node *prev;
    Node *next;

    Node(int key, int val) : key(key), val(val), prev(nullptr), next(nullptr) {}
};

class LRUCache {
  private:
    int capacity;
    unordered_map<int, Node *> cache;
    Node *left;
    Node *right;

    void remove(Node *node) {
        Node *prev = node->prev;
        Node *next = node->next;

        prev->next = next;
        next->prev = prev;
    }

    void insert(Node *node) {
        Node *prev = right->prev;
        Node *next = right;

        prev->next = node;
        next->prev = node;
        node->prev = prev;
        node->next = next;
    }

  public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
    }

    int get(int key) {
        if (cache.count(key)) {
            remove(cache[key]);
            insert(cache[key]);
            return cache[key]->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cache.count(key)) {
            remove(cache[key]);
        }
        Node *new_node = new Node(key, value);
        cache[key] = new_node;
        insert(new_node);

        if (cache.size() > capacity) {
            Node *lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// n = capacity
// Time Complexity:
// get(): O(1)
// put(): O(1)
// Space Complexity: O(n)
