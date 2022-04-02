/****************************************************
Date: March 23rd

link: https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/591/week-4-march-22nd-march-28th/3681/
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
  Q: 3Sum With Multiplicity

  Given an integer array arr, and an integer target, return the number of tuples i, j, k such that i < j < k and arr[i] + arr[j] + arr[k] == target.
  As the answer can be very large, return it modulo 109 + 7.

  Example 1:
    Input: arr = [1,1,2,2,3,3,4,4,5,5], target = 8
    Output: 20
    Explanation: 
      Enumerating by the values (arr[i], arr[j], arr[k]):
        (1, 2, 5) occurs 8 times;
        (1, 3, 4) occurs 8 times;
        (2, 2, 4) occurs 2 times;
        (2, 3, 3) occurs 2 times.

  Example 2:
    Input: arr = [1,1,2,2,2,2], target = 5
    Output: 12
    Explanation: 
      arr[i] = 1, arr[j] = arr[k] = 2 occurs 12 times:
      We choose one 1 from [1,1] in 2 ways,
      and two 2s from [2,2,2,2] in 6 ways.

  Constraints:
    3 <= arr.length <= 3000
    0 <= arr[i] <= 100
    0 <= target <= 300
*/

class Solution 
{
public:
  int threeSumMulti(vector<int>& arr, int target) 
  {
    unordered_map<int, long> freq;
    for(int& a : arr)
    {
      freq[a]++;
    }
    
    long ans = 0;
    for(auto it1 : freq)
    {
      for(auto it2 : freq)
      {
        int i = it1.first;
        int j = it2.first;
        int k = target - i - j;
        
        if(freq.count(k) == 0)
        {
          continue;
        }
        
        if (i == j && j == k)
        {
          ans += freq[i] * (freq[i] - 1) * (freq[i] - 2) / 6;
        }
        else if (i == j && j != k)
        {
          ans += freq[i] * (freq[i] - 1) / 2 * freq[k];
        }
        else if (i < j && j < k)
        {
          ans += freq[i] * freq[j] * freq[k];
        }
      }
    }
    
    return ans % (int)(1e9 + 7);
  }
};