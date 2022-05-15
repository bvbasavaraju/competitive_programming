/****************************************************
Date: May 14th, 2022
Successful submissions : 2
Time expiration : 0
Memory limit exceeded : 1
Not Solved : 1
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/biweekly-contest-78
****************************************************/

#include <bits/stdc++.h>
using namespace std;

/*
  Q: 2269. Find the K-Beauty of a Number
*/
class Solution1_t
{
private:
  int getNum(string num)
  {
    int ans = 0;
    for(char ch : num)
    {
      ans = (ans * 10) + (ch - '0');
    }
    
    return ans;
  }
public:
  int divisorSubstrings(int num, int k) 
  {
    string numS = std::to_string(num);
    
    int ans = 0;
    
    int p = 0;
    string d = numS.substr(p, k);
    while(d.size() == k)
    {
      int div = getNum(d);
      if(div != 0 && (num % div == 0))
      {
        ans++;
      }
      
      p++;
      d = numS.substr(p, k);
    }
    
    return ans;
  }
};

/*
  Q: 2270. Number of Ways to Split Array
*/
class Solution2_t
{
public:
  int waysToSplitArray(vector<int>& nums) 
  {
    long long sum = 0;
    for(int n : nums)
    {
      sum += n;
    }
    
    int ans = 0;
    long long ls = 0;
    int l = nums.size();
    for(int i = 0; i < l-1; ++i)
    {
      ls += nums[i];
      sum -= nums[i];
      
      if(ls >= sum)
      {
        ans++;
      }
    }
    
    return ans;
  }
};

/*
  Q: 2271. Maximum White Tiles Covered by a Carpet - memory limit exceeded
*/
class Solution3_t
{
public:
  int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) 
  {
    sort(tiles.begin(), tiles.end());

    int l = tiles.size();
    vector<int> count(l, 0);
    for(int i = 0; i < l; ++i)
    {
      count[i] = tiles[i][1] - tiles[i][0] + 1;
      if(i > 0)
      {
        count[i] += count[i-1];
      }
    }
    
    if(carpetLen >= tiles.back()[1])
    {
      return count.back();
    }
    
    int ans = INT_MIN;
    for(int i = 0; i < carpetLen; ++i)
    {
      // TODO:
    }

    //Below code works but memory limit exceeded!!
//    sort(tiles.begin(), tiles.end());

//    int l = tiles.size();
//     vector<int> count(tiles.back()[1], 0);
//     for(int p = 0; p < l; ++p)
//     {
//       vector<int>& t = tiles[p];
//       int i = t[0]-1;
//       for(; i < t[1]; ++i)
//       {
//         count[i] = 1 + ((i > 0) ? count[i-1] : 0);
//       }

//       if(p != l-1)
//       {
//         for(; i < tiles[p+1][0]; ++i)
//         {
//           count[i] = count[i-1];
//         }
//       }
//     }

//     l = count.size();
//     int ans = (carpetLen > l) ? count.back() : count[carpetLen-1];
//     for(int i = carpetLen; i < l; ++i)
//     {
//       ans = max(ans, count[i] - count[i-carpetLen]);
//     }
    
//     return ans;
  }
};

/*
  Q: 2272. Substring With Largest Variance
*/
class Solution4_t 
{
public:
  int largestVariance(string s) 
  {
      
  }
};