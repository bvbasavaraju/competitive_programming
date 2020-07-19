/****************************************************
Date: July 19th

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
  Q: Add Binary

  Given two binary strings, return their sum (also a binary string).
  The input strings are both non-empty and contains only characters 1 or 0.

  Example 1:
    Input: a = "11", b = "1"
    Output: "100"
  
  Example 2:
    Input: a = "1010", b = "1011"
    Output: "10101"

  Constraints:
    Each string consists only of '0' or '1' characters.
    1 <= a.length, b.length <= 10^4
    Each string is either "0" or doesn't contain any leading zero.
*/
class Solution 
{
public:
  string addBinary(string a, string b) 
  {
    int la = a.size();
    int lb = b.size();
    
    string diffZeros;
    for(int i = 0; i < abs(la-lb); ++i)
    {
      diffZeros += "0";
    }
    
    if(la < lb)
    {
      a = diffZeros + a;  
      la = lb;
    }
    else if(lb < la)
    {
      b = diffZeros + b;
      lb = la;
    }
    
    string ans;
    int carry = 0;
    for(int i = la-1; i >= 0; --i)
    {
      int sum = (a[i] - '0') + (b[i] - '0') + carry;
      
      carry = sum / 2;
      
      ans = (sum % 2 == 0) ? "0" + ans : "1" + ans; 
    }
    
    if(carry > 0)
    {
      ans = "1" + ans;
    }
    
    return ans;
  }
};