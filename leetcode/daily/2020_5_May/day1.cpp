/****************************************************
Date: May 1st

link: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3316/
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
  Q: First Bad Version

  You are a product manager and currently leading a team to develop a new product.
  Unfortunately, the latest version of your product fails the quality check.
  Since each version is developed based on the previous version, all the versions after a bad version are also bad.

  Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one,
  which causes all the following ones to be bad.

  You are given an API bool isBadVersion(version) which will return whether version is bad.
  Implement a function to find the first bad version. You should minimize the number of calls to the API.

  Example:
    Given n = 5, and version = 4 is the first bad version.

    call isBadVersion(3) -> false
    call isBadVersion(5) -> true
    call isBadVersion(4) -> true

    Then 4 is the first bad version. 
*/

// The API isBadVersion is defined for you.

bool isBadVersion(int version);
class Solution 
{
public:
  int firstBadVersion(int n) 
  {
    int ans = 0;
    
    int l = 0;
    int h = n;
    
    while(l <= h)
    {
      int m = l + (h-l)/2;
      
      if(isBadVersion(m))
      {
        ans = m;
        h = m - 1;
      }
      else
      {
        l = m + 1;
      }
    }
    
    return ans;
  }
};