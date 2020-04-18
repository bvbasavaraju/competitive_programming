/****************************************************
Date: April 16th

link: https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/530/week-3/3301/
****************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using namespace std;

/*
  Q:  Valid Parenthesis String

  Given a string containing only three types of characters: '(', ')' and '*', 
  write a function to check whether this string is valid. 
  
  We define the validity of a string by these rules:
  Any left parenthesis '(' must have a corresponding right parenthesis ')'.
  Any right parenthesis ')' must have a corresponding left parenthesis '('.
  Left parenthesis '(' must go before the corresponding right parenthesis ')'.
  '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
  An empty string is also valid.

  Example 1:
  Input: "()"
  Output: True
  
  Example 2:
  Input: "(*)"
  Output: True
  
  Example 3:
  Input: "(*))"
  Output: True
  
  Note:
    The string size will be in the range [1, 100].
*/

class Solution 
{
public:
  bool checkValidString(string s) 
  {
    int l = s.size();
    vector<int> star;
    stack< pair<int, int> > st; //first = bracket, second = pos
    
    for(int i = 0; i < l; ++i)
    {
      if(s[i] == '*')
      {
        star.push_back(i);
      }
      else if(s[i] == ')')
      {
        if(st.empty())
        {
          if(star.size() == 0)
            return false;
          else
            star.pop_back();
        }
        else if(st.top().first == '(')
        {
          st.pop();
        }
        else
          st.push(std::make_pair(s[i], i));
      }
      else
      {
        if(st.empty())
          star.clear();
        st.push(std::make_pair(s[i], i));
      }
    }
    
    while(st.size() > 0 && star.size() > 0 && st.size() <= star.size())
    {
      if(st.top().second > star.back())
      {
        return false;
      }
      else
      {
        st.pop();
        star.pop_back();
      }
    }
    
    return (st.size() <= star.size()) || (st.empty() == true);
  }
};