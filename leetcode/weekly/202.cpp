/****************************************************
Date: aug 16th, 2020
Successful submissions : 2
Time expiration : 0
Not Solved : 2
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/weekly-contest-201
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
  Q: 1550. Three Consecutive Odds
*/
class Solution1_t
{
public:
  bool threeConsecutiveOdds(vector<int>& arr) 
  {
    bool ans = false;
    int l = arr.size();
    for(int i = 0; i < l - 2; ++i)
    {
      if((arr[i] & 0x01) && (arr[i+1] & 0x01) && (arr[i+2] & 0x01))
      {
        ans = true;
        break;
      }
    }
    
    return ans;
  }
};

/* 
  Q: 1551. Minimum Operations to Make Array Equal
*/
class Solution2_t
{
public:
  int minOperations(int n) 
  {
    int l = n/2;
    
    int val = 1;
    int ans = 0;
    for(int i = 0; i < l; ++i)
    {
      ans += abs(n - val);
      val += 2;
    }
    
    return ans;
  }
};

/* 
  Q: 1552. Magnetic Force Between Two Balls
*/
class Solution3_t
{
private:
  bool calKeepMinBalls(vector<int>& pos, int min_gap, int balls_to_keep)
  {
    int count = 1;
    int p = pos[0];

    for(int i = 1; i < pos.size(); ++i)
    {
      if(abs(p - pos[i]) >= min_gap)
      {
        p = pos[i];
        count++;
        if(count == balls_to_keep)
        {
          return true;
        }
      }
    }

    return (count < balls_to_keep) ? false : true;
  }
  
public:
  int maxDistance(vector<int>& position, int m) 
  {
    sort(position.begin(), position.end());
    
    int lo = 0;
    int hi = position.back();
    int ans = 0;
    while(lo <= hi)
    {
      int mid = lo + (hi-lo)/2;
      
      if(calKeepMinBalls(position, mid, m))
      {
        ans = max(ans, mid);
        lo = mid + 1;
      }
      else
      {
        hi = mid - 1;
      }
    }
    
    return ans;
  }
};

/* 
  Q: 1553. Minimum Number of Days to Eat N Oranges - time limit exceeded
*/
class Solution4_t
{
public:
  int minDays(int n) 
  {
    vector<int> dp(n+1, 0);
    for(int i = 1; i <= n; ++i)
    {
      if(i%3 == 0)
      {
        dp[i] = min(dp[i-2*(i/3)]+1, dp[i-1]+1);
      }
      else if(i%2 == 0)
      {
        dp[i] = min(dp[i-(i/2)] + 1, dp[i-1] + 1);
      }      
      else
      {
        dp[i] = dp[i-1] + 1;
      }
    }
    
    return dp[n];
  }
};