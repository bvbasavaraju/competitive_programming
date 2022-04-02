/****************************************************
Date: April 3rd

link: https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/593/week-1-april-1st-april-7th/3693/
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
  Q: Longest Valid Parentheses

  Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

  Example 1:
    Input: s = "(()"
    Output: 2
    Explanation:
      The longest valid parentheses substring is "()".

  Example 2:
    Input: s = ")()())"
    Output: 4
    Explanation:
      The longest valid parentheses substring is "()()".

  Example 3:
    Input: s = ""
    Output: 0

  Constraints:
    0 <= s.length <= 3 * 104
    s[i] is '(', or ')'.
*/

class Solution 
{
public:
  int longestValidParentheses(string s) 
  {
    int l = s.size();
    
    stack<int> stk;
    
    for(int i = 0 ; i < l; ++i)
    {
      if(s[i] == '(')
      {
        stk.push(i);
      }
      else
      {
        if(!stk.empty())
        {
          if(s[stk.top()] == '(')
          {
            stk.pop();
          }
          else
          {
            stk.push(i);
          }
        }
        else
        {
          stk.push(i);
        }
      }
    }
    
    int ans = stk.empty() ? l : 0;
    if(!stk.empty())
    {
      int l1 = l;
      int l2 = 0;
      while(!stk.empty())
      {
        l2 = stk.top();
        stk.pop();
        
        ans = max(ans, l1-l2-1);
        l1 = l2;
      } 
      
      ans = max(ans, l1);
    }
    
    return ans;
  }
};