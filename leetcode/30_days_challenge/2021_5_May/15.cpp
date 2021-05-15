/****************************************************
Date: May 15th

link: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/600/week-3-may-15th-may-21st/3744/
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
  Q: Valid Number

  A valid number can be split up into these components (in order):
    + A decimal number or an integer.
    + (Optional) An 'e' or 'E', followed by an integer.
  
  A decimal number can be split up into these components (in order):
    + (Optional) A sign character (either '+' or '-').
    + One of the following formats:
      + At least one digit, followed by a dot '.'.
      + At least one digit, followed by a dot '.', followed by at least one digit.
      + A dot '.', followed by at least one digit.
  
  An integer can be split up into these components (in order):
    + (Optional) A sign character (either '+' or '-').
    + At least one digit.
  
  For example, 
    all the following are valid numbers: 
      ["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"], 
    while the following are not valid numbers: 
      ["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"].

  Given a string s, return true if s is a valid number.

  Example 1:
    Input: s = "0"
    Output: true

  Example 2:
    Input: s = "e"
    Output: false

  Example 3:
    Input: s = "."
    Output: false

  Example 4:
    Input: s = ".1"
    Output: true

  Constraints:
    1 <= s.length <= 20
    s consists of only English letters (both uppercase and lowercase), digits (0-9), plus '+', minus '-', or dot '.'.
*/

class Solution 
{
public:
  bool isNumber(string s) 
  {
    int signs_count = 0;
    int dot_count = 0;
    bool num_started = false;
    bool ePresent = false;
    bool num_after_e = false;
    
    char prev = 0;
    for(char ch : s)
    {
      switch(ch)
      {
        case '+':
        case '-':
          if((num_started && (prev != 'e')) || ((dot_count > 0) && (prev != 'e')))
          {
            return false;
          }
          signs_count++;
          if(signs_count > 1)
          {
            if(prev != 'e')
            {
              return false;
            }
          }
          break;
          
        case '.':
          dot_count++;
          if((dot_count > 1) || (ePresent))
          {
            return false;
          }
          break;
          
        case 'e':
        case 'E':
          if(ePresent || !num_started)
          {
            return false;
          }
          ePresent = true;
          break;
          
        default:
          if(((ch - '0') >= 0) && ((ch - '0') <= 9))
          {
            if(ePresent)
            {
              num_after_e = true;
            }

            num_started = true;
          }
          else
          {
            return false;
          }
          break;
      }
      
      prev = ch;
    }
    
    if((ePresent && !num_after_e) || (dot_count > 0 && !num_started) || (signs_count > 0 && !num_started))
    {
      return false;
    }
    return  true;
  }
};