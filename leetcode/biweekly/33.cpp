/****************************************************
Date: August 22nd, 2020
Successful submissions : 1
Time expiration : 0
Not Solved : 3
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/biweekly-contest-33
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
    Q: 1556. Thousand Separator
*/

class Solution1_t
{
public:
    string thousandSeparator(int n)
    {
        if (n == 0)
        {
            return "0";
        }

        int count = 0;
        vector<char> str;
        while (n > 0)
        {
            if (count == 3)
            {
                str.push_back('.');
                count = 0;
            }

            int ni = n % 10;
            str.push_back(ni + 0x30);

            n = n / 10;
            count++;
        }

        string ans;
        while (!str.empty())
        {
            ans += str.back();
            str.pop_back();
        }

        return ans;
    }
};

/*
    Q: 1557. Minimum Number of Vertices to Reach All Nodes
*/
class Solution2_t
{
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
    {
    }
};

/*
    Q: 1558. Minimum Numbers of Function Calls to Make Target Array
*/
class Solution3_t
{
public:
    int minOperations(vector<int> &nums)
    {
    }
};

/*
    Q: 1559. Detect Cycles in 2D Grid
*/
class Solution4_t
{
public:
    bool containsCycle(vector<vector<char>> &grid)
    {
    }
};