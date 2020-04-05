/****************************************************
Date: April 1st

link: https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/528/week-1/3283/
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
  Q:  Single Number

  Given a non-empty array of integers, every element appears twice except for one. Find that single one.

  Note:
  Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

  Example 1:
  Input: [2,2,1]
  Output: 1

  Example 2:
  Input: [4,1,2,1,2]
  Output: 4
*/

class Solution
{
public:
  int singleNumber(vector<int>& n) 
  {
    //Hint: XOR'ing same 2 numbers result in 0!!
    int x = n[0];
    int l = n.size();
    for (int i = 1; i < l; ++i)
    {
      x ^= n[i];
    }
    
    return x;
  }
};