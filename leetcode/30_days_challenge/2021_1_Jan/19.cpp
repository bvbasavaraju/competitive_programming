/****************************************************
Date: Jan 19th

link: https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/581/week-3-january-15th-january-21st/3606/
****************************************************/

/*
  Q: Longest Palindromic Substring

  Given a string s, return the longest palindromic substring in s.

  Example 1:
    Input: s = "babad"
    Output: "bab"
    Note: "aba" is also a valid answer.

  Example 2:
    Input: s = "cbbd"
    Output: "bb"

  Example 3:
    Input: s = "a"
    Output: "a"

  Example 4:
    Input: s = "ac"
    Output: "a"

  Constraints:
    1 <= s.length <= 1000
    s consist of only digits and English letters (lower-case and/or upper-case),

  Hide Hint #1  
    How can we reuse a previously computed palindrome to compute a larger palindrome?
  Hide Hint #2  
    If “aba” is a palindrome, is “xabax” and palindrome? Similarly is “xabay” a palindrome?
  Hide Hint #3  
    Complexity based hint:
    If we use brute-force and check whether for every start and end position a substring is a palindrome we have O(n^2) start - end pairs and O(n) palindromic checks. 
    Can we reduce the time for palindromic checks to O(1) by reusing some previous computation.
*/

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

class Solution 
{
private:
  bool IsPalindrome(const string& source, int firstIndex, int lastIndex, string& result)
  {
    bool retVal = true;
    int f = firstIndex;
    int l = lastIndex;
    while(f <= l)
    {
      if(source[f] != source[l])
      {
        retVal = false;
        break;
      }
      
      f++;
      l--;
    }
    
    if(retVal)
    {
      result = source.substr(firstIndex, (lastIndex - firstIndex + 1));
    }
    
    return retVal;
  }
  
public:
  string longestPalindrome(string s) 
  {
    string retVal;
    int l = s.size();    
    for(int i = 0; i < l; i++)
    {
      for(int j = (i + 1); j < l; j++)
      {
        if(s[i] == s[j])
        {
          string subStr;
          if(IsPalindrome(s, i, j, subStr))
          {
            retVal = (retVal.size() >= subStr.size()) ? retVal : subStr;
          }
        }
      }
      
      if(retVal.size() == l)
      {
        break;
      }
    }
    
    if(retVal.empty() && (l > 0))
    {
      retVal = s.substr(0, 1);
    }
    
    return retVal;
  }
};