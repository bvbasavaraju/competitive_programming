/****************************************************
Date: May 9th, 2021
Successful submissions : 0
Time expiration : 0
Not Solved : 2
Wrong Answer/ Partial result : 1

note: Wrong answer solved. It was a simple mistake. after looking at discussion solved.
      first problem was also solved after looking at the discussion.

link: https://leetcode.com/contest/weekly-contest-240
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
  Q: 1854. Maximum Population Year - solved after looking at the solution
*/
class Solution1_t
{
public:
  int maximumPopulation(vector<vector<int>>& logs) 
  {
    vector<int> count(101, 0);
    
    for(vector<int>& l : logs)
    {
      for(int i = l[0]; i < l[1]; ++i)
      {
        count[i-1950]++;
      }
    }
    
    int ans = 0;
    int max_count = 0;
    for(int i = 0; i < 101; ++i)
    {
      if(max_count < count[i])
      {
        max_count = count[i];
        ans = i+1950;
      }
    }
    
    return ans;
  }
};

/*
  Q: 1855. Maximum Distance Between a Pair of Values
*/
class Solution2_t
{
private:
  int getIndex(const vector<int>& nums, int max)
  {
    int l = 0;
    int h = nums.size()-1;
    
    int ans = -1;
    while(l <= h)
    {
      int m = l + (h-l)/2;
      if(nums[m] > max)
      {
        l = m+1;
      }
      else
      {
        ans = m;
        h = m-1;
      }
    }
    
    return ans;
  }
public:
  int maxDistance(vector<int>& nums1, vector<int>& nums2) 
  {
    int ans = 0;
    int l = nums2.size();
    for(int i = l-1; i >= 0; --i)
    {
      int index = getIndex(nums1, nums2[i]);
      if((index >= 0) && (index <= i))
      {
        ans = max(ans, i - index);
      }
    }
    
    return ans;
  }
};

/*
  Q: 1856. Maximum Subarray Min-Product - not working. yet to complete
*/
class Solution 
{  
public:
  int maxSumMinProduct(vector<int>& nums) 
  {
    static const int MOD = 1e7 + 7;
    
    long sum = 0;
    long mini = INT_MAX;
    long sum_subArray = 0;
    
    long long ans = 1;
    for(int n : nums)
    {
      if(sum + n > n)
      {
        mini = min(mini, static_cast<long long>(n));
        sum += n;
        sum_subArray = sum;
      }
      else
      {
        mini = n;
        sum = n;
        sum_subArray = sum;
      }
      
      ans = min(ans, mini * sum);
      
      ans = (ans % MOD);
    }
    
    return ans;
  }
};

/*
  Q: 1857. Largest Color Value in a Directed Graph
*/
class Solution4_t
{
public:
  int largestPathValue(string colors, vector<vector<int>>& edges) 
  {
      
  }
};