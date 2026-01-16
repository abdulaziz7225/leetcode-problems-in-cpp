/*
Problem Number: 225. Implement Stack using Queues
Difficulty Level: Easy
Link: https://leetcode.com/problems/implement-stack-using-queues

********************************************************************************

Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).
Implement the MyStack class:
void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.
Notes:
You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is empty operations are valid.
Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.

Example 1:
Input
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 2, 2, false]
Explanation
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // return 2
myStack.pop(); // return 2
myStack.empty(); // return False

Constraints:
1 <= x <= 9
At most 100 calls will be made to push, pop, top, and empty.
All the calls to pop and top are valid.
Follow-up: Can you implement the stack using only one queue?
*/

#include <queue>

using namespace std;

// Stack implementation using only one queue
class MyStack
{
private:
    queue<int> customStack;

public:
    MyStack() : customStack() {}

    void push(int x)
    {
        customStack.push(x);
        int length = customStack.size();
        for (int i = 0; i < length - 1; i++)
        {
            int topElement = customStack.front();
            customStack.pop();
            customStack.push(topElement);
        }
    }

    int pop()
    {
        int topElement = customStack.front();
        customStack.pop();
        return topElement;
    }

    int top() const
    {
        return customStack.front();
    }

    bool empty() const
    {
        return customStack.empty();
    }
};

// Time Complexity:
// push(): O(n)
// pop(): O(1)
// top(): O(1)
// emtpy(): O(1)
// Space Complexity: O(n)

// Stack implementation using two queues
class MyStack
{
private:
    queue<int> queue1;
    queue<int> queue2;

public:
    MyStack() : queue1(), queue2()
    {
    }

    void push(int x)
    {
        queue1.push(x);
    }

    int pop()
    {
        int length = queue1.size();
        for (int i = 0; i < length - 1; i++)
        {
            queue2.push(queue1.front());
            queue1.pop();
        }

        int topElement = queue1.front();
        queue1.pop();
        swap(queue1, queue2);

        return topElement;
    }

    int top()
    {
        int length = queue1.size();
        for (int i = 0; i < length - 1; i++)
        {
            queue2.push(queue1.front());
            queue1.pop();
        }

        int topElement = queue1.front();
        queue1.pop();
        queue2.push(topElement);
        swap(queue1, queue2);

        return topElement;
    }

    bool empty()
    {
        return queue1.empty();
    }
};

// Time Complexity:
// push(): O(1)
// pop(): O(n)
// top(): O(n)
// emtpy(): O(1)
// Space Complexity: O(n)
