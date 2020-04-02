/****************************************************
Date: April 2st

link: https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/528/week-1/3284/
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
  Q:  Happy Number

  Write an algorithm to determine if a number is "happy".

  A happy number is a number defined by the following process: 
  Starting with any positive integer, replace the number by the sum of the squares of its digits, 
  and repeat the process until the number equals 1 (where it will stay), 
  or it loops endlessly in a cycle which does not include 1. 
  Those numbers for which this process ends in 1 are happy numbers.

  Example: 
  Input: 19
  Output: true
  Explanation: 
  12 + 92 = 82
  82 + 22 = 68
  62 + 82 = 100
  12 + 02 + 02 = 1
*/

class Solution 
{
public:
  bool isHappy(int n) 
  {
    int copy = n;
    unordered_map<int, int> s_map;  //square_map
    unordered_map<int, int> count_map;  // count_map
    while(n > 1)
    {
      count_map[n]++;
      if(count_map[n] > 1)
      {
        return false;
      }
      
      string s = std::to_string(n);
      n = 0;
      int l = s.size();
      for(int i = 0; i < l; i++)
      {
        int d = s[i] - '0';
        if(s_map.count(d) == 0)
        {
          s_map[d] = d * d;
        }
        
        n += s_map[d];
      }
    }
    
    return (n == 1);
  }
};