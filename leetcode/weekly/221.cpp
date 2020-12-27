/****************************************************
Date: Dec 27th, 2020
Successful submissions : 1
Time expiration : 0
Not Solved : 2
Wrong Answer/ Partial result/solved after looking at solution : 1
link: https://leetcode.com/contest/weekly-contest-221
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
  Q: 1704. Determine if String Halves Are Alike
*/
class Solution1_t
{
public:
  bool halvesAreAlike(string s) 
  {
    int l = s.size() / 2;
    string a = s.substr(0, l);
    string b = s.substr(l, l);
    
    unordered_map<int, int> a_count;
    unordered_map<int, int> b_count;
    for(int i = 0; i < l; ++i)
    {
      a_count[a[i]]++;
      b_count[b[i]]++;
    }
    
    string ovals = "aeiouAEIOU";
    
    int a_oval_count = 0;
    int b_oval_count = 0;
    for(int ch : ovals)
    {
      a_oval_count += a_count[ch];
      b_oval_count += b_count[ch];
    }
    
    return (a_oval_count == b_oval_count);
  }
};

/*
  Q: 1705. Maximum Number of Eaten Apples - wrong answer
*/
class Solution2_t
{
private:
    class AppleT
    {
      private:
        int count;
        int life;
        int grownOnDay;
        int rottenDay;
        int numOfDays;
      public:
        AppleT(int count_, int life_, int grownOnDay_)
          : count(count_),
            life(life_),
            grownOnDay(grownOnDay_),
            rottenDay(0),
            numOfDays(0)
        {
          rottenDay = grownOnDay + life;
        }
      
        bool canPickApple(int pickDay)
        {
          return (pickDay >= grownOnDay);
        }
      
        int getCount(int pickDay)
        {
          if(pickDay >= rottenDay)
          {
            return 0;
          }
          
          count = min(0, count - (pickDay - grownOnDay));
          
          if(count == 0)
          {
            return 0;
          }
          
          int retVal = count;
          numOfDays = count;
          count = 0;
          
          return retVal;
        }
      
       int numOfDaysToEat(void)
       {
         return numOfDays;
       }
    };
  
  int getMaxCount(long long startDay, long long pickDay, vector<AppleT>& apples, long long& numOfDays)
  {
    if(pickDay > apples.size())
    {
      return 0;
    }
    
    long long count = 0;
    while(startDay <= pickDay)
    {
      long long count_ = apples[startDay-1].getCount(pickDay);
      long long numOfDays_ = apples[startDay-1].numOfDaysToEat();
      if((count_ > count) || ((count_ == count) && (numOfDays_ < numOfDays)))
      {
        count = count_;
        numOfDays = numOfDays_;
      }
      
      startDay++;
    }
    
    return count;
  }
  
public:
  int eatenApples(vector<int>& apples, vector<int>& days) 
  {
    int l = apples.size();
    
    unordered_map<int, int> apple_days_map;
    for(int i = 0; i < l; ++i)
    {
      
    }
    /*vector<AppleT> appleObjs;
    for(int i = 0; i < l; ++i)
    {
      AppleT a(apples[i], days[i], i+1);
      appleObjs.push_back(a);
    }
    
    int ans = 0;
    
    long long day = 1;
    long long int linearDayCount = 1;
    while(day <= l)
    {
      long long numOfDays = 1;
      ans += getMaxCount(linearDayCount, day, appleObjs, numOfDays);
      
      linearDayCount++;
      if(numOfDays <= 0)
      {
        day++;
        linearDayCount++;
      }
      else
      {
        day += numOfDays;
        linearDayCount+= numOfDays;
      }      
    }
    
    return ans;*/
  }
};

/*
  Q: 1706. Where Will the Ball Fall
*/
class Solution3_t 
{
public:
  vector<int> findBall(vector<vector<int>>& grid) 
  {
      
  }
};

/*
  Q: 1707. Maximum XOR With an Element From Array
*/
class Solution4_t
{
public:
  vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) 
  {
      
  }
};