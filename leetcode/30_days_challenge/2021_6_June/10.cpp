/****************************************************
Date: June 10th

link: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/604/week-2-june-8th-june-14th/3772/
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
  Q: My Calendar I

  Implement a MyCalendar class to store your events. A new event can be added if adding the 
  event will not cause a double booking.

  Your class will have the method, book(int start, int end). Formally, this represents a 
  booking on the half open interval [start, end), the range of real numbers x such that start <= x < end.

  A double booking happens when two events have some non-empty intersection 
  (ie., there is some time that is common to both events.)

  For each call to the method MyCalendar.book, return true if the event can be added to 
  the calendar successfully without causing a double booking. Otherwise, return false and 
  do not add the event to the calendar.

  Your class will be called like this: MyCalendar cal = new MyCalendar(); MyCalendar.book(start, end)

  Example 1:
    MyCalendar();
    MyCalendar.book(10, 20); // returns true
    MyCalendar.book(15, 25); // returns false
    MyCalendar.book(20, 30); // returns true

  Explanation: 
    The first event can be booked.  The second can't because time 15 is already booked by another event.
    The third event can be booked, as the first event takes every time less than 20, but not including 20.

  Note:
    The number of calls to MyCalendar.book per test case will be at most 1000.
    In calls to MyCalendar.book(start, end), start and end are integers in the range [0, 10^9].

  Hide Hint #1  
    Store the events as a sorted list of intervals. If none of the events conflict,
    then the new event can be added.
*/

class MyCalendar 
{
private:
  
  vector< vector<int> > slots;
  
public:
  MyCalendar() 
  {

  }

  bool book(int start, int end) 
  {
    vector<int> data = {start, end};
    for(vector<int>& it : slots)
    {
      int s = max(it[0], start);
      int e = min(it[1], end);
      
      if(s < e)
      {
        return false;
      }
    }
    
    slots.push_back({start, end});
    return true;
  }
};