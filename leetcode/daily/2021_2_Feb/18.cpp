/****************************************************
Date: Feb 18th

link: https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/586/week-3-february-15th-february-21st/3641/
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
  Q: Arithmetic Slices

  A sequence of numbers is called arithmetic if it consists of at least three elements 
  and if the difference between any two consecutive elements is the same.

  For example, these are arithmetic sequences:
    1, 3, 5, 7, 9
    7, 7, 7, 7
    3, -1, -5, -9

  The following sequence is not arithmetic.
  1, 1, 2, 5, 7
  
  A zero-indexed array A consisting of N numbers is given. 
  A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.
  A slice (P, Q) of the array A is called arithmetic if the sequence:
  A[P], A[P + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.

  The function should return the number of arithmetic slices in the array A.

  Example:
    A = [1, 2, 3, 4]
    return: 3, 
      for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.
*/
class Solution 
{  
public:
  int numberOfArithmeticSlices(vector<int>& A) 
  {
    int l = A.size();
    if(l < 3)
    {
      return 0;
    }
    
    int ans = 0;
    for(int i = 1; i < l; ++i)
    {      
      int num1 = A[i-1];
      int num2 = A[i];
      
      int diff = num2-num1;
      int count = 1;
      
      int backup = i;
      while(num2 - num1 == diff)
      {
        count++;
        num1 = num2;
        
        i++;
        
        if(i >= l)
        {
          break;
        }
        
        num2 = A[i];
      }

      if(count >= 3)
      {
        ans += (count - 1) * (count - 2) / 2;
        i--;  //Need to go one step back as extra incremented is in loop
      }
      else
      {
        i = backup; 
      }
    }
    
    return ans;
  }
};