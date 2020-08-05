/****************************************************
Date: July 4th

link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/549/week-1-august-1st-august-7th/3409/
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
  Q: Power of Four

  Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

  Example 1:
    Input: 16
    Output: true
  
  Example 2:
    Input: 5
    Output: false

  Follow up: Could you solve it without loops/recursion?
*/

class Solution 
{
public:
  bool isPowerOfFour(int num) 
  {
    if(num <= 0)
    {
      return false;
    }
    
    int bitPos = 0;
    int bitCount = 0;
    while(num > 0)
    {
      if(num & 0x01)
      {
        bitCount++;
        if(bitPos % 2 != 0)
        {
          return false;
        }
      }
      
      if(bitCount > 1)
      {
        return false;
      }
      
      num >>= 1;
      bitPos++;
    }
    
    return true;
  }
};