/*
Problem Number: 155. Min Stack
Difficulty Level: Medium
Link: https://leetcode.com/problems/min-stack

********************************************************************************

Design a stack that supports push, pop, top, and retrieving the minimum element
in constant time. Implement the MinStack class: MinStack() initializes the stack
object. void push(int val) pushes the element val onto the stack. void pop()
removes the element on the top of the stack. int top() gets the top element of
the stack. int getMin() retrieves the minimum element in the stack. You must
implement a solution with O(1) time complexity for each function.

Example 1:
Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]
Output
[null,null,null,null,-3,null,0,-2]
Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2

Constraints:
-2^31 <= val <= 2^31 - 1
Methods pop, top and getMin operations will always be called on non-empty
stacks. At most 3 * 104 calls will be made to push, pop, top, and getMin.
*/

#include <vector>

using namespace std;

class MinStack {
  private:
    // index 0 for current value, index 1 for min value
    vector<vector<int>> stack;

  public:
    MinStack() : stack() {}

    void push(int val) {
        if (!stack.empty() && stack.back().at(1) < val) {
            stack.push_back({val, stack.back().at(1)});
        } else {
            stack.push_back({val, val});
        }
    }

    void pop() { stack.pop_back(); }

    int top() { return stack.back().at(0); }

    int getMin() { return stack.back().at(1); }
};

// Time Complexity:
// push(): O(1)
// pop(): O(1)
// top(): O(1)
// getMin(): O(1)
// Space Complexity: O(n)