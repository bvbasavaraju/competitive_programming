/****************************************************
Date: July 15th

link: https://leetcode.com/explore/featured/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3377/
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
  Q: Reverse Words in a String

  Given an input string, reverse the string word by word.

  Example 1:
    Input: "the sky is blue"
    Output: "blue is sky the"

  Example 2:
    Input: "  hello world!  "
    Output: "world! hello"
    Explanation: Your reversed string should not contain leading or trailing spaces.

  Example 3:
    Input: "a good   example"
    Output: "example good a"
    Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

  Note:
    A word is defined as a sequence of non-space characters.
    Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
    You need to reduce multiple spaces between two words to a single space in the reversed string.

  Follow up:
  For C programmers, try to solve it in-place in O(1) extra space.
*/

class Solution 
{
public:
  string reverseWords(string s) 
  {
    string ans;
    
    int l = s.size();
    size_t p = 0;
    while(p < l && s[p] == ' ')
    {
      p++;
    }
    
    if(p >= l)
    {
      return ans;
    }
    
    vector<string> strs;
    while(p != string::npos && p < l)
    {
      int start = p;
      
      p = s.find_first_of(' ', p);
      if(p != string::npos)
      {
        string sub = s.substr(start, p-start);
        strs.push_back(sub);
      }
      else
      {
        string sub = s.substr(start, l-start);
        strs.push_back(sub);
        break;
      }
      
      while(p < l && s[p] == ' ')
      {
        p++;
      }
    }
    
    l = strs.size() - 1;
    while(l >= 0)
    {
      ans += strs[l];
      if(l > 0)
      {
        ans += ' ';
      }
      
      l--;
    }
    
    return ans;
  }
};