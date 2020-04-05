/****************************************************
Date: Mar 29th, 2020
Successful submissions : 3
Time expiration : 0
Not Solved : 1
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/weekly-contest-182
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
  Q: 1394. Find Lucky Integer in an Array
*/
class Solution1_t
{
public:
  int findLucky(vector<int>& arr) 
  {
    map<int, int> freq;
    
    int l = arr.size();
    for(int  i = 0; i < l; ++i)
    {
      freq[arr[i]]++;
    }
    
    int result = -1;
    for(auto it = freq.begin(); it != freq.end(); it++)
    {
      if(it->first == it->second)
      {
        result = max(it->first, result);
      }
    }
    
    return result;
  }
};

/*
  Q: 1395. Count Number of Teams
*/
class Solution2_t
{
public:
  int numTeams(vector<int>& r) 
  {
    int result = 0;
    int l = r.size();
    for(int i = 0; i < l - 2; ++i)
    {
      for(int j = i+1; j < l - 1; ++j)
      {
        for(int k = j+1; k < l; ++k)
        {
          if(((r[i] < r[j]) && (r[j] < r[k])) || ((r[i] > r[j]) && (r[j] > r[k])))
          {
            result++;
          }
        }
      }
    }
    
    return result;
  }
};

/*
  Q: 1396. Design Underground System
*/
class UndergroundSystem_t
{
private:
  unordered_map<int, pair<string, int>> m;
  unordered_map<string, pair<int, int>> data;
public:
    UndergroundSystem_t() 
    {
        
    }
    
    void checkIn(int id, string stationName, int t) 
    {
      m[id].first = stationName;
      m[id].second = t;
    }
    
    void checkOut(int id, string stationName, int t) 
    {
      string p = m[id].first + "_" + stationName;
      data[p].first += (t - m[id].second);
      data[p].second++;
    }
    
    double getAverageTime(string startStation, string endStation) 
    {
      string p = startStation + "_" + endStation;
      return (double)data[p].first/data[p].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */

/*
  Q: 1397. Find All Good Strings
*/
class Solution 
{
public:
    int findGoodStrings(int n, string s1, string s2, string evil) 
    {
        
    }
};