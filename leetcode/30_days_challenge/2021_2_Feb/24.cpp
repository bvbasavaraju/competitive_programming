/****************************************************
Date: Feb 24rd

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
  Q : Score of Parentheses

  Given a balanced parentheses string S, compute the score of the string based on the following rule:

    () has score 1
    AB has score A + B, where A and B are balanced parentheses strings.
    (A) has score 2 * A, where A is a balanced parentheses string.

  Example 1:
    Input: "()"
    Output: 1

  Example 2:
    Input: "(())"
    Output: 2

  Example 3:
    Input: "()()"
    Output: 2

  Example 4:
    Input: "(()(()))"
    Output: 6

  Note:
    S is a balanced parentheses string, containing only ( and ).
    2 <= S.length <= 50
*/

class Solution 
{
public:
  int scoreOfParentheses(string S) 
  {
    stack<int>par;
    par.push(0);
    
    for(int ch : S)
    {
      if(ch == '(')
      {
        par.push(0);
      }
      else
      {
        int top = par.top();
        par.pop();
        
        if(top > 0)
        {
          top *= 2;
        }
        else
        {
          top = 1;
        }
        
        par.top() += top;
      }
    }
    
    return par.top();
  }
};