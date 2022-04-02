/****************************************************
Date: Feb 19th

link: https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/586/week-3-february-15th-february-21st/3641/
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
  Q: Minimum Remove to Make Valid Parentheses

  Given a string s of '(' , ')' and lowercase English characters. 

  Your task is to remove the minimum number of parentheses ( '(' or ')', 
  in any positions ) so that the resulting parentheses string is valid and return any valid string.

  Formally, a parentheses string is valid if and only if:
    + It is the empty string, contains only lowercase characters, or
    + It can be written as AB (A concatenated with B), where A and B are valid strings, or
    + It can be written as (A), where A is a valid string.

  Example 1:
    Input: s = "lee(t(c)o)de)"
    Output: "lee(t(c)o)de"
    Explanation: 
      "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.

  Example 2:
    Input: s = "a)b(c)d"
    Output: "ab(c)d"

  Example 3:
    Input: s = "))(("
    Output: ""
    Explanation: 
      An empty string is also valid.

  Example 4:
    Input: s = "(a(b(c)d)"
    Output: "a(b(c)d)"

  Constraints:
    1 <= s.length <= 10^5
    s[i] is one of  '(' , ')' and lowercase English letters.

  Hide Hint #1  
    Each prefix of a balanced parentheses has a number of open parentheses greater or equal than closed parentheses, similar idea with each suffix.
  Hide Hint #2  
    Check the array from left to right, remove characters that do not meet the property mentioned above, same idea in backward way.
*/

class Solution 
{
public:
  string minRemoveToMakeValid(string s) 
  {
    int l = s.size();
    stack<pair<int, int>> pile;
    
    for(int i = 0; i < l; ++i)
    {
      int ch = s[i];
      
      if(ch == ')')
      { 
        if(!pile.empty() && pile.top().first == '(')
        {
          pile.pop();
        }
        else
        {
          pile.push({ch, i});
        }
      }
      else if(ch == '(')
      {
        pile.push({ch, i});
      }
    }
    
    while(!pile.empty())
    {
      s.erase(pile.top().second, 1);
      pile.pop();
    }
    
    return s;
  }
};