/****************************************************
Date: April 30th, 2022
Successful submissions : 2
Time expiration : 1 (it was solved. just needed another or loop!!)
Not Solved : 1
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/biweekly-contest-77
****************************************************/

#include <bits/stdc++.h>

using namespace std;

/*
  Q: 2255. Count Prefixes of a Given String
*/
class Solution1_t
{
public:
  int countPrefixes(vector<string>& words, string s) 
  {
    int ans = 0;
    for(string w : words)
    {
      if(w.size() > s.size())
      {
        continue;
      }
      
      string temp = s.substr(0, w.size());
      if(temp == w)
      {
        ans++;
      }
    }
    
    return ans;
  }
};

/*
  Q: 2256. Minimum Average Difference
*/
class Solution2_t
{
public:
  int minimumAverageDifference(vector<int>& nums) 
  {    
    long long sum = 0;
    for(int n : nums)
    {
      sum += n;
    }
    
    long long s = 0;
    pair<long long, int> ans = {INT_MAX, INT_MAX};
    int l = nums.size();
    for(int i = 0; i < l; ++i)
    {
      s += nums[i];
      long long first_avg = s / (i+1);
      long long second_avg = ((l - i - 1) > 0) ? ((sum - s)/(l - i - 1)) : (sum - s)/1;
      
      long long avg_diff = abs(first_avg - second_avg);
      if(avg_diff <= ans.first)
      {
        if(avg_diff != ans.first)
        {
          ans.second = i;
        }
        ans.first = avg_diff;
      }
    }
    
    return ans.second;
  }
};

/*
  Q: 2257. Count Unguarded Cells in the Grid - this was TLE - fix was very simple!!
*/
class Solution3_t
{
private:
  
  void calcGuardedCells(int m, int n, vector<int>& g, vector< vector<char> >& grid)
  {
    int r = g[0];
    int c = g[1];
    //right
    for(int i = c+1; i < n; ++i)
    {
      if(grid[r][i] == 'W' || grid[r][i] == 'G')
      {
        break;
      }
      
      grid[r][i] = 'g';
    }
    
    //left
    for(int  i = c-1; i >= 0; --i)
    {
      if(grid[r][i] == 'W' || grid[r][i] == 'G')
      {
        break;
      }
      
      grid[r][i] = 'g';
    }
    
    //down
    for(int i = r+1; i < m; ++i)
    {
      if(grid[i][c] == 'W' || grid[i][c] == 'G')
      {
        break;
      }
      
      grid[i][c] = 'g';
    }
    
    //up
    for(int i = r-1; i >= 0; --i)
    {
      if(grid[i][c] == 'W' || grid[i][c] == 'G')
      {
        break;
      }
      
      grid[i][c] = 'g';
    }
  }
  
public:
  int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) 
  {    
    vector< vector<char> > grid(m, vector<char>(n, 'p'));
    
    for(vector<int> w : walls)
    {
      grid[w[0]][w[1]] = 'W';
    }
    
    for(vector<int> g : guards)
    {
      grid[g[0]][g[1]] = 'G';
      // calcGuardedCells(m, n, g, grid);  // instead of calling from here!!, I needed to call from another for loop!! like below!!
    }

    // this for loop solved instead of keeping only 2 for loop!!
    for(vector<int> g : guards)
    {
      calcGuardedCells(m, n, g, grid);
    }
    
    int ans = 0;
    for(int i = 0; i < m; ++i)
    {
      for(int j = 0; j < n; ++j)
      {
        if(grid[i][j] == 'p')
        {
          ans++;
        }
      }
    }
    
    return ans;
  }
};

/*
  Q: 2258. Escape the Spreading Fire - not solved!!
*/
class Solution4_t
{
public:
  int maximumMinutes(vector<vector<int>>& grid) 
  {

  }
};