/****************************************************
Date: June 5th

link: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/603/week-1-june-1st-june-7th/3764/
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

/*
  Q: Maximum Performance of a Team

  You are given two integers n and k and two integer arrays speed and efficiency both of length n.
  There are n engineers numbered from 1 to n. speed[i] and efficiency[i] represent the speed and
  efficiency of the ith engineer respectively.

  Choose at most k different engineers out of the n engineers to form a team with the maximum performance.

  The performance of a team is the sum of their engineers' speeds multiplied by the minimum efficiency
  among their engineers.

  Return the maximum performance of this team. Since the answer can be a huge number, return it modulo 109 + 7.

  Example 1:
    Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 2
    Output: 60
    Explanation: 
      We have the maximum performance of the team by selecting engineer 2 (with speed=10 and efficiency=4) 
      and engineer 5 (with speed=5 and efficiency=7). That is, performance = (10 + 5) * min(4, 7) = 60.

  Example 2:
    Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 3
    Output: 68
    Explanation:
      This is the same example as the first but k = 3. We can select engineer 1, 
      engineer 2 and engineer 5 to get the maximum performance of the team. 
      That is, performance = (2 + 10 + 5) * min(5, 4, 7) = 68.

  Example 3:
    Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 4
    Output: 72

  Constraints:
    1 <= <= k <= n <= 105
    speed.length == n
    efficiency.length == n
    1 <= speed[i] <= 105
    1 <= efficiency[i] <= 108

  Hide Hint #1  
    Keep track of the engineers by their efficiency in decreasing order.
  Hide Hint #2  
    Starting from one engineer, to build a team, it suffices to bring K-1 more engineers who have higher 
    efficiencies as well as high speeds.
*/
class Solution 
{
public:
  int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) 
  {
    vector<pair<int, int>> p;
    for(int i = 0; i < n; ++i)
    {
      p.push_back({efficiency[i], speed[i]});
    }
    
    sort(p.begin(), p.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    
    long long sum = 0;
    long long ans = 0;
    for(int i = n-1; i >= 0; --i)
    {
      sum += p[i].second;
      pq.push(p[i].second);
      
      if(pq.size() > k)
      {
        sum -= pq.top();
        pq.pop();
      }
      
      ans = max(ans, sum * p[i].first);
    }
    
    return static_cast<int>(ans % 1000000007);
  }
};