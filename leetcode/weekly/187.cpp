/****************************************************
Date: May 3rd, 2020
Successful submissions : 3
Time expiration : 0
Not Solved : 1
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/weekly-contest-187
****************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using namespace std;

/*
  Q: 1436. Destination City
*/
class Solution1_t
{
public:
  string destCity(vector<vector<string>>& paths) 
  {
    if(paths.empty())
    {
      return "";
    }
    
    unordered_set<string> source;
    for(vector<string>& s : paths)
    {
      source.insert(s[0]);
    }
    
    string dest = "";
    for(vector<string>& s : paths)
    {
      if(source.count(s[1]) == 0)
      {
        dest = s[1];
        break;
      }
    }
    
    return dest;
  }
};

/*
  Q: 1437. Check If All 1's Are at Least Length K Places Away
*/
class Solution2_t
{
public:
  bool kLengthApart(vector<int>& nums, int k) 
  {    
    int prev_one_pos = -1;
    int l = nums.size();
    for(int i = 0; i < l; ++i)
    {
      if(nums[i] == 1)
      {
        if(i > 0 && prev_one_pos >= 0 && (i - prev_one_pos - 1 < k))
        {
          return false;
        }
        else
        {
          prev_one_pos = i;
        }
      }
    }
    
    return true;
  }
};

/*
  Q: 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
*/

class Solution3_t
{
public:
  int longestSubarray(vector<int>& nums, int limit) 
  {
    int ans = 0;
    int start_pos = 0;
    int max_num = *min_element(nums.begin(), nums.end());
    int min_num = *max_element(nums.begin(), nums.end());
    
    int l = nums.size();
    if(l == 1)
    {
      return 1;
    }
    for(int i = 0; i < l; ++i)
    {
      min_num = min(min_num, nums[i]);
      max_num = max(max_num, nums[i]);
      
      while((start_pos < i) && abs(max_num - min_num) > limit)
      {
        if(nums[start_pos] == min_num)
        {
          min_num = *min_element(nums.begin() + start_pos + 1, nums.begin() + i);
        }
        
        if(nums[start_pos] == max_num)
        {
          max_num = *max_element(nums.begin() + start_pos + 1, nums.begin() + i); 
        }
        
        start_pos++;
      }
      
      if(start_pos < i)
      {
        ans = max(ans, i - start_pos + 1);
      }
    }
    
    return ans;
  }
};

/*
  Q: 1439. Find the Kth Smallest Sum of a Matrix With Sorted Rows
*/
class Solution4_t
{
public:
  int kthSmallest(vector<vector<int>>& mat, int k) 
  {
    if(mat.empty() || mat[0].empty())
    {
      return 0;
    }
    
    vector<int> sums;
    for()
  }
};