/****************************************************
Date: Mar 7th, 2021
Successful submissions : 2
Time expiration : 0
Not Solved : 3
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/weekly-contest-230
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
  Q: 1784. Check if Binary String Has at Most One Segment of Ones
*/
class Solution1_t
{
public:
  bool checkOnesSegment(string s) 
  {
    int l = s.size();
    
    int oneStart = -1;
    int oneEnd = -1;
    for(int i = 0; i < l; ++i)
    {
      if(s[i] == '1')
      {
        if(oneEnd >= 0)
        {
          return false;
        }
        
        oneStart = oneStart < 0 ? i : oneStart;
      }
      else
      {
        if(oneStart >= 0)
        {
          oneEnd = i-1;
        }
      }
    }
    
    return true;
  }
};

/*
  Q: 1785. Minimum Elements to Add to Form a Given Sum
*/
class Solution2_t
{
public:
  int minElements(vector<int>& nums, int limit, int goal) 
  {
    long long sum = 0;
    for(int n : nums)
    {
      sum += n;
    }
    
    long long target = abs(static_cast<long long>(goal) - sum);
    
    int ans = 0;
    if(abs(target) > limit)
    {
      ans = target / limit;
      target %= limit;
    }
    
    if(target != 0)
    {
      ans++;
    }
    
    return ans;
  }
};

/*
  Q: 1786. Number of Restricted Paths From First to Last Node
*/
class Solution3_t
{
public:
  int countRestrictedPaths(int n, vector<vector<int>>& edges) 
  {
      
  }
};

/*
  Q: 1787. Make the XOR of All Segments Equal to Zero - something is wrong here!! need to figure out!!
*/
class Solution4_t
{
public:
  int minChanges(vector<int>& nums, int k) 
  {
    int ans = 0;
    int l = nums.size();
    
    int i = 0; 
    int xored = 0;
    for(int j = 0; j < k - 1 && i < l; ++j)
    {
      xored ^= nums[i];
      i++;
    }
    
    for( ;i < l; ++i)
    {
      if(nums[i] != xored)
      {
        ans++;
        nums[i] = xored;
      }
      
      xored = 0;
      xored ^= nums[i+1-k];
    }
    
    std::cout << endl;
    for(int n : nums)
    {
      std::cout << n << " ";
    }
    
    return ans;
  }
};