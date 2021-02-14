/****************************************************
Date: Feb 14th, 2021
Successful submissions : 1
Time expiration : 1
Not Solved : 2
Wrong Answer/ Partial result : 1  //this was corrected after looking at the discussion

link: https://leetcode.com/contest/weekly-contest-228
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
  Q: 1758. Minimum Changes To Make Alternating Binary String - Looked for the solution!!
*/
class Solution1_t
{
public:
  int minOperations(string s) 
  {
    int f0 = '1';
    int f1 = '0';
    
    int sum0 = 0;
    int sum1 = 0;
    for(int ch : s)
    {
      sum0 += (ch != f0);
      sum1 += (ch != f1);
      
      swap(f0, f1);
    }
    
    return min(sum0, sum1);
  }
};

/*
  Q: 1759. Count Number of Homogenous Substrings - solved
*/
class Solution2_t
{
private:
  
  long long getSum(unordered_map<int, int>& sum, int val, const int& MOD)
  {
    if(val <= 0)
    {
      return 0;
    }
    
    if(sum.count(val) != 0)
    {
      return sum[val];
    }
    
    long long s = static_cast<long long>(val) % MOD + (getSum(sum, val-1, MOD)) % MOD;
    sum[val] = static_cast<int>(s);
    
    return s;
  }

public:
  int countHomogenous(string s) 
  {
    static const int MOD = 1e9 + 7;
    
    int l = s.size();
    
    long long ans = 0;
    int count = 1;
    int prev = s[0];
    unordered_map<int, int> sum;
    // sum[0] = 0;
    // sum[1] = 1;
    
    for(int i = 1; i < l; ++i)
    {
      if(prev == s[i])
      {
        count++;
      }
      else
      {        
        ans = (ans + ((getSum(sum, count, MOD)) % MOD)) % MOD;
        
        prev = s[i];
        count = 1;
      }
    }
    
    if(count > 0)
    {
      ans = (ans + ((getSum(sum, count, MOD)) % MOD)) % MOD;
    }
    
    return static_cast<int>(ans);
  }
};

/*
  Q: 1760. Minimum Limit of Balls in a Bag - nteresting problem! - could not solve
*/
class Solution3_t
{
public:
  int minimumSize(vector<int>& nums, int maxOperations) 
  {
    priority_queue<int> pq;
    for(int n : nums)
    {
      pq.push_back();
    }
  }
};

/*
  Q: 1761. Minimum Degree of a Connected Trio in a Graph - tme limit exceeded. Looking at the discussion. resolved the issue.
  Note: Vector is much faster than unordered_set or unordered_map
*/
class Solution 
{
public:
  int minTrioDegree(int n, vector<vector<int>>& edges) 
  {
    vector<int> conns(n+1, 0);
    vector<vector<int>> adj(n+1, vector<int>(n+1, 0));
    
    for(vector<int>& e : edges)
    {
      conns[e[0]]++;
      conns[e[1]]++;
      adj[e[0]][e[1]] = 1;
      adj[e[1]][e[0]] = 1;
    }
    
    int ans = INT_MAX;
    
    for(int i = 1; i <= n; ++i)
    {
      if(conns[i] < 2)
      {
        continue;
      }
      
      for(int j = i+1; j <= n; ++j)
      {
        if((conns[j] < 2) || (adj[i][j] == 0))
        {
          continue;
        }
        
        for(int k = j+1; k <= n; ++k)
        {
          if(conns[k] < 2)
          {
            continue;
          }
          
          if(adj[i][j] && adj[j][k] && adj[k][i])
          {
            ans = min(ans, (conns[i] - 2) + (conns[j] - 2) + (conns[k] - 2));
          }
        }
      }
    }
    
    return (ans == INT_MAX) ? -1  : ans;
  }
};