/****************************************************
Date: Feb 26th

link: https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/587/week-4-february-22nd-february-28th/3649/
****************************************************/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <limits.h>

using namespace std;

/*
  Q: Validate Stack Sequences

  Given two sequences pushed and popped with distinct values, 
  return true if and only if this could have been the result 
  of a sequence of push and pop operations on an initially empty stack.

  Example 1:
    Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
    Output: true
    Explanation: 
      We might do the following sequence:
      push(1), push(2), push(3), push(4), pop() -> 4,
      push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1

  Example 2:
    Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
    Output: false
    Explanation: 
      1 cannot be popped before 2.

  Constraints:
    0 <= pushed.length == popped.length <= 1000
    0 <= pushed[i], popped[i] < 1000
    pushed is a permutation of popped.
    pushed and popped have distinct values.
*/

class Solution 
{
public:
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
  {
    int popIndex = 0;
    
    stack<int> stk;
    for(int n : pushed)
    {
      stk.push(n);
      while(!stk.empty() && (popIndex < popped.size()) && popped[popIndex] == stk.top())
      {
        stk.pop();
        popIndex++;
      }
    }
    
    return (popIndex == popped.size() && stk.empty());
  }
};