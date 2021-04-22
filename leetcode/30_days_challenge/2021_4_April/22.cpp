/****************************************************
Date: April 22nd

link: https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/596/week-4-april-22nd-april-28th/3717/
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
  Q: Brick Wall

  There is a brick wall in front of you. The wall is rectangular and has several rows of bricks. 
  The bricks have the same height but different width. You want to draw a vertical line from the top to the bottom and cross the least bricks.

  The brick wall is represented by a list of rows.
  Each row is a list of integers representing the width of each brick in this row from left to right.

  If your line go through the edge of a brick, then the brick is not considered as crossed. 
  You need to find out how to draw the line to cross the least bricks and return the number of crossed bricks.

  You cannot draw a line just along one of the two vertical edges of the wall, in which case the line will obviously cross no bricks.

  Example:
  Input: 
    [[1,2,2,1],
    [3,1,2],
    [1,3,2],
    [2,4],
    [3,1,2],
    [1,3,1,1]]
  Output: 2

  Explanation: 

  Note:
  The width sum of bricks in different rows are the same and won't exceed INT_MAX.
  The number of bricks in each row is in range [1,10,000]. 
  The height of wall is in range [1,10,000]. Total number of bricks of the wall won't exceed 20,000.
*/

class Solution 
{
public:
  int leastBricks(vector<vector<int>>& wall) 
  {
    unordered_map<int, int> edges;
    auto ans = wall.size();
    for (auto row : wall)
    {
      for (auto i = 0, width = 0; i < row.size() - 1; ++i) // skip last brick
      {
        ans = min(ans, wall.size() - (++edges[width += row[i]]));
      }
    }
    
    return ans;
  }
};