/****************************************************
Date: April 15th

link: https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/595/week-3-april-15th-april-21st/3709/
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
  Q: Fibonacci Number

  The Fibonacci numbers, commonly denoted F(n) form a sequence, 
  called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

  F(0) = 0, F(1) = 1
  F(n) = F(n - 1) + F(n - 2), for n > 1.
  Given n, calculate F(n).

  Example 1:
    Input: n = 2
    Output: 1
    Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.

  Example 2:
    Input: n = 3
    Output: 2
    Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.

  Example 3:
    Input: n = 4
    Output: 3
    Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.

  Constraints:
    0 <= n <= 30
*/

class Solution 
{
public:
  int fib(int N) 
  {
    if(N <= 0)
    {
      return 0;
    }
    if(N < 2)
    {
      return 1;
    }
    
    vector<int> series(N, 0);
    series[0] = 1;
    series[1] = 1;
    for(int i = 2; i < N; i++)
    {
      series[i] = series[i - 1] + series[i - 2];
    }
    
    return series[N - 1];
  }
};