/****************************************************
Date: May 23rd, 2021
Successful submissions : 1
Time expiration : 1
Not Solved : 1
Wrong Answer/ Partial result : 1

note: 1 problem has been solved after looking at solution

link: https://leetcode.com/contest/weekly-contest-242
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
  Q: 1869. Longer Contiguous Segments of Ones than Zeros
*/

class Solution1_t
{
private:
  int getCount(string s, int ch)
  {
    int l = s.size();
    
    int count = 0;
    int c = count;
    for(int i = 0; i < l; ++i)
    {
      if(s[i] == ch)
      {
        c++;
      }
      else
      {
        c = 0;
      }
      
      count = max(c, count);
    }
    
    return count;
  }
public:
  bool checkZeroOnes(string s) 
  {
    return getCount(s, '1') > getCount(s, '0');
  }
};

/*
  Q: 1870. Minimum Speed to Arrive on Time - solved after looking at solution. Resulted in TLE first
*/
class Solution2_t
{
private:
  bool canReach(vector<int>& dist, double hour, int speed)
  {
    double time = 0;
    
    int l = dist.size();
    for(int  i = 0; i < l-1; ++i)
    {
      time += (dist[i] + speed - 1)/speed;
    }
    
    time += (dist[l-1] * 1.0) / speed;
    
    return time <= hour;
  }
public:
  int minSpeedOnTime(vector<int>& dist, double hour) 
  {
    int len = dist.size();

    if(hour < (double(len) - 1.0))
    {
      return -1;
    }
    
    int l = 1;
    int h = 1e7;

    while(l < h)
    {
      int m = l + (h-l)/2;
      
      if(canReach(dist, hour, m))
      {
        h = m;
      }
      else
      {
        l = m+1;
      }
    }

    return h;
  }
};

/*
  Q: 1871. Jump Game VII - wrong answer. Still need to fix it
*/

class Solution3_t
{
private:
  bool reachable(const string s, int l, int p, int mini, int maxi)
  {
//     if(p == l-1)
//     {
//       return true;
//     }
    
//     for(int i = p+mini; i <= min(p+maxi, l-1); ++i)
//     {
//       if(s[i] == '1')
//       {
//         continue;
//       }
      
//       if(reachable(s, l, i, mini, maxi))
//       {
//         return true;
//       }
//     }
    
//     return false;
    for(int i = p+mini; i <= min(p+maxi, l-1); ++i)
    {
      if(p == l-1)
      {
        return true;
      }
      
      if(s[i] == '1')
      {
        continue;
      }
      
      
    }
  }
    
public:
  bool canReach(string s, int minJump, int maxJump) 
  {
    int l = s.size();
    return reachable(s, l, 0, minJump, maxJump);
  }
};

/*
  Q: 1872. Stone Game VIII
*/
class Solution4_t
{
public:
  int stoneGameVIII(vector<int>& stones) 
  {
    
  }
};