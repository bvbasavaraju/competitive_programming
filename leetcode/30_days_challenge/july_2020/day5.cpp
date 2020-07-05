/****************************************************
Date: July 5th

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
  Q: Hamming Distance

  The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
  Given two integers x and y, calculate the Hamming distance.

  Note:
    0 ≤ x, y < 2^31.

  Example:
    Input: x = 1, y = 4
    Output: 2

    Explanation:
    1   (0 0 0 1)
    4   (0 1 0 0)
          ↑   ↑

  The above arrows point to positions where the corresponding bits are different.
*/

class Solution 
{
public:
  int hammingDistance(int x, int y) 
  {
    int r = x ^ y;
    
    int ans = 0;
    while(r > 0)
    {
      if(r & 0x01)
      {
        ans++;
      }
      
      r >>= 1;
    }
    
    return ans;
  }
};