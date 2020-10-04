/****************************************************
Date: Oct 4th

link: https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/559/week-1-october-1st-october-7th/3481/
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
    Q: Remove Covered Intervals

    Given a list of intervals, remove all intervals that are covered by another interval in the list.
    Interval [a,b) is covered by interval [c,d) if and only if c <= a and b <= d.
    After doing so, return the number of remaining intervals.

    Example 1:
        Input: intervals = [[1,4],[3,6],[2,8]]
        Output: 2
        Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.

    Example 2:
        Input: intervals = [[1,4],[2,3]]
        Output: 1

    Example 3:
        Input: intervals = [[0,10],[5,12]]
        Output: 2

    Example 4:
        Input: intervals = [[3,10],[4,10],[5,11]]
        Output: 2

    Example 5:
        Input: intervals = [[1,2],[1,4],[3,4]]
        Output: 1

    Constraints:
        1 <= intervals.length <= 1000
        intervals[i].length == 2
        0 <= intervals[i][0] < intervals[i][1] <= 10^5
        All the intervals are unique.
    
    Hide Hint #1  
        How to check if an interval is covered by another?
    Hide Hint #2  
        Compare each interval to all others and check if it is covered by any interval.
*/

class Solution
{
public:
    int removeCoveredIntervals(vector<vector<int>> &intervals)
    {
        int l = intervals.size();
        if (l <= 1)
        {
            return l;
        }

        sort(intervals.begin(), intervals.end(), [](const vector<int> &i1, const vector<int> &i2) -> bool {
            return ((i1[0] < i2[0]) || ((i1[0] == i2[0]) && (i1[1] >= i2[1])));
        });

        vector<vector<int>> valid;
        vector<int> interval = intervals[0];
        for (int i = 1; i < l; ++i)
        {
            if (!((interval[0] <= intervals[i][0]) && (intervals[i][1] <= interval[1])))
            {
                valid.push_back(interval);
                interval = intervals[i];
            }
        }

        if ((valid.size() == 0) || (valid.back() != interval))
        {
            valid.push_back(interval);
        }

        return valid.size();
    }
};