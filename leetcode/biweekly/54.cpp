/****************************************************
Date: June 12th, 2021
Successful submissions : 2
Time expiration : 0
Not Solved : 2
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/biweekly-contest-54
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
  Q: 1893. Check if All the Integers in a Range Are Covered
*/
class Solution1_t
{
public:
  bool isCovered(vector<vector<int>>& ranges, int left, int right) 
  {    
    for(int i = left; i <= right; ++i)
    {
      bool inRange = false;
      for(vector<int>& r : ranges)
      {
        if((r[0] <= i) && (r[1] >= i))
        {
          inRange = true;
          break;
        }
      }
      
      if(!inRange)
      {
        return false;
      }
    }
    
    return true;
  }
};

/*
  Q: 1894. Find the Student that Will Replace the Chalk
*/
class Solution2_t
{
public:
  int chalkReplacer(vector<int>& chalk, int k) 
  {
    long long sum = 0;
    for(int c : chalk)
    {
      sum += c;
    }
    
    k = k % sum;
    
    int ans = 0;
    while(k > 0)
    {
      k -= chalk[ans];
      if(k >= 0)
      {
        ans++;
      }
    }
    
    return ans;
  }
};

/*
  Q: 1895. Largest Magic Square - yet to solve!!
*/

class Solution3_t
{
public:
  int largestMagicSquare(vector<vector<int>>& grid) 
  {
    int r = grid.size();
    int c = grid[0].size();
    
    int ans = 1;
    for(int k = 2; k <= min(r, c); ++k)
    {
      vector<long long> r_sum(k, 0);
      vector<long long> c_sum(k, 0);
      
      for()
      
      ans = max(ans, k);
      if(ans == k)
      {
        break;
      }
    }
    
    return ans;
    
    
  }
};

/*
  Q: 1896. Minimum Cost to Change the Final Value of Expression
*/

class Solution4_t
{
public:
  int minOperationsToFlip(string expression) 
  {

  }
};