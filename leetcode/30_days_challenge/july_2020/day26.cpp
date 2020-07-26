/****************************************************
Date: July 26th

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
  Q: Add Digits

  Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

  Example:
  Input: 38
  Output: 2 
  Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2. 
              Since 2 has only one digit, return it.

  Follow up:
  Could you do it without any loop/recursion in O(1) runtime?

  Hide Hint #1  
    A naive implementation of the above process is trivial. Could you come up with other methods?
  Hide Hint #2  
    What are all the possible results?
  Hide Hint #3  
    How do they occur, periodically or randomly?
  Hide Hint #4  
    You may find this Wikipedia article useful.
*/

class Solution 
{
public:
  int addDigits(int num) 
  {
    string n = to_string(num);
    int l = n.size();
    
    int sum = 0;
    for(int i = 0; i < l; ++i)
    {
      sum += n[i] - '0';
    }
    
    
    while(sum > 9)
    {
      n = to_string(sum);
      sum = 0;
      l = n.size();
      for(int i = 0; i < l; ++i)
      {
        sum += n[i] - '0';
      }
    }
    
    return sum;
  }
};