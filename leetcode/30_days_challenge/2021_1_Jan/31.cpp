/****************************************************
Date: Jan 31th

link: https://leetcode.com/explore/featured/card/january-leetcoding-challenge-2021/583/week-5-january-29th-january-31st/3621/
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
  Q: Next Permutation

  Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
  If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).
  The replacement must be in place and use only constant extra memory.

  Example 1:
    Input: nums = [1,2,3]
    Output: [1,3,2]

  Example 2:
    Input: nums = [3,2,1]
    Output: [1,2,3]

  Example 3:
    Input: nums = [1,1,5]
    Output: [1,5,1]

  Example 4:
    Input: nums = [1]
    Output: [1]

  Constraints:
    1 <= nums.length <= 100
    0 <= nums[i] <= 100
*/

class Solution 
{
public:
  void nextPermutation(vector<int>& nums) 
  {
    int l = nums.size();
    
    int p = l-1;
    int p_found = false;
    for(int i = p-1; i >= 0; --i)
    {
      if(nums[p]-nums[i] > 0)
      {
        p--;
        p_found = true;
        break;
      }
      p--;
    }
   
    //Time = n + n;
    if(p_found)
    {
      int next_num_pos = l-1;
      for(int i = l-1; i > p; --i)
      {
        if(nums[i] > nums[p])
        {
          next_num_pos = i;
          break;
        }
      }
      
      swap(nums[p], nums[next_num_pos]);
      p = p+1;
    }
    
    reverse(nums.begin()+p, nums.end());
    
//    Time - n + nlogn
//     if(p_found)
//     {
//       int next_num_pos = p+1;
//       int diff = INT_MAX;
//       for(int i = p+1; i < l; ++i)
//       {
//         if(((nums[i] - nums[p]) > 0) && (diff > (nums[i] - nums[p])))
//         {
//           diff = nums[i] - nums[p];
//           next_num_pos = i;
//         }
//       }
      
//       swap(nums[p], nums[next_num_pos]);
//       p = p+1;
//     }
    
    
//     sort(nums.begin()+p, nums.end());
  }
};