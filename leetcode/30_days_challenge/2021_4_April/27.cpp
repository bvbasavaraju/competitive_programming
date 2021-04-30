/****************************************************
Date: April 27th

link: https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/596/week-4-april-22nd-april-28th/3717/
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
  Q: Power of Three

  Given an integer n, return true if it is a power of three. Otherwise, return false.
  An integer n is a power of three, if there exists an integer x such that n == 3x.

  Example 1:
    Input: n = 27
    Output: true

  Example 2:
    Input: n = 0
    Output: false

  Example 3:
    Input: n = 9
    Output: true

  Example 4:
    Input: n = 45
    Output: false

  Constraints:
    -231 <= n <= 231 - 1

  Follow up: Could you solve it without loops/recursion?
*/

class Solution 
{
public:
  bool isPowerOfThree(int n) 
  {
    for(long long i = 1; i <= n; i *= 3)
    {
      if(static_cast<int>(i) == n)
      {
        return true;
      }
    }
    
    return false;
  }
};