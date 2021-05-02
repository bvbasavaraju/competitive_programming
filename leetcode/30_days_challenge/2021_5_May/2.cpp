/****************************************************
Date: May 2nd

link: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/598/week-1-may-1st-may-7th/3728/
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
  Q: Course Schedule III

  There are n different online courses numbered from 1 to n. 
  You are given an array courses where courses[i] = [durationi, lastDayi] indicate that 
  the ith course should be taken continuously for durationi days and must be finished before or on lastDayi.

  You will start on the 1st day and you cannot take two or more courses simultaneously.

  Return the maximum number of courses that you can take.

  Example 1:
    Input: courses = [[100,200],[200,1300],[1000,1250],[2000,3200]]
    Output: 3
    Explanation: 
      There are totally 4 courses, but you can take 3 courses at most:
        + First, take the 1st course, it costs 100 days so you will finish it on the 100th day, 
        and ready to take the next course on the 101st day.
        + Second, take the 3rd course, it costs 1000 days so you will finish it on the 1100th day, 
        and ready to take the next course on the 1101st day. 
        + Third, take the 2nd course, it costs 200 days so you will finish it on the 1300th day. 
        + The 4th course cannot be taken now, since you will finish it on the 3300th day, which exceeds the closed date.

  Example 2:
    Input: courses = [[1,2]]
    Output: 1

  Example 3:
    Input: courses = [[3,2],[4,3]]
    Output: 0

  Constraints:
    1 <= courses.length <= 104
    1 <= durationi, lastDayi <= 104

  Hide Hint #1  
    During iteration, say I want to add the current course, 
    currentTotalTime being total time of all courses taken till now, 
    but adding the current course might exceed my deadline or it doesn’t.
    1. If it doesn’t, then I have added one new course. Increment the currentTotalTime with duration of current course.
  
  Hide Hint #2  
    2. If it exceeds deadline, I can swap current course with current courses that has biggest duration.
      * No harm done and I might have just reduced the currentTotalTime, right?
      * What preprocessing do I need to do on my course processing order so that this swap is always legal?
*/
class Solution 
{
public:
  int scheduleCourse(vector<vector<int>>& courses) 
  {
    sort(courses.begin(), courses.end(), [](const vector<int>& c1, const vector<int>& c2) -> bool
         {
           if((c1[1] < c2[1]) || (c1[1] == c2[1] && c1[0] < c2[0]))
           {
             return true;
           }
           
           return false;
         });
    
    priority_queue<int> pq;
    
    int current_time = 0;
    for(vector<int>& course : courses)
    {
      if(current_time + course[0] <= course[1])
      {
        current_time += course[0];
        pq.push(course[0]);
      }
      else
      {
        if(!pq.empty() && (pq.top() > course[0]) && (current_time - pq.top() + course[0] <= course[1]))
        {
          int temp = pq.top();
          pq.pop();
          
          current_time -= temp;
          
          current_time += course[0];
          pq.push(course[0]);
        }
      }
    }
    
    return pq.size();
  }
};