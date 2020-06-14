/****************************************************
Date: June 14th, 2020
Successful submissions : 3
Time expiration : 1
Not Solved : 0
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/weekly-contest-193
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
  Q: 5453. Running Sum of 1d Array
*/
class Solution1_t
{
public:
  vector<int> runningSum(vector<int>& nums) 
  {
    int sum = 0;
    for(int& n : nums)
    {
      sum += n;
      n = sum;
    }
    
    return nums;
  }
};

/*
  Q: 5454. Least Number of Unique Integers after K Removals
*/
class Solution2_t
{
public:
  int findLeastNumOfUniqueInts(vector<int>& arr, int k) 
  {
    vector<int> nums;
    unordered_map<int, int> freq;
    for(auto n : arr)
    {
      freq[n]++;
      if(freq[n] == 1)
      {
        nums.push_back(n);
      }
    }
    
    sort(nums.begin(), nums.end(), [&freq](const int& n1, const int& n2) -> bool { return (freq[n1] < freq[n2]); } );
        
    int ans = nums.size();
    for(int i = 0; k > 0 && i < nums.size(); ++i)
    {
      if(freq[nums[i]] <= k)
      {
        ans--;
        k -= freq[nums[i]];
      }
      else
      {
        freq[nums[i]]--;
        k--;
      }
    }
    
    return ans;
  }
};

/*
  Q: 5455. Minimum Number of Days to Make m Bouquets - initial brut force approach was wrong. binary search approach used later!
*/
class Solution3_t
{
public:
  int minDays(vector<int>& bD, int m, int k) 
  {
    int l = bD.size();
    
    if(l < m * k)
    {
      return -1;
    }
    
    int lo = INT_MAX;
    int hi = INT_MIN;
    for(int n : bD)
    {
      lo = min(lo, n);
      hi = max(hi, n);
    }
    
    if( l == m * k)
    {
      return hi;
    }
    
    while(lo <= hi)
    {
      int mid = lo + (hi-lo)/2;
      
      //Check if by this day harvest is possible!
      int adj = 0;
      int count = 0;
      bool possible = false;
      for(auto n : bD)
      {
        adj = (n <= mid) ? adj + 1 : 0;
        if(adj == k)
        {
          adj = 0;
          count++;
        }
      }
      
      if(count >= m)
      {
        hi = mid - 1;
      }
      else
      {
        lo = mid + 1;
      }
    }
    
    return lo;
  }
};

/*
  Q: 5456. Kth Ancestor of a Tree Node - Time expired
*/
/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
class TreeAncestor 
{
private:
  int m;
  vector<int> p;
public:
  TreeAncestor(int n, vector<int>& parent) 
  {
    for(int i = 0; i < n; ++i)
    {
      p.push_back(parent[i]);
    }
    m = n - 1;
  }

  int getKthAncestor(int node, int k) 
  {
    if(node > m)
    {
      return -1;
    }
    
    int ans = p[node];
    k--;
    while(k > 0 && ans >= 0)
    {
      ans = p[ans];
      k--;
    }
    
    //printf("%d\n", ans);
    return ans;
  }
};