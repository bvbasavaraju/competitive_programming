/****************************************************
Date: May 22nd, 2022
Successful submissions : 1
Time expiration : 0
Memory exhausted : 0
Not Solved : 1
Wrong Answer/ Partial result : 2

link: https://leetcode.com/contest/weekly-contest-294
****************************************************/

#include <bits/stdc++.h>
using namespace std;

/*
  Q: 2278. Percentage of Letter in String
*/
class Solution1_t
{
public:
  int percentageLetter(string s, char letter) 
  {
    int count = 0;
    
    for(char ch : s)
    {
      if(letter == ch)
      {
        count++;
      }
    }
    
    int ans = (static_cast<float>(count)/static_cast<float>(s.size())) * 1000;
    
    return  ans/10;
  }
};

/*
  Q: 2279. Maximum Bags With Full Capacity of Rocks - Surprisingly DP did not work!!
*/
class Solution 
{
public:
  int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) 
  {
    int l = capacity.size();
    
    vector<int> diffs;
    for(int i = 0; i < l; ++i)
    {
      diffs.push_back(capacity[i] - rocks[i]);
    }
    
    sort(diffs.begin(), diffs.end());
    
    int ans = 0;
    for(int i = 0; i < l; ++i)
    {
      if(diffs[i] == 0)
      {
        ans++;
      }
      else
      {
        if(diffs[i] <= additionalRocks)
        {
          ans++;
          additionalRocks -= diffs[i];
        }
      }
    }
    
    return ans;
    
    
//    Surprisingly DP did not work here!!
//     int l = capacity.size();
//     vector<vector<int>> dp(l+1, vector<int>(additionalRocks+1, 0));
    
//     for(int i = 0; i <= l; ++i)
//     {
//       for(int j = 0; j <= additionalRocks; ++j)
//       {
//         if(i == 0 || j == 0)
//         {
//           continue;
//         }
        
//         int diff = capacity[i-1] - rocks[i-1];
        
//         if(diff <= j)
//         {
//           dp[i][j] = max(1+dp[i-1][j-diff], dp[i-1][j]);
//         }
//         else
//         {
//           dp[i][j] = dp[i-1][j];
//         }
//       }
//     }
    
//     return dp[l][additionalRocks];
  }
};

/*
  Q: 2280. Minimum Lines to Represent a Line Chart - after looking at the solution!
*/
class Solution3_t
{
public:
  int minimumLines(vector<vector<int>>& sp) 
  {
    sort(sp.begin(), sp.end());
    
    int ans = 0;
    int l = sp.size();
    
    int slope = 0;
    int xDelta = INT_MAX;
    int yDelta = INT_MAX;
    for(int i = 1; i < l; ++i)
    {
      int xDiff = (sp[i][0] - sp[i-1][0]);
      int yDiff = (sp[i][1] - sp[i-1][1]);
      
      int gcd_ = gcd(xDiff, yDiff);
      
      if((xDelta != xDiff/gcd_) || (yDelta != yDiff/gcd_))
      {
        ans++;
      }
      
      xDelta = xDiff/gcd_;
      yDelta = yDiff/gcd_;
      
      // if((yDiff == 0))
      // {
      //   if(slope != INT_MAX)
      //   {
      //     slope = INT_MAX;
      //     ans++;
      //   }
      // }
      // else if(slope != (xDiff/yDiff))
      // {
      //   slope = xDiff/yDiff;
      //   ans++;
      // }
    }
    
    return ans;
  }
};

/*
  Q: 2281. Sum of Total Strength of Wizards - yet to complete
*/
class Solution4_t
{
public:
  int totalStrength(vector<int>& strength) 
  {
    int l = strength.size();
    
    const int MOD = 1e9 + 7;
    
    int ans = 0;
    int windowSize = 1;
    unodered_map<int, pair<int, int>> data;
    
    for(int i = 0; i < l; ++i)
    {
      int sum += strength[i];
      
    }
  }
};
