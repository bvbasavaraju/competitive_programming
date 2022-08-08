/****************************************************
Date: August 7th, 2022
Successful submissions : 3
Time expiration : 0
Memory exhausted : 0
Not Solved : 0
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/weekly-contest-305
****************************************************/

#include<bits/stdc++.h>
using namespace std;

/*
  Q: 2367. Number of Arithmetic Triplets
*/
class Solution1_t
{
public:
  int arithmeticTriplets(vector<int>& nums, int diff) 
  {
    int l = nums.size();
    
    int ans = 0;
    for(int i = 0; i < l-1; ++i)
    {
      for(int j = i+1; j < l-1; ++j)
      {
        if(nums[j] - nums[i] != diff)
        {
          continue;
        }

        for(int k = j+1; k < l; ++k)
        {
          if(nums[k] - nums[j] == diff)
          {
            ans++;
          }
        }
      }
    }
    
    return ans;
  }
};

/*
  Q: 2368. Reachable Nodes With Restrictions
*/
class Solution2_t
{
private:
  void getCount(int node, int& ans, vector<vector<int>>& adjList, vector<bool>& visited, unordered_set<int>& notAllowed)
  {
    if(notAllowed.find(node) != notAllowed.end() || visited[node])
    {
      return;
    }
    
    ans++;
    visited[node] = true;
    for(int adjNode : adjList[node])
    {
      //std::cout << node << ":" << adjNode << std::endl;
      getCount(adjNode, ans, adjList, visited, notAllowed);
    }
  }
  
public:
  int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) 
  {
    unordered_set<int> notAllowed;
    for(int n : restricted)
    {
      notAllowed.insert(n);
    }
    
    vector<vector<int>> adjList(n);
    for(vector<int> e : edges)
    {
      adjList[e[0]].push_back(e[1]);
      adjList[e[1]].push_back(e[0]);
    }
    
    int ans = 0;
    vector<bool> visited(n);
    
    getCount(0, ans, adjList, visited, notAllowed);
    return ans;
  }
};

/*
  Q: 2369. Check if There is a Valid Partition For The Array
*/
class Solution3_t
{
private:
  bool isPartitionable(int p, int count, vector<int>& nums)
  {
    if(count == 2)
    {
      if(p > 0 && (nums[p-1] == nums[p]))
      {
        return true;
      }
      return false;
    }
    
    //count == 3
    if(p < 2)
    {
      return false;
    }
    
    int d1 = nums[p] - nums[p-1];
    int d2 = nums[p-1] - nums[p-2];
    
    return d1 != d2 ? false : (d1 == 0) || (d1 == 1);
  }
  
  bool isPossible(int p, vector<int>& nums, vector<int>& cache)
  {
    if(p < 0)
    {
      return true;
    }
    
    if(cache[p] != -1)
    {
      return cache[p] == 1 ? true : false;
    }
    
    int ans = isPartitionable(p, 2, nums);
    
    if(ans)
    {
      ans = isPossible(p-2, nums, cache);
    }
    
    if(!ans)
    {
      ans = isPartitionable(p, 3, nums);
      if(ans)
      {
        ans = isPossible(p-3, nums, cache);
      }
    }
    
    cache[p] = ans == true ? 1 : 0;
    return ans;
  }
public:
  bool validPartition(vector<int>& nums) 
  {
    int l = nums.size();
    vector<int> cache(l, -1);
    
    return isPossible(l-1, nums, cache);
  }
};

/*
  Q: 2370. Longest Ideal Subsequence - wrong answer!
*/
class Solution4_t
{
private:
  int getLCS(const string& s1, const string& s2, int p1, int p2, int k, vector<vector<int>>& cache)
  {
    if(p1 < 0 || p2 < 0)
    {
      return 0;
    }
    
    if(cache[p1][p2] != -1)
    {
      return cache[p1][p2];
    }
    
    //if(s1[p1] == s2[p2] || ((s2[p2] > s1[p1]) && (s2[p2] >= (s1[p1]+k))))
    //if(s1[p1] == s2[p2] || (abs(s2[p2] - s1[p1]) <= k))
    if(s1[p1] == s2[p2] || (abs(s2[p2] - s1[p1]) <= k))
    {
      cache[p1][p2] = 1+getLCS(s1, s2, p1-1, p2-1, k, cache);
    }
    else
    {
      cache[p1][p2] = max(getLCS(s1, s2, p1-1, p2, k, cache), getLCS(s1, s2, p1, p2-1, k, cache));
    }
    
    return cache[p1][p2];
  }
public:
  int longestIdealString(string s, int k) 
  {
    string s2 = s;
    int l = s.size();
    
    reverse(s2.begin(), s2.end());
    
//     vector<vector<int>> cache(l, vector<int>(l, -1));
    
//     return getLCS(s, s2, l-1, l-1, k, cache);
    
    int ans = 0;
    int count = 0;
    while(count < k)
    {
      char ch = s2[0];
      s2 = s2.substr(1);
      s2.push_back(ch);
      
      vector<vector<int>> cache(l+1, vector<int>(l+1, 0));
      for(int i = 0; i <= l; ++i)
      {
        for(int j = 0; j <= l; ++j)
        {
          if(i == 0 || j == 0)
          {
            continue;
          }

          if((s[i-1] == s2[j-1]) || (abs(s[i-1] - s2[j-1]) <= k))
          {
            cache[i][j] = 1 + cache[i-1][j-1];
          }
          else
          {
            cache[i][j] = max(cache[i-1][j], cache[i][j-1]);
          }
        }
      }

      count++;
      ans = max(ans, cache[l][l]);
    }
    return ans;
  }
};