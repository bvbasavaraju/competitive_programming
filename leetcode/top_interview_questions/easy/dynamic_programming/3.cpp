#include <iostream>
#include <vector>

using namespace std;

/*
  Q: Maximum Subarray

  Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

  Example 1:
    Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
    Output: 6
    Explanation: 
      [4,-1,2,1] has the largest sum = 6.

  Example 2:
    Input: nums = [1]
    Output: 1

  Example 3:
    Input: nums = [0]
    Output: 0

  Example 4:
    Input: nums = [-1]
    Output: -1

  Example 5:
    Input: nums = [-100000]
    Output: -100000

  Constraints:
    1 <= nums.length <= 3 * 104
    -105 <= nums[i] <= 105

  Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/
class Solution 
{
public:
  int maxSubArray(vector<int>& n) 
  {
    int l = n.size();
    if(l <= 0)
    {
      return 0;
    }
    
    int sum = n[0];
    int result = sum;
    for(int i = 1; i < l; ++i)
    {
      sum = max(n[i], sum+n[i]);
      
      result = max(sum, result);
    }
    
    return result;
  }
};