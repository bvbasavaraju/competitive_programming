/****************************************************
Date: June 28th, 2020
Successful submissions : 1
Time expiration : 0
Not Solved : 3
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/weekly-contest-195
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
  Q: Path Crossing
*/
class Solution1_t
{
public:
  bool isPathCrossing(string path) 
  {
    set<pair<int, int>> visited;
    
    pair<int, int> p = make_pair(0, 0);
    visited.insert(p);
    
    int l = path.size();
    for(int i = 0; i < l; ++i)
    {
      switch(path[i])
      {
        case 'N':
          p = make_pair(p.first, p.second + 1);
          break;
          
        case 'E':
          p = make_pair(p.first + 1, p.second);
          break;
          
        case 'S':
          p = make_pair(p.first, p.second - 1);
          break;
          
        case 'W':
          p = make_pair(p.first - 1, p.second);
          break;
          
        default:
          break;
      }
      
      if(visited.find(p) != visited.end())
      {
        return true;
      }
      
      visited.insert(p);
    }
    
    return false;
  }
};

/*
  Q: Check If Array Pairs Are Divisible by k
*/
class Solution2_t
{
public:
  bool canArrange(vector<int>& arr, int k) 
  {
    int fact_count = 0;
    vector<int> nums;
    
    for(int n : arr)
    {
      if(abs(n) % k == 0)
      {
        fact_count++;
      }
      else
      {
        nums.push_back(n);
      }
    }
    
    if((fact_count % 2 != 0) || (nums.size() % 2 != 0))
    {
      return false;
    }
    
    sort(nums.begin(), nums.end());
    
    int l = nums.size()/2;
    nums.insert(nums.begin() + l, 0);
    for(int i = l; i > 0; --i)
    {
      if((nums[i-1] + nums[i+1]) % k != 0)
      {
        return false;
      }
    }
    
    return true;
  }
};

/*
  Q: Number of Subsequences That Satisfy the Given Sum Condition
*/
class Solution3_t
{
public:
  int numSubseq(vector<int>& nums, int target) 
  {
    
  }
};

/*
  Q: Max Value of Equation
*/
class Solution4_t
{
public:
  int findMaxValueOfEquation(vector<vector<int>>& points, int k) 
  {
      
  }
};