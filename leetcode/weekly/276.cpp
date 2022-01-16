/****************************************************
Date: Jan 16, 2022
Successful submissions : 2
Time expiration : 
Not Solved : 1
Wrong Answer/ Partial result : 1

link: https://leetcode.com/contest/weekly-contest-276
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
  Q: 2138. Divide a String Into Groups of Size k
*/
class Solution1_t
{
public:
  vector<string> divideString(string s, int k, char fill) 
  {
    int l = s.size();
    
    int rem = l % k;
    if(rem > 0)
    {
      for(int i = 0; i < k - rem; ++i)
      {
        s += fill;
      }
    }
    l = s.size();
    
    int p = 0;
    vector<string> ans;
    for(int i = 0; i < l/k; ++i)
    {
      string str = s.substr(p, k);
      ans.push_back(str);
      
      p += k;
    }
    
    return ans;
  }
};


/*
  Q: 2139. Minimum Moves to Reach Target Score
*/
class Solution2_t
{
public:
  int minMoves(int target, int maxDoubles) 
  {
    int ans = 0;
    while((maxDoubles > 0) && (target > 1))
    {
      if(target & 0x01)
      {
        target -= 1;
      }
      else
      {
        maxDoubles--;
        target >>= 1;
      }
      
      ans++;
    }
    
    if(target > 1)
    {
      target--;
      ans += target;
    }
    
    return ans;
  }
};

/*
  Q: 2140. Solving Questions With Brainpower
*/
class Solution 
{
public:
  long long mostPoints(vector<vector<int>>& questions) 
  {
    //Below answer was working if I do not skip
    int l = questions.size();
    //vector<vector<long long>> points(l, vector<long long>(l, 0));
    
    long long ans = 0;
    for(int i = 0; i < l; ++i)
    {
      long long sum = 0;
      for(int j = i; j < l;)
      {
        sum += questions[j][0];
        //points[i][j] = questions[j][0];
        j += questions[j][1] + 1;
      }
      
      ans = max(ans, sum);
    }
    
    return ans;
  }
};

/*
  2141. Maximum Running Time of N Computers
*/
class Solution4_t
{
public:
  long long maxRunTime(int n, vector<int>& batteries) 
  {
      
  }
};