/****************************************************
Date: September 16th

https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/638/week-3-september-15th-september-21st/3978/
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
  Q: Intersection of Two Arrays II

  Given two integer arrays nums1 and nums2, return an array of their intersection. 
  Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

  Example 1:
    Input: nums1 = [1,2,2,1], nums2 = [2,2]
    Output: [2,2]

  Example 2:
    Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
    Output: [4,9]
    Explanation: [9,4] is also accepted.

  Constraints:
    1 <= nums1.length, nums2.length <= 1000
    0 <= nums1[i], nums2[i] <= 1000

  Follow up:
    What if the given array is already sorted? How would you optimize your algorithm?
    What if nums1's size is small compared to nums2's size? Which algorithm is better?
    What if elements of nums2 are stored on disk, and the memory is limited such that you cannot 
    load all elements into the memory at once?
*/
class Solution 
{
public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
  {
    vector<int>& larger = (nums1.size() >= nums2.size()) ? nums1 : nums2;
    vector<int>& smaller = (nums1.size() < nums2.size()) ? nums1 : nums2;
    
    unordered_map<int, int> freq;
    for(int n: larger)
    {
      freq[n]++;
    }
    
    vector<int> ans;
    for(int n : smaller)
    {
      if(freq[n] > 0)
      {
        ans.push_back(n);
        freq[n]--;
      }
    }
    
    return ans;
  }
};