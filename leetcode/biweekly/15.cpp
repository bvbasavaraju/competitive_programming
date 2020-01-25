/****************************************************
Date: December 14, 2019
Successful submissions : 2
Time expiration :
Not Solved : 2
Wrong Answer/ Partial result : 

link: https://leetcode.com/contest/biweekly-contest-15
****************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

/*
    Q: 1287. Element Appearing More Than 25% In Sorted Array
*/
class Solution1_t
{
public:
    int findSpecialInteger(vector<int> &arr)
    {
        int s = arr.size();
        int rl = s * 0.25;

        int retVal = 0;
        for (int i = 0; i < s; i++)
        {
            int count = 1;
            retVal = arr[i];
            for (int j = (i + 1); j < s; j++)
            {
                if (retVal != arr[j])
                {
                    break;
                }
                else
                {
                    count++;
                    if (count > rl)
                    {
                        return retVal;
                    }
                }
            }
        }

        return retVal;
    }
};

/*
    Q: 1288. Remove Covered Intervals
*/
class Solution2_t
{
public:
    int removeCoveredIntervals(vector<vector<int>> &intervals)
    {
        int l = intervals.size();

        sort(intervals.begin(), intervals.end(), [](const vector<int> i, const vector<int> j) -> bool { return (i[0] > j[0]); });

        int dc = 0;
        for (int i = 0; i < l; i++)
        {
            vector<int> x = intervals[i];

            for (int j = (i + 1); j < l; j++)
            {
                vector<int> y = intervals[j];
                if ((y[0] <= x[0]) && (x[1] <= y[1]))
                {
                    dc++;
                    break;
                }
            }
        }

        return intervals.size() - dc;
    }
};

/*
    Q: 1286. Iterator for Combination
*/

class CombinationIterator
{
public:
    CombinationIterator(string characters, int combinationLength)
    {
    }

    string next()
    {
    }

    bool hasNext()
    {
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

/*
    Q: 1289. Minimum Falling Path Sum II
*/

class Solution4_t
{
public:
    int minFallingPathSum(vector<vector<int>> &arr)
    {
    }
};