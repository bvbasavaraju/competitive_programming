/****************************************************
Date: May 13th

link: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3328/
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
  Q: Remove K Digits

  Given a non-negative integer num represented as a string,
  remove k digits from the number so that the new number is the smallest possible.

  Note:
  The length of num is less than 10002 and will be ≥ k.
  The given num does not contain any leading zero.
  
  Example 1:
    Input: num = "1432219", k = 3
    Output: "1219"
    Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

  Example 2:
    Input: num = "10200", k = 1
    Output: "200"
    Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.

  Example 3:
    Input: num = "10", k = 2
    Output: "0"
    Explanation: Remove all the digits from the number and it is left with nothing which is 0.
*/

class Solution 
{
public:
  string removeKdigits(string num, int k) 
  {
    int l = num.size();
    if(l == 0 || l == k)
    {
      return "0";
    }
    
    int i = 0;
    while(k)
    {
      int cur = (num[i] != 0) ? num[i] - '0' : 0;
      int next = i < (num.size() - 1) ? num[i+1] - '0' : 0;
      
      if((cur > next) || (k == num.size() - i))
      {
        num.erase(i, 1);
        i = max(-1, i - 2);
        k--;
      }
      
      i++;
    }
    
    i = num.find_first_not_of("0");
    num.erase(0, i);
    
    return num.empty() ? "0" : num;
  }
};