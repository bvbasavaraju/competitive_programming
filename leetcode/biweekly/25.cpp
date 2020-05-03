/****************************************************
Date: May 2nd, 2020
Successful submissions : 1
Time expiration : 0
Not Solved : 2
Wrong Answer/ Partial result : 1

link: https://leetcode.com/contest/biweekly-contest-25
****************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;

/* 
  Q: 1431. Kids With the Greatest Number of Candies - Solved
*/
class Solution1_t
{
public:
  vector<bool> kidsWithCandies(vector<int>& c, int e) 
  {
    int m = *max_element(c.begin(), c.end());
    
    int l = c.size();
    vector<bool> ans(l, false);
    
    for(int i = 0; i < l; ++i)
    {
      if(c[i] + e >= m)
      {
        ans[i] = true;
      }
    }
    
    return ans;
  }
};

/* 
  Q: 1432. Max Difference You Can Get From Changing an Integer - wrong answer
*/
class Solution2_t
{
public:
  int maxDiff(int num) 
  {
    if(num <= 0)
    {
      return 0;
    }
    
    string n = std::to_string(num);
    string a = "";
    string b = "";
    
    if(n.size() == 1)
    {
      return 8;
    }
    else
    {
      a = n;
      b = n;
      char f = n[0];
      char s = n[1];
      
      if(f == '1')
      {
        for(char& ch : a)
        {
          if(ch == n[0])
            ch = '9';
        }
        
        for(char& ch : b)
        {
          if(ch == n[1])
          {
            if(n[0] != n[1])
              ch = '0';
            else
              ch = '1';
          }
        }
      }
      else if(f == '9')
      {
        for(char& ch : a)
        {
          if(ch == n[0])
            ch = '1';
        }
        
        for(char& ch : b)
        {
          if(ch == n[1])
            ch = '9';
        }
      }
      else
      {
        for(char& ch : a)
        {
          if(ch == n[0])
            ch = '9';
        }
        
        for(char& ch : b)
        {
          if(ch == n[0])
            ch = '1';
        } 
      }
    }
    
    return abs(stoi(a) - stoi(b));
  }
};
/* 
  Q: 1433. Check If a String Can Break Another String
*/
class Solution3_t
{
public:
  bool checkIfCanBreak(string s1, string s2) 
  {
      
  }
};

/* 
  Q: 1434. Number of Ways to Wear Different Hats to Each Other
*/
class Solution4_t
{
public:
  int numberWays(vector<vector<int>>& hats) 
  {
      
  }
};