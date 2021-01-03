/****************************************************
Date: Jan 2nd, 2021
Successful submissions : 1
Time expiration : 0
Not Solved : 2
Wrong Answer/ Partial result/solved after looking at solution : 1
link: https://leetcode.com/contest/weekly-contest-222
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
  Q: 1710. Maximum Units on a Truck
*/
class Solution1_t
{
public:
  int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) 
  {
    sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& t1, const vector<int>& t2) -> bool
         {
           if(t1[1] > t2[1])
           {
             return true;
           }
           else if(t1[1] == t2[1])
           {
             if(t1[0] <= t2[0])
             {
               return true;
             }
           }
           
           return false;
         }
        );
    
    int ans = 0;
    for(vector<int>& boxType : boxTypes)
    {
      int units = boxType[1];
      int boxCount = boxType[0];

      if(truckSize >= boxCount)
      {
        ans += (boxCount * units);
        truckSize -= boxCount;
      }
      else
      {
        ans += (truckSize * units);
        truckSize = 0;
      }

      if(truckSize == 0)
      {
        break;
      }
    }
    
    return ans;
  }
};

/*
  Q: 1711. Count Good Meals - initial approach was wrong. after looking at solution it has been solved
*/
class Solution2_t
{
public:
  int countPairs(vector<int>& del)
  {
    static const int MOD = 1e9 +7;
    
    unordered_map<int, long long> freq;
    for(long long num : del)
    {
      freq[num]++;
    }
    
    long long ans = 0;
    for(auto numFreq : freq)
    {
      for(int p = 0; p <= 21; ++p)
      {
        long long num2 = ((1 << p) - numFreq.first);
        
        if(freq.find(num2) == freq.end())
        {
          continue;
        }
        
        if(num2 == numFreq.first)
        {
          ans = ans + (numFreq.second * (numFreq.second - 1));
        }
        else
        {
          ans = ans + (numFreq.second * freq[num2]);
        }
      }
    }
    
    return (ans / 2) % MOD;
  }
};

/*
  Q: 1712. Ways to Split Array Into Three Subarrays
*/
class Solution 
{
public:
  int waysToSplit(vector<int>& nums) 
  {
      
  }
};

/*
  Q: 1713. Minimum Operations to Make a Subsequence
*/
class Solution 
{
public:
  int minOperations(vector<int>& target, vector<int>& arr) 
  {
      
  }
};