/****************************************************
Date: November 24th, 2019
Successful submissions : 1
Time expiration :
Not Solved : 3
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/weekly-contest-164
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
    Q: 1266. Minimum Time Visiting All Points
*/
class Solution1_t
{
public:
    int minTimeToVisitAllPoints(vector<vector<int>> &points)
    {
    }
};

/*
    Q: 1267. Count Servers that Communicate
*/
class Solution2_t
{
public:
    int countServers(vector<vector<int>> &g)
    {
        int retVal = 0;

        int r = g.size();
        int c = g[0].size();

        vector<int> rSum(r, 0);
        vector<int> cSum(c, 0);

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (g[i][j] != 0)
                {
                    rSum[i]++;
                    cSum[j]++;
                }
            }
        }

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if ((g[i][j] > 0) && ((rSum[i] > 1) || (cSum[j] > 1)))
                {
                    retVal++;
                }
            }
        }

        return retVal;
    }
};

/*
    Q: 1268. Search Suggestions System
*/
class Solution3_t
{
public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {
    }
};

/*
    Q: 1269. Number of Ways to Stay in the Same Place After Some Steps
*/
class Solution4_t
{
public:
    int numWays(int steps, int arrLen)
    {
    }
};