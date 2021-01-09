/****************************************************
Date: July 16th

link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/546/week-3-july-15th-july-21st/3393/
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
  Q: Pow(x, n)

  Implement pow(x, n), which calculates x raised to the power n (xn).

  Example 1:
    Input: 2.00000, 10
    Output: 1024.00000

  Example 2:
    Input: 2.10000, 3
    Output: 9.26100

  Example 3:
    Input: 2.00000, -2
    Output: 0.25000

  Explanation: 2-2 = 1/22 = 1/4 = 0.25
  
  Note:
    -100.0 < x < 100.0
    n is a 32-bit signed integer, within the range [−231, 231 − 1]
*/
class Solution 
{
public:
  double myPow(double x, int n) 
  {
    if(x == 1 || n == 0)
    {
      return 1.0;
    }
    
    bool neg = n < 0 ? true : false;
    double ans = 1.0;
    
    int64_t n_ = n;
    n_ = abs(n_);
    
    ans = pow(x, n_);
    
    return neg ? (1.0 / ans) : ans;  
  }
};