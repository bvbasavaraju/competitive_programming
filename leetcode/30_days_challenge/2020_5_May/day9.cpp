/****************************************************
Date: May 9th

link: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3324/
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
  Q: Valid Perfect Square
  Given a positive integer num, write a function which returns True if num is a perfect square else False.

  Note: Do not use any built-in library function such as sqrt.

  Example 1:
    Input: 16
    Output: true
  
  Example 2:
    Input: 14
    Output: false
*/

class Solution 
{
public:
  bool isPerfectSquare(int num) 
  {
    int l = 1;
    int h = num == 1 ? num : num/2;
    //int h = num;
    
    int64_t sq = 1;
    while(l <= h)
    {
      int m = l + (h-l)/2;
      
      if(m <= num/m)
      {
        sq = m;
        l = m + 1;
      }
      else
      {
        h = m - 1;
      }
    }
    
    return sq * sq == num ? true : false;
  }
};