/****************************************************
Date: Dec 20th, 2020
Successful submissions : 1
Time expiration : 0
Not Solved : 1
Wrong Answer/ Partial result/solved after looking at solution : 2
link: https://leetcode.com/contest/weekly-contest-220
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
    Q: 1694. Reformat Phone Number
*/
class Solution_1
{
public:
    string reformatNumber(string number)
    {
        string nums = "";
        for (auto ch : number)
        {
            if (ch != ' ' && ch != '-')
            {
                nums += ch;
            }
        }

        string ans = "";
        int l = nums.size();

        int i = 0;
        for (; i < l - 4;)
        {
            for (int j = 0; j < 3; ++j)
            {
                ans += nums[i];
                ++i;
            }
            ans += '-';
        }

        if (l - i == 4)
        {
            for (int j = 0; j < 2; ++j)
            {
                ans += nums[i];
                i++;
            }
            ans += '-';
            for (int j = 0; j < 2; ++j)
            {
                ans += nums[i];
                i++;
            }
        }
        else
        {
            for (; i < l; ++i)
            {
                ans += nums[i];
            }
        }

        return ans;
    }
};

/*
    Q: 1695. Maximum Erasure Value - later
*/
class Solution2_t
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        int l = nums.size();

        vector<int> sum_p(l + 1);
        for (int i = 0; i < l; ++i)
        {
            sum_p[i + 1] = sum_p[i] + nums[i];
        }

        int i = 0;
        int j = 0;
        int ans = INT_MIN;
        unordered_set<int> used;

        while (i < l && j < l)
        {
            if (used.find(nums[j]) != used.end())
            {
                used.erase(nums[i++]);
            }
            else
            {
                used.insert(nums[j++]);
                ans = max(ans, sum_p[j] - sum_p[i]);
            }
        }

        return ans;
    }
};

/*
    Q: 1696. Jump Game VI - later
*/
class Solution3_t
{
public:
    int maxResult(vector<int> &nums, int k)
    {
        int l = nums.size();

        int ans = 0;
        vector<int> dp(l, INT_MIN);
        dp[0] = nums[0];
        for (int i = 0; i < l; ++i)
        {
            for (int j = 1; j <= k && i + j < l; ++j)
            {
                dp[i + j] = max(dp[i + j], dp[i] + nums[i + j]);
                if (nums[i + j] >= 0)
                {
                    break;
                }
            }
        }

        return dp[l - 1];
    }
};

/*
    Q: 1697. Checking Existence of Edge Length Limited Paths
*/
class Solution4_t
{
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>> &edgeList, vector<vector<int>> &queries)
    {
    }
};