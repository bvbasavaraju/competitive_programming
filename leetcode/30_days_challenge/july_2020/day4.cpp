/****************************************************
Date: July 4th

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
  Q: Ugly Number II

  Write a program to find the n-th ugly number.
  Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

  Example:
    Input: n = 10
    Output: 12
    Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

  Note:  
    1 is typically treated as an ugly number.
    n does not exceed 1690.
    
  Hide Hint #1  
    The naive approach is to call isUgly for every number until you reach the nth one. Most numbers are not ugly. Try to focus your effort on generating only the ugly ones.
  Hide Hint #2  
    An ugly number must be multiplied by either 2, 3, or 5 from a smaller ugly number.
  Hide Hint #3  
    The key is how to maintain the order of the ugly numbers. Try a similar approach of merging from three sorted lists: L1, L2, and L3.
  Hide Hint #4  
    Assume you have Uk, the kth ugly number. Then Uk+1 must be Min(L1 * 2, L2 * 3, L3 * 5).
*/

class Solution 
{
private:
  /*unordered_set<int> ugly;
  unordered_set<int> not_ugly;
  
  vector<int> divs;
  bool isUgly(int num, int p)
  {
    if((p >= 3) || (not_ugly.find(num) != not_ugly.end()))
    {
      return false;
    }
    
    if(ugly.find(num) != ugly.end())
    {
      return true;
    }
    
    int n = num;
    while(num > 0)
    {
      if(num % 2 == 0)
      {
        num = num/2;
      }
      else if(num % 3 == 0)
      {
        num = num/3;
      }
      else if(num % 5 == 0)
      {
        num = num/5;
      }
      else
      {
        if(isUgly(num, p+1))
        {
          ugly.insert(num);
          return true;
        }
        else
        {
          not_ugly.insert(num);
          return false;
        }
      }
    }
    
    ugly.insert(n);
    return true;
  }*/
  
public:
  int nthUglyNumber(int n) 
  {
    vector<int> nums(n);
    nums[0] = 1;
    
    int i2 = 0;
    int i3 = 0;
    int i5 = 0;
    for(int i = 1; i < n; ++i)
    {
      int mini = min({nums[i2]*2, nums[i3]*3, nums[i5]*5});
      nums[i] = mini;
      if(nums[i] == nums[i2]*2)
      {
        i2++;
      }
      if(nums[i] == nums[i3]*3)
      {
        i3++;
      }
      if(nums[i] == nums[i5]*5)
      {
        i5++;
      }
    }
    
    return nums[n-1];
    //Slow solution
    /*int ans = 0;
    int count = 0;
    
    divs.push_back(2);
    divs.push_back(3);
    divs.push_back(5);
    
    ugly.insert(1);
    not_ugly.insert(0);
    for(int i = 1; count < n; ++i)
    {
      if(isUgly(i, 0))
      {
        count++;
        ans = i;
      }
    }
    
    return ans;*/
  }
};