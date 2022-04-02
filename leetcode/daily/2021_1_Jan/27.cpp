/****************************************************
Date: Jan 27th

link: https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/582/week-4-january-22nd-january-28th/3616/
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
  Q: Concatenation of Consecutive Binary Numbers

  Given an integer n, return the decimal value of the binary string formed by concatenating the binary representations of 1 to n in order, modulo 109 + 7.

  Example 1:
    Input: n = 1
    Output: 1
    Explanation:
      "1" in binary corresponds to the decimal value 1. 
  
  Example 2:
    Input: n = 3
    Output: 27
    Explanation: 
      In binary, 1, 2, and 3 corresponds to "1", "10", and "11".
      After concatenating them, we have "11011", which corresponds to the decimal value 27.

  Example 3:
    Input: n = 12
    Output: 505379714
    Explanation:
      The concatenation results in "1101110010111011110001001101010111100".
      The decimal value of that is 118505380540.

  After modulo 109 + 7, the result is 505379714.

  Constraints:
    1 <= n <= 105

  Hide Hint #1  
    Express the nth number value in a recursion formula and think about how we can do a fast evaluation.
*/

class Solution 
{
private:  
public:
  int concatenatedBinary(int n) 
  {
    const int MOD = 1e9 + 7;
    
    int count = 2;
    int num_of_shits = 2;
    int shift_count = 0;
    
    long long ans = 1;
    for(int i = 2; i <= n; ++i)
    {
      ans = ((ans << num_of_shits) | i) % MOD;
      
      shift_count++;
      if(shift_count == count)
      {
        shift_count = 0;
        count = count << 1;
        num_of_shits++;
      }
    }
    
    return static_cast<int>(ans);
  }
};