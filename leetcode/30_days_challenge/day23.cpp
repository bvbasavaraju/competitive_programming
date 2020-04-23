/****************************************************
Date: April 24th

link: https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/531/week-4/3308/
****************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;

/*
  Q: Bitwise AND of Numbers Range

  Given a range [m, n] where 0 <= m <= n <= 2147483647, 
  return the bitwise AND of all numbers in this range, inclusive.

  Example 1:
  Input: [5,7]
  Output: 4

  Example 2:
  Input: [0,1]
  Output: 0
*/

class Solution 
{
public:
  int rangeBitwiseAnd(int m, int n) 
  {
    if(m == 0 || n == 0)
    {
      return 0;
    }
    
    unsigned long l = min(m, n);
    unsigned long h = max(m, n);
    
    vector<unsigned long> l_bytes(8, 0);
    vector<unsigned long> h_bytes(8, 0);
    
    //Get low and high number'e each byte in a vector. Each enctry in vector is a byte and 0th -> MSB and 7th LSB
    unsigned long mask = 0xf0000000;
    for(int i = 0; i < 8; ++i)
    {
      l_bytes[i] = ((l & mask) >> ((7 - i) * 4));
      mask = mask >> 4;
    }
    
    //printf("\n");
    mask = 0xf0000000;
    for(int i = 0; i < 8; ++i)
    {
      h_bytes[i] = ((h & mask) >> ((7 - i) * 4));
      mask = mask >> 4;
    }

    vector<unsigned long> ans(8, 0);
    for(int i = 0; i < 8; i++)
    {
      if(h_bytes[i] - l_bytes[i] >= 0)
      {
        unsigned long ans_ = l_bytes[i];
        for(int j = l_bytes[i] + 1; j <= h_bytes[i]; j++)
        {
          ans_ &= j;
        }
        
        ans[i] = ans_;
        
        //if the difference is greater than 0, then all other lsbs will be 0, so mark as 0
        if(h_bytes[i] - l_bytes[i] > 0)
        {
          for(int j = i + 1; j < 8; ++j)
          {
            h_bytes[j] = 0;
            l_bytes[j] = 0;
          }
        }
      }
    }
    
    //Compute the result
    unsigned long result = 0;
    for(int i = 0; i < 8; ++i)
    {
      result = result << 4;
      result |= ans[i];
    }
    
    return static_cast<int>(result);
  }
};