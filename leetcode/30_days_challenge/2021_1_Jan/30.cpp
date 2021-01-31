/****************************************************
Date: Jan 30th

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
  Q: Minimize Deviation in Array

  You are given an array nums of n positive integers.

  You can perform two types of operations on any element of the array any number of times:
    + If the element is even, divide it by 2.
      For example, if the array is [1,2,3,4], then you can do this operation on the last element, and the array will be [1,2,3,2].
    + If the element is odd, multiply it by 2.
      For example, if the array is [1,2,3,4], then you can do this operation on the first element, and the array will be [2,2,3,4].
  
  The deviation of the array is the maximum difference between any two elements in the array.

  Return the minimum deviation the array can have after performing some number of operations.

  Example 1:
    Input: nums = [1,2,3,4]
    Output: 1
    Explanation: 
      You can transform the array to [1,2,3,2], then to [2,2,3,2], then the deviation will be 3 - 2 = 1.

  Example 2:
    Input: nums = [4,1,5,20,3]
    Output: 3
    Explanation: 
      You can transform the array after two operations to [4,2,5,5,3], then the deviation will be 5 - 2 = 3.

  Example 3:
    Input: nums = [2,10,8]
    Output: 3

  Constraints:
    n == nums.length
    2 <= n <= 105
    1 <= nums[i] <= 109

  Hide Hint #1  
    Assume you start with the minimum possible value for each number so you can only multiply a number by 2 till it reaches its maximum possible value.
  Hide Hint #2  
    If there is a better solution than the current one, then it must have either its maximum value less than the current maximum value, 
    or the minimum value larger than the current minimum value.
  Hide Hint #3  
    Since that we only increase numbers (multiply them by 2), we cannot decrease the current maximum value, so we must multiply the current minimum number by 2.
*/

class Solution 
{
public:
  int minimumDeviation(vector<int>& nums) 
  {
    int ans = INT_MAX;
    int mini = INT_MAX;
    
    priority_queue<int> pq;
    for(int n : nums)
    {
      n = (n%2 == 1) ? n*2 : n;
      
      pq.push(n);
      
      mini = min(mini, n);
    }
    
    int pq_top = pq.top();
    while(pq_top % 2 == 0)
    {
      pq.pop();
      
      ans = min(ans, abs(pq_top - mini));
      
      pq_top /= 2;
      mini = min(mini, pq_top);
      pq.push(pq_top);
      
      pq_top = pq.top();
    }
    
    return min(ans, abs(pq.top() - mini));
  }
};

int main()
{
  Solution s;
  vector<int> v = {4,1,5,20,3};
  s.minimumDeviation(v);
}