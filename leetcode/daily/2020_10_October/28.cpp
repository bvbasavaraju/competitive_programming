/****************************************************
Date: Oct 29th

link: https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/563/week-5-october-29th-october-31st/3512/
****************************************************/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <limits.h>

using namespace std;

/*
    Q: Maximize Distance to Closest Person

    You are given an array representing a row of seats where seats[i] = 1 represents a person sitting in the ith seat, 
    and seats[i] = 0 represents that the ith seat is empty (0-indexed).

    There is at least one empty seat, and at least one person sitting.
    Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 
    Return that maximum distance to the closest person.

    Example 1:
        Input: seats = [1,0,0,0,1,0,1]
        Output: 2
        Explanation: 
            If Alex sits in the second open seat (i.e. seats[2]), then the closest person has distance 2.
            If Alex sits in any other open seat, the closest person has distance 1.
            Thus, the maximum distance to the closest person is 2.
    
    Example 2:
        Input: seats = [1,0,0,0]
        Output: 3
        Explanation: 
            If Alex sits in the last seat (i.e. seats[3]), the closest person is 3 seats away.
            This is the maximum distance possible, so the answer is 3.

    Example 3:
        Input: seats = [0,1]
        Output: 1

    Constraints:
        2 <= seats.length <= 2 * 104
        seats[i] is 0 or 1.
        At least one seat is empty.
        At least one seat is occupied.
*/

class Solution
{
public:
    int maxDistToClosest(vector<int> &seats)
    {
        int l = seats.size();

        int ans = -1;
        int j = seats[0] == 0 ? -1 : 0;
        int one_count = seats[0] == 0 ? 0 : 1;
        for (int i = 1; i < l; ++i)
        {
            if (seats[i] == 1)
            {
                if (j < 0)
                {
                    j = i;
                    ans = j;
                    one_count++;
                }
                else
                {
                    ans = max(ans, (i - j) / 2);
                    j = i;
                }
            }
        }

        if (one_count == 1)
        {
            ans = max(ans, l - j - 1);
        }

        return (ans < 0) ? l - 1 : ans;
    }
};