/****************************************************
Date: April 10th

link: https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/529/week-2/3292/
****************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;

/*
  Q:  Min Stack
  Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

  push(x) -- Push element x onto stack.
  pop() -- Removes the element on top of the stack.
  top() -- Get the top element.
  getMin() -- Retrieve the minimum element in the stack.

  Example:
  MinStack minStack = new MinStack();
  minStack.push(-2);
  minStack.push(0);
  minStack.push(-3);
  minStack.getMin();   --> Returns -3.
  minStack.pop();
  minStack.top();      --> Returns 0.
  minStack.getMin();   --> Returns -2.

  Show Hint #1
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