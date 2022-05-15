/****************************************************
Date: May 15th, 2022
Successful submissions : 2
Time expiration : 0
Memory exhausted : 0
Not Solved : 1
Wrong Answer/ Partial result : 1

link: https://leetcode.com/contest/weekly-contest-293
****************************************************/

#include <bits/stdc++.h>
using namespace std;

/*
  Q: 2273. Find Resultant Array After Removing Anagrams
*/
class Solution1_t
{
public:
  vector<string> removeAnagrams(vector<string>& words) 
  {
    int l = words.size();
    
    vector<vector<int>> freq(l, vector<int>(26, 0));
    for(int i = 0; i < l; ++i)
    {
      const string& w = words[i];
      for(char ch : w)
      {
        freq[i][ch-'a']++;
      }
    }
    
    vector<string> ans;
    ans.push_back(words[0]);
    for(int i = 1; i < l; ++i)
    {
      if(freq[i-1] != freq[i])
      {
        ans.push_back(words[i]);
      }
    }
    
    return ans;
  }
};

/*
  Q: 2274. Maximum Consecutive Floors Without Special Floors
*/
class Solution2_t
{
public:
  int maxConsecutive(int bottom, int top, vector<int>& special) 
  {
    sort(special.begin(), special.end());
    
    int ans = INT_MIN;
    int prevFloor = bottom;
    int l = special.size();
    for(int i = 0; i < l; ++i)
    {
      int count = special[i] - prevFloor;
      ans = max(ans, count);
      
      prevFloor = special[i] + 1;
    }
    
    int count = top - special.back();
    ans = max(ans, count);
    
    return ans;
    
//     sort(special.begin(), special.end());
    
//     int count  = 0;
//     int ans = INT_MIN;
//     for(int i = bottom; i <= top; ++i)
//     {
//       auto it = lower_bound(special.begin(), special.end(), i);
//       if(it != special.end())
//       {
//         ans = max(ans, count);
//         count = 0;
//       }
//       else
//       {
//         count++;
//       }
//     }
    
//     if(count  > 0)
//     {
//       ans = max(ans, count);
//     }
    
//     return ans;
    
    
//     unordered_set<int> spl;
//     for(int s : special)
//     {
//       spl.insert(s);
//     }
    
//     int count  = 0;
//     int ans = INT_MIN;
//     for(int i = bottom; i <= top; ++i)
//     {
//       if(spl.find(i) != spl.end())
//       {
//         ans = max(ans, count);
//         count = 0;
//       }
//       else
//       {
//         count++;
//       }
//     }
    
//     if(count  > 0)
//     {
//       ans = max(ans, count);
//     }
    
//     return ans;
    
//     vector<int> floors(top+1, 0);
    
//     unordered_set<int> spl;
//     for(int s : special)
//     {
//       spl.insert(s);
//     }
    
//     for(int i = bottom; i <= top; ++i)
//     {
//       if(spl.find(i) != spl.end())
//       {
//         floors[i] = 2;
//       }
//       else
//       {
//         floors[i] = 1;
//       }
//     }
    
//     int count  = 0;
//     int ans = INT_MIN;
//     for(int i = bottom; i <= top; ++i)
//     {
//       if(floors[i] == 1)
//       {
//         count++;
//       }
//       else
//       {
//         ans = max(ans, count);
//         count = 0;
//       }
//     }
    
//     if(count  > 0)
//     {
//       ans = max(ans, count);
//     }
    
//     return ans;
  }
};

/*
  Q: 2275. Largest Combination With Bitwise AND Greater Than Zero - solved after looking into solution
*/
class Solution3_t 
{
//   int getMax(const vector<int>& candidates, int p, int mask, unordered_map<int, int>& dp)
//   {
//     if(p >= candidates.size())
//     {
//       return 0;
//     }

//     if(dp.find(candidates[p]) != dp.end())
//     {
//       return dp[candidates[p]];
//     }
    
//     int result = mask & candidates[p];
//     result = max(result, getMax(candidates, p+1, result, dp));
//     result = max(result, getMax(candidates, p+1, mask, dp));
//     dp[candidates[p]] = result;
    
//     return result;
//   }
  
  //   pair<int, int> getMax(const vector<int>& candidates, int p, int mask, int count, unordered_map<int, pair<int, int>>& dp)
  // {
  //   if(p >= candidates.size())
  //   {
  //     return {0, INT_MIN};
  //   }

  //   if(mask == 0)
  //   {
  //     return {0, INT_MIN};
  //   }
    
  //   if(dp.find(candidates[p]) != dp.end())
  //   {
  //     return dp[candidates[p]];
  //   }
    
  //   pair<int, int> result = {mask & candidates[p], count + 1};
    
  //   pair<int, int> resultIncl = getMax(candidates, p+1, result.first, count+1, dp);
  //   if(resultIncl.first >= result.first)
  //   {
  //     if(resultIncl.first == result.first)
  //     {
  //       result.second = max(result.second, resultIncl.second);
  //     }
  //     else
  //     {
  //       result = resultIncl;
  //     }
  //   }
    
  //   pair<int, int> resultExcl = getMax(candidates, p+1, mask, count, dp);
  //   if(resultExcl.first >= result.first)
  //   {
  //     if(resultExcl.first == result.first)
  //     {
  //       result.second = max(result.second, resultExcl.second);
  //     }
  //     else
  //     {
  //       result = resultExcl;
  //     }
  //   }
    
  //   dp[candidates[p]] = result;
    
  //   return result;
  // }
  
public:
  int largestCombination(vector<int>& candidates) 
  {
//     unordered_map<int, pair<int, int>> dp;
//     pair<int, int> ans = getMax(candidates, 0, 0xFFFFFFFF, 0, dp);
    
//     //std::cout << ans.first << std::endl;
//     return ans.second;
    
    int maxi = INT_MIN;
    for(int c : candidates)
    {
      maxi = max(maxi, c);
    }
    
    int ans = 0;
    for(int i = 1; i <= maxi; i<<=1)
    {
      int count = 0;
      for(int c : candidates)
      {
        if((i & c) > 0)
        {
          count++;
        }
      }
      
      ans = max(ans, count);
    }
    
    return ans;
  }
};

/*
  Q: 2276. Count Integers in Intervals
*/
class CountIntervals 
{
private:
   priority_queue<pair<int, int>> intervals;
public:
    CountIntervals() 
    {
        
    }
    
    void add(int left, int right) 
    {
      if(intervals.empty())
      {
        intervals.push_back()
      }
    }
    
    int count() {
        
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */