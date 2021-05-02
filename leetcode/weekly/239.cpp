/****************************************************
Date: May 2nd, 2021
Successful submissions : 1
Time expiration : 0
Not Solved : 2
Wrong Answer/ Partial result : 1

link: https://leetcode.com/contest/weekly-contest-239
****************************************************/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using namespace std;

/*
  Q 1848. Minimum Distance to the Target Element
*/
class Solution1_t
{
public:
  int getMinDistance(vector<int>& nums, int target, int start) 
  {
    int l = nums.size();
    
    int ans = INT_MAX;
    for(int i = 0; i < l; ++i)
    {
      if(nums[i] == target)
      {
        ans = min(ans, abs(i-start));
      }
    }
    
    return ans;
  }
};

/*
  Q 1849. Splitting a String Into Descending Consecutive Values -  too many wrong answers! need to find better way to answer this
*/
class Solution2_t
{
private:
  bool isPowerOf10(long long num)
  {
    for(long long i = 10; i < INT_MAX; i *= 10)
    {
      if(num == i)
      {
        return true;
      }
    }

    return false;
  }

  bool isPossible(const string& s, int l, int win_len, long long mul10)
  {
    vector<long long> nums;
    for(int i = 0; i+win_len <= l; )
    {
      if(s[i] == '0')
      {
        i++;
        continue;
      }

      string n = s.substr(i, win_len);

      i += win_len;
      long long num = std::atoi(n.c_str());

      nums.push_back(num);

      if(nums.back() > 0 && isPowerOf10(nums.back()))
      {
        win_len--;
      }
    }
    
    l = nums.size();
    if(l <= 0)
    {
      return 0;
    }

    long long prev_num = nums[0];
    for(int i = 1; i < l; ++i)
    {
      if(nums[i] == 0)
      {
        continue;
      }

      if(prev_num <= nums[i] || (abs(prev_num - nums[i]) != 1))
      {
        return false;
      }

      prev_num = nums[i];
    }

    return true;
  }
public:
  bool splitString(string s) 
  {
    while(s.size() > 0 && s[0] == "0")
    {
      s = s.substr(1, s.size()-1);
    }

    int l = s.size();
    for(int i = 1; i < l/2; ++i)
    {
      if(isPossible(s, l, i)
      {
        return true;
      }
    }

    if(s[0] != '0' && l%2 == 0 && isPossible(s, l, l/2))
    {
      return true;
    }

    return false;
  }
};

/*
  Q 1850. Minimum Adjacent Swaps to Reach the Kth Smallest Number
*/
class Solution3_t
{
public:
  int getMinSwaps(string num, int k) 
  {

  }
};

/*
  Q 1851. Minimum Interval to Include Each Query
*/
class Solution4_t
{
public:
  vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) 
  {

  }
};