/****************************************************
Date: July 17th

link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/546/week-3-july-15th-july-21st/3393/
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
  Q: Top K Frequent Elements

  Given a non-empty array of integers, return the k most frequent elements.

  Example 1:
    Input: nums = [1,1,1,2,2,3], k = 2
    Output: [1,2]
  
  Example 2:
    Input: nums = [1], k = 1
    Output: [1]
  
  Note:
    You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
    Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
    It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
    You can return the answer in any order.
*/
class Solution 
{
public:
  vector<int> topKFrequent(vector<int>& nums, int k) 
  {
    unordered_map<int, int> freq;
    
    for(int n : nums)
    {
      freq[n]++;
    }
    
    priority_queue<pair<int, int>> pq;
    for(auto f : freq)
    {
      pq.push(make_pair(f.second, f.first));
    }
    
    vector<int> ans;
    while(k > 0)
    {
      ans.push_back(pq.top().second);
      pq.pop();
      k--;
    }
    
    return ans;
  }
};