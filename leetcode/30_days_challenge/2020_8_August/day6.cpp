/****************************************************
Date: July 6th

link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/549/week-1-august-1st-august-7th/3409/
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
  Q: Find All Duplicates in an Array

  Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
  Find all the elements that appear twice in this array.

  Could you do it without extra space and in O(n) runtime?
  Example:
    Input:
      [4,3,2,7,8,2,3,1]
    Output:
      [2,3]
*/

class Solution 
{
public:
  vector<int> findDuplicates(vector<int>& nums) 
  {
    //O(n) - time ans O(1) - space
    int l = nums.size();
    vector<int> ans(l, 0);
    for(auto n : nums)
    {
      ans[n-1]++;
    }
    
    int p = 0;
    for(int i = 0; i < l; ++i)
    {
      if(ans[i] == 2)
      {
        ans[i] = i + 1;
        swap(ans[i], ans[p]);
        p++;
      }
    }
    
    ans.resize(p);
    return ans;
    
    /* O(n) - Space and time complexity!!
    vector<int> ans;
    unordered_set<int> freq;
    for(auto n : nums)
    {
      if(freq.find(n) != freq.end())
      {
        ans.push_back(n);
      }
      else
      {
        freq.insert(n);
      }
    }
    
    return ans;*/
  }
};