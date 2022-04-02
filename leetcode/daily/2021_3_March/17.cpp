/****************************************************
Date: March 17th

link: https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/590/week-3-march-15th-march-21st/3673/
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
  Q: Generate Random Point in a Circle

  Given the radius and x-y positions of the center of a circle, write a function randPoint which generates a uniform random point in the circle.

  Note:
    input and output values are in floating-point.
    radius and x-y position of the center of the circle is passed into the class constructor.
    a point on the circumference of the circle is considered to be in the circle.
    randPoint returns a size 2 array containing x-position and y-position of the random point, in that order.

  Example 1:
    Input: 
      ["Solution","randPoint","randPoint","randPoint"]
      [[1,0,0],[],[],[]]
    Output: 
      [null,[-0.72939,-0.65505],[-0.78502,-0.28626],[-0.83119,-0.19803]]

  Example 2:
    Input: 
      ["Solution","randPoint","randPoint","randPoint"]
      [[10,5,-7.5],[],[],[]]
    Output: 
      [null,[11.52438,-8.33273],[2.46992,-16.21705],[11.13430,-12.42337]]

  Explanation of Input Syntax:
    The input is two lists: the subroutines called and their arguments. 
    Solution's constructor has three arguments, the radius, x-position of the center, 
    and y-position of the center of the circle. randPoint has no arguments. 
    Arguments are always wrapped with a list, even if there aren't any.
*/

class Solution 
{
private:
  double r;
  double x;
  double y;
  
  bool isInCircle(double x_, double y_)
  {
    return (((x_ - x) * (x_ - x)) + ((y_ - y) * (y_ - y)) <= (r * r));
  }
  
public:
  Solution(double radius, double x_center, double y_center) 
    : r(radius),
      x(x_center),
      y(y_center)
  { }

  vector<double> randPoint() 
  {
    double x_ = 0.0;
    double y_ = 0.0;
    
    do
    {
      x_ = (double)rand()/RAND_MAX * (2*r) + x - r;
      y_ = (double)rand()/RAND_MAX * (2*r) + y - r;
    }while(!isInCircle(x_, y_));
    
    return {x_, y_};
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */