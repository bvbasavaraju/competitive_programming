/****************************************************
Date: July 25, 2020
Successful submissions : 1
Time expiration : 0
Not Solved : 3
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/biweekly-contest-31
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

using namespace std;

/*
  Q: 1523. Count Odd Numbers in an Interval Range
*/
class Solution1_t
{
public:
  int countOdds(int low, int high) 
  {
    int ans = (high - low) / 2;
    return ((high % 2 != 0) || (low % 2 != 0)) ? ans + 1 : ans;
  }
};

/*
  Q: 1524. Number of Sub-arrays With Odd Sum
*/
class Solution2_t
{
public:
  int numOfSubarrays(vector<int>& arr) 
  {
    
  }
};

/*
  Q: 1525. Number of Good Ways to Split a String
*/
class Solution3_t
{
public:
    int numSplits(string s) 
    {
        
    }
};

/*
  Q: 1526. Minimum Number of Increments on Subarrays to Form a Target Array
*/
class Solution4_t
{
public:
  int minNumberOperations(vector<int>& target) 
  {
    int sPos = 0;
    int ePos = 0;
    
    bool increasingOrder = true;
    
    int ans = 0;
    int maxi = 0;
    int l = target.size();
    for(int i = 0; i < l; ++i)
    {
      
    }
    
    return ans;
  }
};