/****************************************************
Date: November 13th

https://leetcode.com/problems/daily-temperatures/
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


class Solution 
{
private:
  unordered_map<int, queue<int>> tempPos;
  
  int nextWarmDayPos(int temp, int current_pos)
  {
    int retVal = INT_MAX;
    while(temp <= 100)
    {
      if(tempPos.count(temp) > 0)
      {
        while(!tempPos[temp].empty())
        {
          if(tempPos[temp].front() <= current_pos)
          {
            tempPos[temp].pop();
          }
          else
          {
            retVal = min(retVal, tempPos[temp].front());
            break;
          }
        }
      }

      temp++;
    }
    
    return retVal == INT_MAX ? -1 : retVal;
  }
  
public:
  vector<int> dailyTemperatures(vector<int>& temperatures) 
  {
    int l = temperatures.size();
    
    vector<int> ans(l, 0);
    for(int i = l-1; i >= 0; --i)
    {
      int j = i+1; //couldBeNextWarmDayPos
      while(j < l && (temperatures[j] <= temperatures[i]))
      {
        if(ans[j] > 0)  // there is another next warmer day
        {
          j = j + ans[j];
        }
        else
        {
          j = l;
        }
      }
      
      if(j < l)
      {
        ans[i] = j-i;
      }
    }
    
    return ans;
    
    //Size O(2n), Time == O(70n)
//     for(int i = 0; i < l; ++i)
//     {
//       tempPos[temperatures[i]].push(i);
//     }
    
//     vector<int> ans(l);
//     for(int i = 0; i < l; ++i)
//     {
//       int t = temperatures[i];
//       int nexWarmDay = nextWarmDayPos(t+1, i);
//       ans[i] = (nexWarmDay > 0) ? (nexWarmDay - i) : 0;
//     }
    
    // return ans;
  }
};

int main()
{
  Solution s;
  vector<int> temperatures = {73,74,75,71,69,72,76,73};
  s.dailyTemperatures(temperatures);

  return 0;
}