/*
Problem Number: 232. Implement Queue using Stacks
Difficulty Level: Easy
Link: https://leetcode.com/problems/implement-queue-using-stacks

********************************************************************************

Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).
Implement the MyQueue class:
void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
Notes:
You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.

Example 1:
Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]
Explanation
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false

Constraints:
1 <= x <= 9
At most 100 calls will be made to push, pop, peek, and empty.
All the calls to pop and peek are valid.
Follow-up: Can you implement the queue such that each operation is amortized O(1) time complexity? In other words, performing n operations will take overall O(n) time even if one of those operations may take longer.
*/

#include <stack>

using namespace std;

// Queue implementation using two stacks
class MyQueue
{
private:
    stack<int> stack1;
    stack<int> stack2;

public:
    MyQueue() : stack1(), stack2()
    {
    }

    void push(int x)
    {
        while (!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }

        stack1.push(x);

        while (!stack2.empty())
        {
            stack1.push(stack2.top());
            stack2.pop();
        }
    }

    int pop()
    {
        int topElement = stack1.top();
        stack1.pop();
        return topElement;
    }

    int peek()
    {
        return stack1.top();
    }

    bool empty()
    {
        return stack1.empty();
    }
};

// Time Complexity:
// push(): O(2 * n) ==> O(n)
// pop(): O(1)
// peek(): O(1)
// empty(): O(1)
// Space Complexity: O(n)

// Queue implementation using two stacks: Amortized Approach
class MyQueue
{
private:
    stack<int> inputStack;
    stack<int> outputStack;

public:
    MyQueue() : inputStack(), outputStack()
    {
    }

    void push(int x)
    {
        inputStack.push(x);
    }

    int pop()
    {
        int topElement = peek();
        outputStack.pop();
        return topElement;
    }

    int peek()
    {
        if (outputStack.empty())
        {
            while (!inputStack.empty())
            {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }
        return outputStack.top();
    }

    bool empty()
    {
        return inputStack.empty() && outputStack.empty();
    }
};

// Time Complexity:
// push(): O(1)
// pop(): amortized O(1)
// peek(): amortized O(1)
// empty(): O(1)
// Space Complexity: O(n)