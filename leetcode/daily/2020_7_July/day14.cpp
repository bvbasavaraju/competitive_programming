/****************************************************
Date: July 14th

link: https://leetcode.com/explore/featured/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3377/
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
  Q: Angle Between Hands of a Clock

  Given two numbers, hour and minutes. 
  Return the smaller angle (in degrees) formed between the hour and the minute hand.

  Example 1:
    Input: hour = 12, minutes = 30
    Output: 165
  
  Example 2:
    Input: hour = 3, minutes = 30
    Output: 75
  
  Example 3:
    Input: hour = 3, minutes = 15
    Output: 7.5
  
  Example 4:
    Input: hour = 4, minutes = 50
    Output: 155
  
  Example 5:
    Input: hour = 12, minutes = 0
    Output: 0

  Constraints:
    1 <= hour <= 12
    0 <= minutes <= 59
    Answers within 10^-5 of the actual value will be accepted as correct.
  
  Hide Hint #1  
    The tricky part is determining how the minute hand affects the position of the hour hand.
  Hide Hint #2  
    Calculate the angles separately then find the difference.
*/
class Solution 
{
public:
  double angleClock(int hour, int minutes) 
  {
    const double MIN_HAND_DEGREE_PER_MIN = 6.0;
    const double HOUR_HAND_DEGREE_SHIFT_PER_MIN = 0.5;
    
    double minHandAngleFrom12 = minutes * 6.0;
    double hourHandAngleFrom12 = (hour % 12) * 30.0;
    
    hourHandAngleFrom12 += (minutes * HOUR_HAND_DEGREE_SHIFT_PER_MIN);
    
    double ans = abs(hourHandAngleFrom12 - minHandAngleFrom12);
    return (ans > 180.0) ? 360.0 - ans : ans;
  }
};