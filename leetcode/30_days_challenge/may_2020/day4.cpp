/****************************************************
Date: May 4th

link: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3319/
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
  Q: Number Complement
  Given a positive integer, output its complement number.
  The complement strategy is to flip the bits of its binary representation.

  Example 1:
    Input: 5
    Output: 2
    Explanation:  The binary representation of 5 is 101 (no leading zero bits), 
                  and its complement is 010. So you need to output 2.

  Example 2:
    Input: 1
    Output: 0
    Explanation:  The binary representation of 1 is 1 (no leading zero bits), 
                  and its complement is 0. So you need to output 0.

  Note:
    The given integer is guaranteed to fit within the range of a 32-bit signed integer.
    You could assume no leading zero bit in the integer’s binary representation.
    This question is the same as 1009: https://leetcode.com/problems/complement-of-base-10-integer/
*/
class Solution 
{
public:
  int findComplement(int n) 
  {
    stack<int> b;
    while(n > 0)
    {
      b.push(n%2);
      n /= 2;
    }
    
    if(b.empty())
      return 1;
    
    vector<int> binary;
    while(!b.empty())
    {
      binary.push_back(b.top());
      b.pop();
    }
    
    if(binary.size() > 1 && binary[0] == 0)
      binary[0] = -1;
    
    for(int& bit : binary)
    {
      if(bit == -1)
        continue;
      
      if(bit == 1)
        bit = 0;
      else
        bit = 1;
    }
    
    int ans = 0;
    for(int bit : binary)
    {
      if(bit == -1)
        continue;
      
      ans = (ans * 2) + bit;
    }
    
    return ans;
  }
};