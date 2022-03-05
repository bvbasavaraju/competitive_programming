/****************************************************
Date: Jan 22nd, 2022
Successful submissions : 1
Time expiration : 0
Not Solved : 2
Wrong Answer/ Partial result : 1

link: https://leetcode.com/contest/biweekly-contest-70
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
  Q: 2144. Minimum Cost of Buying Candies With Discount
*/
class Solution1_t
{
public:
  int minimumCost(vector<int>& cost) 
  {
    int ans = 0;
    priority_queue<int> pq;
    
    for(int c : cost)
    {
      pq.push(c);
    }
    
    int count = 0;
    while(!pq.empty())
    {
      int c = pq.top();
      pq.pop();
      count++;
      ans += (count % 3 == 0) ? 0 : c;
    }
    
    return ans;
  }
};

/*
  Q: 2145. Count the Hidden Sequences
*/
class Solution2_t
{
private:
  bool isOutOfRange(int num, int lower, int upper)
  {
    return (num < lower || num > upper);
  }
  
public:
  int numberOfArrays(vector<int>& diffs, int lower, int upper) 
  {
    int mini = 1e6;
    int miniP = -1;
    
    int maxi = -1e6;
    int maxiP = -1;
    int l = diffs.size();
    for(int i = 0; i < l; ++i)
    {
      if(diffs[i] < mini)
      {
        mini = diffs[i];
        miniP = i;
      }
      
      if(diffs[i] > maxi)
      {
        maxi = diffs[i];
        maxiP = i;
      }
    }
    
    int startWith = lower;
    if(mini != maxi)
    {
      while(miniP >= 0)
      {
        startWith = startWith - diffs[miniP];
        miniP--;
      }
    }
        
    if(isOutOfRange(startWith, lower, upper))
    {
      return 0;
    }
    
    int ans = 0;
    for(int i = startWith; i <= upper; ++i)
    {
      int num = i;
      bool count = true;
      for(int d : diffs)
      {
        std::cout << num << " + " << d << " => ";
        num = num + d;
        std::cout << num << std::endl;
        if(isOutOfRange(num, lower, upper))
        {
          count = false;
          break;
        }
      }
      
      ans += count ? 1 : 0;
    }
    
    return ans;
  }
};

/*
  Q: 2146. K Highest Ranked Items Within a Price Range
*/
class Solution 
{
public:
  vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) 
  {
      
  }
};
/*
  Q: 2147. Number of Ways to Divide a Long Corridor
*/
class Solution4_t 
{
public:
  int numberOfWays(string corridor) 
  {
      
  }
};
