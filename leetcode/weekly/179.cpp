/****************************************************
Date: Mar 8th, 2020
Successful submissions : 0
Time expiration : 0
Not Solved : 4
Wrong Answer/ Partial result : 0

Note: I was travelling to US for business purpose

link: https://leetcode.com/contest/weekly-contest-179
****************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;

/*
    Q:  1374. Generate a String With Characters That Have Odd Counts
*/
class Solution1_t
{
public:
    string generateTheString(int n)
    {
        string retVal = "";
        for (int i = 0; i < n; i++)
        {
            retVal += 'a';
        }

        if (n % 2 == 0)
        {
            retVal[n - 1] = 'b';
        }

        return retVal;
    }
};

/*
    Q:  1375. Bulb Switcher III
*/
class Solution2_t
{
public:
    int numTimesAllBlue(vector<int> &light)
    {
        int l = light.size();
        if (l <= 0)
        {
            return 0;
        }

        int result = 0;

        int currentMax = 0;
        for (int i = 0; i < l; ++i)
        {
            currentMax = max(currentMax, light[i]);

            if (currentMax == (i + 1))
            {
                result++;
            }
        }

        return result;
    }
};

/*
    Q:  1376. Time Needed to Inform All Employees
*/
class Solution3_t
{
public:
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
    {
    }
};

/*
    Q:  1377. Frog Position After T Seconds
*/
class Solution4_t
{
public:
    double frogPosition(int n, vector<vector<int>> &edges, int t, int target)
    {
    }
};