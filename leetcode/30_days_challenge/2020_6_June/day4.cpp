/****************************************************
Date: June 4th

link: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3350/
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
  Q: Reverse String
  Write a function that reverses a string. The input string is given as an array of characters char[].
  Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
  You may assume all the characters consist of printable ascii characters.

  Example 1:
    Input: ["h","e","l","l","o"]
    Output: ["o","l","l","e","h"]

  Example 2:
    Input: ["H","a","n","n","a","h"]
    Output: ["h","a","n","n","a","H"]

  Hide Hint #1  
    The entire logic for reversing a string is based on using the opposite directional two-pointer approach!
*/

class Solution 
{
public:
  void reverseString(vector<char>& s) 
  {
    int l = s.size();
    for(int i = 0; i < l/2; ++i)
    {
      char ch = s[i];
      s[i] = s[l-i-1];
      s[l-i-1] = ch;
    }
  }
};