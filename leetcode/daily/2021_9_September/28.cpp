/****************************************************
Date: September 28th

https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/639/week-4-september-22nd-september-28th/3990/
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
  Q: Sort Array By Parity II

  Given an array of integers nums, half of the integers in nums are odd, and the other half are even.

  Sort the array so that whenever nums[i] is odd, i is odd, and whenever nums[i] is even, i is even.

  Return any answer array that satisfies this condition.

  Example 1:
    Input: nums = [4,2,5,7]
    Output: [4,5,2,7]
    Explanation: 
      [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.

  Example 2:
    Input: nums = [2,3]
    Output: [2,3]

  Constraints:
    2 <= nums.length <= 2 * 104
    nums.length is even.
    Half of the integers in nums are even.
    0 <= nums[i] <= 1000

  Follow Up: 
    Could you solve it in-place?
*/

class Solution 
{
private:
  int getNextPos(vector<int>& nums, int sp, int l, bool evenPos)
  {
    for(int i = sp; i < l; ++i)
    {
      if(evenPos)
      {
        if(nums[i] % 2 == 0)
        {
          return i;
        }
      }
      else
      {
        if(nums[i] % 2 != 0)
        {
          return i;
        }
      }
    }
    
    return -1;
  }
public:
  vector<int> sortArrayByParityII(vector<int>& nums) 
  {
    int l = nums.size();
    for(int i = 0; i < l; ++i)
    {
      int p = -1;
      if(i % 2 == 0)
      {
        if(nums[i] % 2 != 0)
        {
          p = getNextPos(nums, i+1, l, true);
        }
      }
      else
      {
        if(nums[i] % 2 == 0)
        {
          p = getNextPos(nums, i+1, l, false);
        }
      }
      
      if(p >= 0)
      {
        swap(nums[i], nums[p]);
      }
    }
    
    return nums;
  }
};