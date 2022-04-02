/****************************************************
Date: May 30th

link: https://leetcode.com/explore/featured/card/may-leetcoding-challenge/538/week-5-may-29th-may-31st/3345/
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
  Q: K Closest Points to Origin

  We have a list of points on the plane.  Find the K closest points to the origin (0, 0).
  (Here, the distance between two points on a plane is the Euclidean distance.)
  You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)

  Example 1:
    Input: points = [[1,3],[-2,2]], K = 1
    Output: [[-2,2]]
    Explanation: 
    The distance between (1, 3) and the origin is sqrt(10).
    The distance between (-2, 2) and the origin is sqrt(8).
    Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
    We only want the closest K = 1 points from the origin, so the answer is just [[-2,2]].

  Example 2:
    Input: points = [[3,3],[5,-1],[-2,4]], K = 2
    Output: [[3,3],[-2,4]]
    (The answer [[-2,4],[3,3]] would also be accepted.)

  Note:
    1 <= K <= points.length <= 10000
    -10000 < points[i][0] < 10000
    -10000 < points[i][1] < 10000
*/

class Solution 
{
public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int K) 
  {
    int l = points.size();
    
    vector<int> d(l, 0);
    unordered_map<int, vector<vector<int>> > m;
    for(int i = 0; i < l; ++i)
    {
      d[i] = (points[i][0] * points[i][0]) + (points[i][1] * points[i][1]);      
      m[d[i]].push_back(points[i]);
    }
    
    sort(d.begin(), d.end());
    
    vector<vector<int>> ans;
    for(int i = 0; i < K && ans.size() < K; ++i)
    {
      vector<vector<int>> ps = m[d[i]];
      for(auto p : ps)
      {
        ans.push_back(p);
        if(ans.size() >= K)
        {
          break;
        }
      }
    }
    
    return ans;
  }
};