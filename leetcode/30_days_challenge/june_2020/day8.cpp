/****************************************************
Date: June 8th

link: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3354/
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
  Q: Power of Two

  Given an integer, write a function to determine if it is a power of two.

  Example 1:
    Input: 1
    Output: true 
    Explanation: 20 = 1

  Example 2:
    Input: 16
    Output: true
    Explanation: 24 = 16

  Example 3:
    Input: 218
    Output: false
*/

class Solution 
{
public:
  bool isPowerOfTwo(int n) 
  {
    int count = 0;
    while(n > 0)
    {
      if(n & 0x01)
      {
        count++;
      }
      
      if(count > 1)
      {
        break;
      }
      
      n = n >> 1;
    }
    
    return (count == 1) ? true : false;
  }
};