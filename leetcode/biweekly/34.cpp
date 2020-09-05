/****************************************************
Date: Setember 5th, 2020
Successful submissions : 1
Time expiration : 0
Not Solved : 3
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/biweekly-contest-34
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
    Q: 1572. Matrix Diagonal Sum    
*/
class Solution1_t
{
public:
    int diagonalSum(vector<vector<int>> &mat)
    {
        int ans = 0;

        int r = mat.size();
        int c = mat[0].size();

        int j = 0;
        int k = c - 1;
        for (int i = 0; i < r && j < c && k >= 0; ++i)
        {
            if (j != k)
            {
                ans += mat[i][j] + mat[i][k];
            }
            else
            {
                ans += mat[i][j];
            }

            ++j;
            --k;
        }

        return ans;
    }
};

/*
    Q: 1573. Number of Ways to Split a String - incomplete
*/
class Solution2_t
{
public:
    int numWays(string s)
    {
        int count = 0;
        for (int ch : s)
        {
            if (ch == '1')
            {
                count++;
            }
        }

        int ans = 0;
        if (count % 3 == 0)
        {
            if (count == 0)
            {
            }
            else
            {
                int c = count / 3;
                int l = s.size();

                count = 0;
                int s1_min_len = 0;
                int s1_max_len = 0;
                int s3_min_len = 0;
                int s3_max_len = 0;
                for (int i = 0; i < l && (count == c); ++i)
                {
                    if (s[i] == '1')
                    {
                        count++;
                    }
                }
            }
        }

        return ans;
    }
};

/*
    Q: 1574. Shortest Subarray to be Removed to Make Array Sorted - incomplete
*/
class Solution3_t
{
public:
    int findLengthOfShortestSubarray(vector<int> &arr)
    {
        int l = arr.size();

        int ans = 0;
        int p = -1;
        for (int i = 1; i < l; ++i)
        {
            if (arr[i] > arr[i - 1])
            {
                if (p < 0)
                {
                    p = i - 1;
                }

                ans++;
            }
            else if (p >= 0)
            {
                if (arr[p] >= arr[i])
                {
                    break;
                }
            }
        }
    }
};

/*
    Q: 1575. Count All Possible Routes
*/
class Solution4_t
{
public:
    int countRoutes(vector<int> &locations, int start, int finish, int fuel)
    {
    }
};