/****************************************************
Date: aug 30th, 2020
Successful submissions : 2
Time expiration : 0
Not Solved : 2
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/weekly-contest-204
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
  Q: 1566. Detect Pattern of Length M Repeated K or More Times  
*/
class Solution1_t
{
private:
  void getSubArr(vector<int>& arr, int i, int l, int m, vector<int>& sa)
  {
    for(int j = 0; j < m && (i+j < l); ++j)
    {
      sa.push_back(arr[i+j]);
    }
  }
  
  bool isPatternExists(vector<int>& arr, vector<int>& pattern, int sp, int l, int m, int k)
  {
    int count = 1;
    while(count < k)
    {
      vector<int> sa;
      for(int i = 0; i < m && i+sp < l; ++i)
      {
        sa.push_back(arr[i+sp]);
      }
      
      if(sa == pattern)
      {
        count++;
        sp += m;
      }
      else
      {
        break;
      }
      
      if(count == k)
      {
        return true;
      }
    }
    
    return false;
  }
  
public:
  bool containsPattern(vector<int>& arr, int m, int k) 
  {
    int l = arr.size();
    if(l < (m * k))
    {
      return false;
    }
    
    int count = 0;
    vector<int> pattern;
    for(int i = 0; i < l-m; ++i)
    {
      getSubArr(arr, i, l, m, pattern);
      if(isPatternExists(arr, pattern, i+m, l, m, k))
      {
        return true;
      }
      else
      {
        pattern.clear();
      }
    }
    
    return false;
  }
};

/*
  Q: 1567. Maximum Length of Subarray With Positive Product
*/
class Solution2_t
{
public:
  int getMaxLen(vector<int>& nums) 
  {
    int total_neg = 0;
    int first_neg_pos = -1;
    int zero_pos = -1;
    
    int ans = 0;
    int l = nums.size();
    for(int i = 0; i < l; ++i)
    {
      int n = nums[i];
      
      if(n < 0)
      {
        total_neg++;
        first_neg_pos = (first_neg_pos < 0) ? i : first_neg_pos;
      }
      if(n == 0)
      {
        total_neg = 0;
        zero_pos = i;
        first_neg_pos = -1;
      }
      else
      {
        if(total_neg%2 == 0)
        {
          ans = max(i-zero_pos, ans);
        }
        else
        {
          ans = max(i-first_neg_pos, ans);
        }
      }
    }
    
    return ans;
  }
};

/*
  Q: 1568. Minimum Number of Days to Disconnect Island
*/
class Solution3_t 
{
public:
    int minDays(vector<vector<int>>& grid) 
    {
        
    }
};

/*
  Q: 1569. Number of Ways to Reorder Array to Get Same BST
*/
class Solution4_t
{
public:
  int numOfWays(vector<int>& nums) 
  {
      
  }
};