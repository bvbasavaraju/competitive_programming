/****************************************************
Date: Oct 25th, 2020
Successful submissions : 2
Time expiration : 0
Not Solved : 1
Wrong Answer/ Partial result : 1
link: https://leetcode.com/contest/weekly-contest-212
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
    Q: 1629. Slowest Key
*/
class Solution
{
public:
    char slowestKey(vector<int> &rt, string kp)
    {
        vector<int> key_time(26, 0);

        char ans;
        int max_rt = 0;
        int l = rt.size();
        for (int i = 0; i < l; ++i)
        {
            if (i == 0)
            {
                key_time[kp[i] - 'a'] = rt[i];
            }
            else
            {
                int kt = key_time[kp[i] - 'a'];
                int ckt = rt[i] - rt[i - 1];

                key_time[kp[i] - 'a'] = max(ckt, kt);
            }

            if (key_time[kp[i] - 'a'] > max_rt)
            {
                max_rt = key_time[kp[i] - 'a'];
                ans = kp[i];
            }
            else if (key_time[kp[i] - 'a'] == max_rt)
            {
                ans = max(ans, kp[i]);
            }
        }

        return ans;
    }
};

/*
    Q: 1630. Arithmetic Subarrays
*/
class Solution
{
private:
    bool canBeAP(vector<int> &nums, int s, int e)
    {
        vector<int> seq(nums.begin() + s, nums.begin() + e + 1);

        sort(seq.begin(), seq.end());

        if (seq.size() < 2)
        {
            return false;
        }

        int d = seq[1] - seq[0];
        for (int i = 1; i < e - s + 1; ++i)
        {
            if ((seq[i] - seq[i - 1]) != d)
            {
                return false;
            }
        }

        return true;
    }

public:
    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r)
    {
        int s = l.size();

        vector<bool> ans(s);
        for (int i = 0; i < s; ++i)
        {
            ans[i] = canBeAP(nums, l[i], r[i]);
        }

        return ans;
    }
};

/*
    Q: 1631. Path With Minimum Effort - wrong answer
*/
class Solution
{
private:
    bool canReachEnd(vector<vector<int>> &h, set<pair<int, int>> &visited_path, int i, int j, int r, int c, int &current_height, int &effort)
    {
        if (i < 0 || j < 0 || i >= r || j >= c)
        {
            return false;
        }

        if (visited_path.count({i, j}) > 0)
        {
            return true;
        }

        if (visited_path.find({i, j}) == visited_path.end())
        {
            visited_path.insert({i, j});
            effort = min(effort, abs(current_height - h[i][j]));
        }

        if (i == r - 1 && j == c - 1)
        {
            return true;
        }

        canReachEnd(h, visited_path, i - 1, j, r, c, h[i][j], effort);
        canReachEnd(h, visited_path, i + 1, j, r, c, h[i][j], effort);
        canReachEnd(h, visited_path, i, j - 1, r, c, h[i][j], effort);
        canReachEnd(h, visited_path, i, j + 1, r, c, h[i][j], effort);

        return false;
    }

public:
    int minimumEffortPath(vector<vector<int>> &h)
    {
        int r = h.size();
        int c = h[0].size();

        if (r == 1 && c == 1)
        {
            return 0;
        }

        vector<vector<int>> dp(r, vector<int>(c, 0));
        // for (int i = 0; i < r; ++i)
        // {
        //     for (int j = 0; j < c; ++j)
        //     {
        //         int l_d = j > 0 ? abs(h[i][j] - h[i][j - 1]) : INT_MAX;
        //         int r_d = j < c - 1 ? abs(h[i][j] - h[i][j + 1]) : INT_MAX;
        //         int d_d = i < r - 1 ? abs(h[i][j] - h[i + 1][j]) : INT_MAX;
        //         int u_d = i > 0 ? abs(h[i][j] - h[i - 1][j]) : INT_MAX;

        //         //printf("%d, %d, %d, %d, %d, %d\n", i, j, l_d, r_d, d_d, u_d);
        //         dp[i][j] = min({l_d, r_d, d_d, u_d});
        //     }
        // }

        vector<pair<int, int>> path;
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                if (i == 0 && j == 0)
                {
                    path.push_back({i, j});
                }
                else if (i == 0)
                {
                }
            }
        }

        return dp[r - 1][c - 1];
    }
};

/*
    Q: 1632. Rank Transform of a Matrix
*/
class Solution
{
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>> &matrix)
    {
    }
};