/****************************************************
Date: May 9th

link: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/599/week-2-may-8th-may-14th/3737/
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
  Q: Construct Target Array With Multiple Sums - gives wrong answer yet!!
  
  Given an array of integers target. From a starting array, A consisting of all 1's, you may perform the following procedure :
  + let x be the sum of all elements currently in your array.
  + choose index i, such that 0 <= i < target.size and set the value of A at index i to x.
  + You may repeat this procedure as many times as needed.
  
  Return True if it is possible to construct the target array from A otherwise return False.

  Example 1:
    Input: target = [9,3,5]
    Output: true
    Explanation: 
      Start with [1, 1, 1] 
      [1, 1, 1], sum = 3 choose index 1
      [1, 3, 1], sum = 5 choose index 2
      [1, 3, 5], sum = 9 choose index 0
      [9, 3, 5] Done
  
  Example 2:
    Input: target = [1,1,1,2]
    Output: false
    Explanation: 
      Impossible to create target array from [1,1,1,1].

  Example 3:
    Input: target = [8,5]
    Output: true

  Constraints:
    N == target.length
    1 <= target.length <= 5 * 10^4
    1 <= target[i] <= 10^9

  Hide Hint #1  
    Given that the sum is strictly increasing, the largest element in the target 
    must be formed in the last step by adding the total sum in the previous step. 
    Thus, we can simulate the process in a reversed way.

  Hide Hint #2  
    Subtract the largest with the rest of the array, and put the new element into the array. 
    Repeat until all elements become one
*/

class Solution 
{
public:
  bool isPossible(vector<int>& target) 
  {
    int i = 0;
    int maxi = INT_MIN;
    unordered_map<int, int> freq;
    for(int& n : target)
    {
      if(freq.count(n) > 0)
      {
        return false;
      }
      
      freq[n] = i;
      maxi = max(maxi, n);
      i++;
    }
    
    int l = target.size();
    
    int sum = l;
    int prev_sum = 0;
    vector<int> A(l, 1);
    
    while(sum <= maxi)
    {
      if(freq.count(sum) != 0)
      {
        A[freq[sum]] = sum;
      }
      else
      {
        if(l > 0)
        {
          A[l-1] = sum;
        }
      }
      
      l--;
      int temp = sum;
      sum += prev_sum + (l > 0 ? l : 0);
      
      prev_sum = temp;
    }
    
    return (A == target);
  }
};