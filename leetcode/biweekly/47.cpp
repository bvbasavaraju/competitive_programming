/****************************************************
Date: March 6th, 2021
Successful submissions : 3 (2 solved after understanding)
Time expiration : 0
Not Solved : 1
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/biweekly-contest-47
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
  Q: 1779. Find Nearest Point That Has the Same X or Y Coordinate - Question was not clear to me at the beggining!!
*/
class Solution1_t
{
public:
  int nearestValidPoint(int x, int y, vector<vector<int>>& points) 
  {
    int minDist = INT_MAX;
    
    for(vector<int>& p : points)
    {
      if((p[0] == x) || (p[1] == y))
      {
        int dist = abs(x-p[0]) + abs(y-p[1]);
        
        minDist = min(minDist, dist);
      }
    }
    
    int i = 0;
    for(vector<int>& p : points)
    {
      if(((p[0] == x) || (p[1] == y)) && (abs(x-p[0]) + abs(y-p[1]) == minDist))
      {
        return i++;
      }
      
      i++;
    }
    
    return -1;
  }
};

/*
  Q: 1780. Check if Number is a Sum of Powers of Three
*/
class Solution2_t
{
private:
  bool targetReachable(vector<long long>& vals, int i, long long sum, int target)
  {
    if(i >= vals.size() || (sum > target))
    {
      return false;
    }
    
    if(target == sum)
    {
      return true;
    }
    
    if(targetReachable(vals, i+1, sum, target))
    {
      return true;
    }
    else
    {
      if(targetReachable(vals, i+1, sum+vals[i], target))
      {
        return true;
      }
    }
    
    return false;
  }
    
public:
  bool checkPowersOfThree(int n) 
  {
    vector<long long> threePow(20, 0);
    
    threePow[0] = 1;
    for(int i = 1; i < 20; ++i)
    {
      threePow[i] = threePow[i-1] * 3;
    }
    
    return targetReachable(threePow, 0, 0, n);
  }
};

/*
  Q: 1781. Sum of Beauty of All Substrings - forgot to get the substrng!!
*/
class Solution3_t
{
private:
  bool getMaxAndMin(vector<int>& freq, int& maxi, int& mini)
  {
    bool calc = false;
    for(int v : freq)
    {
      if(v > 0)
      {
        calc = true;
        maxi = max(maxi, v);
        mini = min(mini, v);
      }
    }
    
    return calc;
  }
  
public:
  int beautySum(string s) 
  {
    int ans = 0;
    int l = s.size();
    for(int i = 0; i < l-1; ++i)
    {
      vector<int> freq(26, 0);
      
      freq[s[i]-'a']++;
      
      for(int j = i+1; j < l; ++j)
      {
        freq[s[j]-'a']++;

        int maxi = INT_MIN;
        int mini = INT_MAX;
        if(getMaxAndMin(freq, maxi, mini))
        {
          ans += abs(maxi - mini);
        }
      }
    }
    
    return ans;
  }
};

/*
  Q: 1782. Count Pairs Of Nodes
*/
class Solution4_t
{
public:
  vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) 
  {
      
  }
};