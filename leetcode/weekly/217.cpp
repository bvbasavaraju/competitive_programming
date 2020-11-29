/****************************************************
Date: Nov 22nd, 2020
Successful submissions : 1
Time expiration : 0
Not Solved : 3
Wrong Answer/ Partial result : 0
link: https://leetcode.com/contest/weekly-contest-217
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
    Q: 1672. Richest Customer Wealth
*/
class Solution1_t
{
public:
    int maximumWealth(vector<vector<int>> &accounts)
    {
        int r = accounts.size();
        int c = accounts[0].size();

        int ans = 0;
        for (int i = 0; i < r; ++i)
        {
            int sum = 0;
            for (int j = 0; j < c; ++j)
            {
                sum += accounts[i][j];
            }

            ans = max(ans, sum);
        }

        return ans;
    }
};

/*
    Q: 1673. Find the Most Competitive Subsequence - solved after checking other code
*/
class Solution2_t
{
public:
    vector<int> mostCompetitive(vector<int> &nums, int k)
    {
        int l = nums.size();

        vector<int> ans;
        for (int i = 0; i < l; ++i)
        {
            while (!ans.empty() && (ans.back() > nums[i]) && ((ans.size() - 1 + l - i) >= k))
            {
                ans.pop_back();
            }

            if (ans.size() < k)
            {
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};

/*
    Q: 1674. Minimum Moves to Make Array Complementary - wrong. yet to correct it.
*/
class Solution3_t
{
private:
    int getCount(vector<int> &nums, int limit, int sum, int l)
    {
        printf("%d, %d, %d\n", limit, sum, l);
        int ret_val = 0;
        for (int i = 0; i < l / 2; ++i)
        {
            int diff = sum - (nums[i] + nums[l - 1 - i]);
            if (diff == 0)
            {
                continue;
            }

            if (abs(diff) > limit)
            {
                return -1;
            }

            if (nums[i] + diff + nums[l - 1 - i] == sum)
            {
                ret_val++;
            }
            else
            {
                ret_val += 2;
            }
        }

        return ret_val;
    }

public:
    int minMoves(vector<int> &nums, int limit)
    {
        int l = nums.size();

        int ans = 0;

        int sum = 0;
        vector<int> comp(l / 2, 0);
        for (int i = 0; i < l / 2; ++i)
        {
            comp[i] = nums[i] + nums[l - 1 - i];
            if (i == 0)
            {
                sum = comp[i];
            }
            else
            {
                if (comp[i] != sum)
                {
                    ans = -1;
                }
            }
        }

        if (ans < 0)
        {
            ans = INT_MAX;
            sort(comp.begin(), comp.end());

            for (int i = comp.size() / 2; i >= 0; --i)
            {
                int count = getCount(nums, limit, comp[i], l);
                if (count > 0)
                {
                    ans = min(ans, count);
                }
            }
        }

        return ans;
    }
};

/*
    Q: 5616. Minimize Deviation in Array
*/
class Solution4_t
{
public:
    int minimumDeviation(vector<int> &nums)
    {
    }
};