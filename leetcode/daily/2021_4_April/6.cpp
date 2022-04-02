/****************************************************
Date: April 6th

link: https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/593/week-1-april-1st-april-7th/3693/
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
  Q: Minimum Operations to Make Array Equal

  You have an array arr of length n where arr[i] = (2 * i) + 1 for all valid values of i (i.e. 0 <= i < n).
  In one operation, you can select two indices x and y where 0 <= x, y < n and subtract 1 from arr[x] and add 1 to arr[y] 
  (i.e. perform arr[x] -=1 and arr[y] += 1). The goal is to make all the elements of the array equal. 
  It is guaranteed that all the elements of the array can be made equal using some operations.

  Given an integer n, the length of the array. Return the minimum number of operations needed to make all the elements of arr equal.

  Example 1:
    Input: n = 3
    Output: 2
    Explanation: 
      arr = [1, 3, 5]
      First operation choose x = 2 and y = 0, this leads arr to be [2, 3, 4]
      In the second operation choose x = 2 and y = 0 again, thus arr = [3, 3, 3].

  Example 2:
    Input: n = 6
    Output: 9

  Constraints:
    1 <= n <= 10^4

  Hide Hint #1  
    Build the array arr using the given formula, define target = sum(arr) / n
  Hide Hint #2  
    What is the number of operations needed to convert arr so that all elements equal target ?
*/
class Solution 
{
public:
  int minOperations(int n) 
  {
    ////O(1) space complexity - even better time optimization!
    int ans = 0;
    for(int i = 1; i < n; i=i+2)
    {
      ans += (n - i);
    }
    
    return ans;
    
    //O(1) space complexity
//     int ans = 0;
//     for(int i = 0; i < n/2; ++i)
//     {
//       ans += (n - (2*i + 1));
//     }
    
//     return ans;
    
    //O(n) space complexity
//     vector<int> nums(n/2);
    
//     for(int i = 0; i < n/2; ++i)
//     {
//       nums[i] = 2*i + 1;
//     }
    
//     int ans = 0;
//     for(int& num : nums)
//     {
//       ans += n - num;
//     }
    
//     return ans;
  }
};