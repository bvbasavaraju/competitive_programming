/****************************************************
Date: May 8th

link: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3323/
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
  Q: Check If It Is a Straight Line
  You are given an array coordinates, coordinates[i] = [x, y], 
  where [x, y] represents the coordinate of a point. 
  Check if these points make a straight line in the XY plane.

  Example 1:
    Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
    Output: true

  Example 2:
    Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
   Output: false

  Constraints:
    2 <= coordinates.length <= 1000
    coordinates[i].length == 2
    -10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
    coordinates contains no duplicate point.

  Show Hint #1
    If there're only 2 points, return true.

  Show Hint #2
    Check if all other points lie on the line defined by the first 2 points.

  Show Hint #3
    Use cross product to check collinearity.
*/

class Solution 
{
public:
  bool checkStraightLine(vector<vector<int>>& points) 
  {
    int l = points.size();
    if(l < 2)
    {
      return false;
    }
    
    
    vector<int> p1 = points[0];
    vector<int> p2 = points[1];
    
    bool parallel_to_x_axis = p2[1] == p1[1] ? true : false;
    bool parallel_to_y_axis = p2[0] == p1[0] ? true : false;
    
    double slope = 1.0;
    if(!parallel_to_x_axis && !parallel_to_y_axis)
    {
      slope = (p2[0] - p1[0])/ (p2[1] - p1[1]);
    }
    
    for(int i = 2; i < l; ++i)
    {
      p1 = p2;
      p2 = points[i];
      
      if(parallel_to_x_axis)
      {
        if(p1[1] != p2[1])
          return false;
        
      }
      else if(parallel_to_y_axis)
      {
        if(p1[0] != p2[0])
          return false;
      }
      else if(!parallel_to_x_axis && p1[1] == p2[1])
      {
        return false;
      }
      else if(!parallel_to_y_axis && p1[0] == p2[0])
      {
        return false;
      }
      else
      {
        double s = (p2[0] - p1[0])/(p2[1] - p1[1]);
        if(s != slope)
        {
          return false;
        }
      }
    }

    return true;
  }
};