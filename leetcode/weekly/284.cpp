/****************************************************
Date: Mar 13th, 2022
Successful submissions : 2
Time expiration : 0
Memory exhausted : 1
Not Solved : 1
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/weekly-contest-284
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
#include <limits.h>

using namespace std;
/*
  Q: 2200. Find All K-Distant Indices in an Array
*/
class Solution1_t
{
public:
  vector<int> findKDistantIndices(vector<int>& nums, int key, int k) 
  {
    int l = nums.size();
    
    vector<int> key_idxs;
    for(int i = 0; i < l; ++i)
    {
      if(nums[i] == key)
      {
        key_idxs.push_back(i);
      }
    }
    
    vector<bool> idxs(l, false);
    for(int idx : key_idxs)
    {      
      for(int i = 0; i < l; ++i)
      {
        if(abs(i-idx) <= k)
        {
          idxs[i] = true;
        }
      }
    }
    
    vector<int> ans;
    for(int i = 0; i < l; ++i)
    {
      if(idxs[i] == true)
      {
        ans.push_back(i);
      }
    }
    
    return ans;
  }
};

/*
  Q: 2201. Count Artifacts That Can Be Extracted - memory exhausted at first due to silly mistake of grid size!!. then resolved it!!
*/
class Solution2_t
{
public:
  int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) 
  {    
    vector< vector<int> > grid(n, vector<int>(n, 0)); // here instead of taking as n, I took min(n*n, 100000)
    
    for(vector<int>& d : dig)
    {
      grid[d[0]][d[1]] = 1;
    }
    
    int ans = 0;
    for(vector<int> a : artifacts)
    {
      bool canExtract = true;
      for(int i = a[0]; i <= a[2] && canExtract; ++i)
      {
        for(int j = a[1]; j <= a[3]; ++j)
        {
          if(grid[i][j] == 0)
          {
            canExtract = false;
            break;
          }
        }
      }
      
      if(canExtract)
      {
        ans++;
      }
    }
    
    return ans;
  }
};

/*
  Q: 2202. Maximize the Topmost Element After K Moves
*/
class Solution3_t
{
public:
  int maximumTop(vector<int>& nums, int k) 
  {
    int l = nums.size();
    if((l <= 1) && (k%2 != 0))
    {
      return -1;
    }
    
    if(k == 0)
    {
      return nums[0];
    }
    
    priority_queue<int> pq;
    
    int range_ = min(l, k-1);
    for(int i = 0; i < range_; ++i)
    {
      pq.push(nums[i]);
    }
    
    int ans = pq.empty() ? -1 : pq.top();
    if((ans > 0) && (k < l))
    {
      ans = max(ans, nums[k]);
    }
    if((l > 1) && (k <= 1))
    {
      ans = max(ans, nums[k]);
    }
    
    return ans;
  }
};

/*
  Q: 2203. Minimum Weighted Subgraph With the Required Paths
*/
class Solution4_t
{
public:
  long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) 
  {
      
  }
};