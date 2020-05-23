/****************************************************
Date: May 23th

link: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3338/
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
  Q: Interval List Intersections
  Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.
  Return the intersection of these two interval lists.

  (Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.
  The intersection of two closed intervals is a set of real numbers that is either empty, or can be represented as a closed interval.
  For example, the intersection of [1, 3] and [2, 4] is [2, 3].)

  Example 1:
    Input: A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
    Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
    Reminder: The inputs and the desired output are lists of Interval objects, and not arrays or lists.

  Note:
    0 <= A.length < 1000
    0 <= B.length < 1000
    0 <= A[i].start, A[i].end, B[i].start, B[i].end < 10^9
    NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
*/
class Solution 
{
public:
  vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) 
  {
    auto a = A.begin();
    auto b = B.begin();
    vector< vector<int> > ans;
    while(a != A.end() && b != B.end())
    {
      if(*a == *b)
      {
        ans.push_back({(*a)[0], (*a)[1]});
        a++;  b++;
        continue;
      }
      
      if((*b)[1] == (*a)[0])
      {
        ans.push_back({(*a)[0], (*a)[0]});
        b++;
        continue;
      }
      else if((*b)[1] < (*a)[0])
      {
        b++;
        continue;
      }
      else if((*a)[1] < (*b)[0])
      {
        a++;
        continue;
      }
      
      vector<int> interval(2);
      interval[0] = max((*a)[0], (*b)[0]);
      interval[1] = min((*a)[1], (*b)[1]);
      ans.push_back(interval);
      
      if((*a)[1] <= (*b)[1])
      {
        a++;
      }
      else if((*b)[1] <= (*a)[1])
      {
        b++;
      }
    }
    
    return ans;
  }
};