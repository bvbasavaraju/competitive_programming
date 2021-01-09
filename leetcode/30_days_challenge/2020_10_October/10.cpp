/****************************************************
Date: Oct 10th

link: https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/560/week-2-october-8th-october-14th/3488/
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
    Q: Minimum Number of Arrows to Burst Balloons

    There are some spherical balloons spread in two-dimensional space. For each balloon, 
    provided input is the start and end coordinates of the horizontal diameter. 
    Since it's horizontal, y-coordinates don't matter, and hence the x-coordinates of start and end of the diameter suffice. 
    The start is always smaller than the end.

    An arrow can be shot up exactly vertically from different points along the x-axis. 
    A balloon with xstart and xend bursts by an arrow shot at x if xstart ≤ x ≤ xend. 
    There is no limit to the number of arrows that can be shot. An arrow once shot keeps traveling up infinitely.

    Given an array points where points[i] = [xstart, xend], return the minimum number of arrows that must be 
    shot to burst all balloons.

    Example 1:
        Input: points = [[10,16],[2,8],[1,6],[7,12]]
        Output: 2
        Explanation: One way is to shoot one arrow for example at x = 6 (bursting the balloons [2,8] and [1,6]) and another arrow at x = 11 (bursting the other two balloons).
        
    Example 2:
        Input: points = [[1,2],[3,4],[5,6],[7,8]]
        Output: 4
        
    Example 3:
        Input: points = [[1,2],[2,3],[3,4],[4,5]]
        Output: 2
        
    Example 4:
        Input: points = [[1,2]]
        Output: 1
        
    Example 5:
        Input: points = [[2,3],[2,3]]
        Output: 1

    Constraints:
        0 <= points.length <= 104
        points.length == 2
        -231 <= xstart < xend <= 231 - 1
*/

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end(), [](const vector<int> &p1, const vector<int> &p2) -> bool {
            return ((p1[0] < p2[0]) || ((p1[0] == p2[0]) && (p1[1] <= p2[1])));
        });

        int ans = 0;
        int max_reach = 0;
        int l = points.size();

        for (int i = 0; i < l;)
        {
            ans++;
            max_reach = points[i][1];

            while ((i < l) && (points[i][0] <= max_reach))
            {
                max_reach = min(max_reach, points[i][1]);
                i++;
            }
        }

        return ans;
    }
};