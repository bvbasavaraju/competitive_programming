/****************************************************
Date: June 27th, 2020
Successful submissions : 3
Time expiration : 0
Not Solved : 0
Wrong Answer/ Partial result : 1

link: https://leetcode.com/contest/biweekly-contest-29
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
#include <string_view>

using namespace std;

/*
  Q: 1491. Average Salary Excluding the Minimum and Maximum Salary
*/
class Solution1_t
{
public:
  double average(vector<int>& salary) 
  {
    int mini = INT_MAX;
    int maxi = INT_MIN;
    
    double sum = 0;
    
    for(int s : salary)
    {
      sum += static_cast<double>(s);
      mini = min(mini, s);
      maxi = max(maxi, s);
    }
    
    sum -= static_cast<double>(mini);
    sum -= static_cast<double>(maxi);
    
    return sum / static_cast<double>(salary.size() - 2);
  }
};

/*
  Q: 1492. The kth Factor of n
*/
class Solution2_t
{
public:
  int kthFactor(int n, int k) 
  {
    int factor_count = 0;
    for(int i = 1; i <= n; ++i)
    {
      if((n % i) == 0)
      {
        factor_count++;
        if(factor_count == k)
        {
          return i;
        }
      }
    }
    
    return -1;
  }
};

/*
  Q: 1493. Longest Subarray of 1's After Deleting One Element
*/
class Solution3_t
{
public:
  int longestSubarray(vector<int>& nums) 
  {
    int ones_cont = 0;
    int ones_gap = 0;
    
    int ans = INT_MIN;
    int zero_count = 0;

    for(int i = 0; i < nums.size(); ++i)
    {
      int n = nums[i];
      if(n == 1)
      {
        if(zero_count == 0)
        {
          ones_cont++;
        }
        
        ones_gap++;
      }
      else
      {
        if(ones_cont == 0 && ones_gap == 0)
        {
          continue;
        }
        
        zero_count++;
        if(zero_count > 1)
        {
          ones_gap -= ones_cont;
          ones_cont = ones_gap;
          
          zero_count--;
          
          if((i > 0) && (nums[i-1] == 0))
          {
            ans = max(ans, ones_gap);
            
            zero_count = 0;
            ones_cont = 0;
            ones_gap = 0;
          }
        }
      }
      
      ans = max(ans, ones_gap);
    }
    
    return ans == nums.size() ? ans - 1 : ((ans == INT_MIN) ? 0 : ans);
  }
};

/*
  Q: 1494. Parallel Courses II
*/
class Solution4_t
{
private:
  unordered_set<int> completed;
  unordered_map<int, vector<int>> dep;
  
  int getSemCount(int sub, int k)
  {
    if(completed.find(sub) != completed.end())
    {
      return 0;
    }
    
    if(dep.find(sub) == dep.end())
    {
      completed.insert(sub);
      return 0;
    }
    
    int ans = 0;
    for(int s : dep[sub])
    {
      ans += getSemCount(s, k);
    }
    
    ans += dep[sub].size() / k;
    
    if(dep[sub].size() % k != 0)
    {
      ans++;
    }
    
    completed.insert(sub);
    return ans;
  }
  
public:
  int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) 
  { 
    for(auto& d : dependencies)
    {
      dep[d[1]].push_back(d[0]);
    }
    
    int ans = 0;
    if(dep.size() == 0)
    {
      ans = n / 2;
      if(n % 2 != 0)
      {
        ans++;
      }
    }
    else
    {
      for(int i = 1; i <= n; ++i)
      {
        ans += getSemCount(i, k);
      }
      ans++;
    }
    
    return ans;
  }
};