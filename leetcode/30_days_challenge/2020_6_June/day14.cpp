/****************************************************
Date: June 14th

link: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3359/
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
  map<pair<int, int>, int> src_dst_cost;
  unordered_map<int, vector<int>> src_dest;

  map<pair<int, int>, int> reached_data;

  int getCostForRoute(int src, int dst, int max_stops, int current_stop, int& total)
  {
    if(current_stop > max_stops)
    {
      return -1;
    }
    
    if(src_dest.find(src) == src_dest.end())
    {
      return -1;
    }
    
    pair<int, int> sd_pair = make_pair(src, dst);
    if(reached_data.find(sd_pair) != reached_data.end())
    {
      return reached_data[sd_pair];
    }
    
    int ans = -1;
    vector<int> cities = src_dest[src];
    for(auto c : cities)
    {
      if(src_dst_cost.find(make_pair(src, c)) == src_dst_cost.end())
      {
        return -1;
      }
      
      total += src_dst_cost[make_pair(src, c)];
      if(c == dst)
      {        
        ans = ans < 0 ? max(ans, total) : min(ans, total);
        
        reached_data[sd_pair] = ans;
        
        total = 0;
        return ans;
      }
      
      current_stop++;
      int cost = getCostForRoute(c, dst, max_stops, current_stop, total);
      if(cost > 0)
      {
        ans = ans < 0 ? cost : ans + cost;
      }
      else
      {
        ans = -1;
        total = 0;
      }
      
      reached_data[make_pair(c, dst)] = cost;
    }
    
    return ans;
  }
    
public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) 
  {
    for(auto d : flights)
    {
      src_dest[d[0]].push_back(d[1]);
      src_dst_cost[make_pair(d[0], d[1])] = d[2];
    }

    vector<int> cities =src_dest[src];
    if(cities.size() == 0)
    {
      return -1;
    }

    int ans = -1;
    for(auto c : cities)
    {
      int total = 0;
      int cost = -1;
      if(c == dst)
      {
        cost = src_dst_cost[make_pair(src, c)];
      }
      else
      {
        cost = getCostForRoute(c, dst, K, 0, total);
      }
      if(cost > 0)
      {
        ans = ans < 0 ? max(ans, cost) : min(ans, cost);
      }
    }

    return ans;
  }
};

int main()
{
  // {
  //   Solution s;
  //   vector<vector<int>> v = {{0,1,100}, {1,2,100}, {0,2,500}};
  //   int ans = s.findCheapestPrice(3, v, 0, 2, 0);
  // }
  // {
  //   Solution s;
  //   vector<vector<int>> v = {{1,2,10}, {2,0,7}, {1,3,8}, {4,0,10}, {3,4,2}, {4,2,10}, {0,3,3}, {3,1,6}, {2,4,5}};
  //   int ans = s.findCheapestPrice(5, v, 0, 4, 1);
  // }
  {
    Solution s;
    vector<vector<int>> v = {{3,4,4},{2,5,6},{4,7,10},{9,6,5},{7,4,4},{6,2,10},{6,8,6},{7,9,4},{1,5,4},{1,0,4},{9,7,3},{7,0,5},{6,5,8},{1,7,6},{4,0,9},{5,9,1},{8,7,3},{1,2,6},{4,1,5},{5,2,4},{1,9,1},{7,8,10},{0,4,2},{7,2,8}};
    int ans = s.findCheapestPrice(10, v, 6, 0, 7);
  }
}