/****************************************************
Date: Jan 9th, 2021
Successful submissions : 1
Time expiration : 1
Not Solved : 1
Wrong Answer/ Partial result : 1

link: https://leetcode.com/contest/biweekly-contest-43
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
  Q: 1716. Calculate Money in Leetcode Bank
*/
class Solution1_t
{
public:
  int totalMoney(int n) 
  {
    int weekNum = 0;
    vector<int> money(n, 0);
    
    int ans = 0;
    static const int WEEK_DAYS = 7;
    for(int i = 0; i < n; ++i)
    {
      if(i % 7 == 0)
      {
        weekNum++;
        money[i] = weekNum;
      }
      else
      {
        money[i] = money[i - 1] + 1;
      }
      
      ans += money[i];
    }
    
    return ans;
  }
};

/*
  Q: 1717. Maximum Score From Removing Substrings - time limit exceeded!
*/
class Solution2_t
{
private:
  void calculateGain(string s, int x, int y, int& sum)
  {
    if(x > y)
    {
      size_t pos = 0;
      do
      {
        while(pos != std::string::npos)
        {
          pos = s.find("ab", 0);
          if(pos != std::string::npos)
          {
            sum += x;
            s.erase(pos, 2);
          }
        }

        pos = s.find("ba", 0);
        if(pos != std::string::npos)
        {
          sum += y;
          s.erase(pos, 2);
        }
      } while(pos != std::string::npos);
    }
    else
    {
      size_t pos = 0;
      do
      {
        while(pos != std::string::npos)
        {
          pos = s.find("ba", 0);
          if(pos != std::string::npos)
          {
            sum += y;
            s.erase(pos, 2);
          }
        }

        pos = s.find("ab", 0);
        if(pos != std::string::npos)
        {
          sum += x;
          s.erase(pos, 2);
        }
      } while(pos != std::string::npos);
    }
  }
  
public:
  int maximumGain(string s, int x, int y) 
  {
    int ans = 0;
    calculateGain(s, x, y, ans);
    return ans;
  }
};

/*
  Q: 1718. Construct the Lexicographically Largest Valid Sequence - partial result
*/
class Solution3_t
{
private:
  bool canFitNum(int num, int l, bool& done, vector<int>& ans)
  {
    if(num == 1)
    {
      done = true;
      return true;
    }
    
    for(int i = 0; i<l ; ++i)
    {
      if((i + num) >= l)
      {
        return false;
      }
      
      if((ans[i] == 0) && (ans[i+num] == 0))
      {
        ans[i] = num;
        ans[i+num] = num;
      }
      else
      {
        continue;
      }
      
      if(!canFitNum(num-1, l, done, ans))
      {
        ans[i] = 0;
        ans[i+num] = 0;
      }
      
      if(done)
      {
        break;
      }
    }
    
    return true;
  }
  
public:
  vector<int> constructDistancedSequence(int n) 
  {
    int l = (n * 2) - 1;
    
    vector<int> ans(l, 0);    
    for(int i = 0; i < l; ++i)  
    {
      bool done = false;
      if(canFitNum(n, l, done, ans))
      {
        break;
      }
    }
    
    for(int& num : ans)
    {
      if(num == 0)
      {
        num = 1;
        break;
      }
    }
    
    return ans;
  }
};

/*
  Q: 1719. Number Of Ways To Reconstruct A Tree
*/
class Solution4_t 
{
public:
  int checkWays(vector<vector<int>>& pairs) 
  {
      
  }
};

