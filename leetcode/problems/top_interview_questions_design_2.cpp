#include <iostream>
#include <vector>

using namespace std;

/*
  Q: Min Stack

  Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    getMin() -- Retrieve the minimum element in the stack.

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
    Methods pop, top and getMin operations will always be called on non-empty stacks.
  
  Hide Hint #1  
    Consider each node in the stack having a minimum value. (Credits to @aakarshmadhavan)
*/

class MinStack 
{
private:
  vector<pair<int, int>> nums;
public:
    /** initialize your data structure here. */
    MinStack() 
    {
    }
    
    void push(int x) 
    {
      if(nums.empty())
      {
        nums.push_back(std::make_pair(x,x));
      }
      else
      {
        int low = nums.back().second;
        nums.push_back(std::make_pair(x, min(x, low)));
      }
    }
    
    void pop() 
    {
      nums.pop_back();
    }
    
    int top() 
    {
      return nums.back().first;
    }
    
    int getMin() 
    {
      return nums.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */