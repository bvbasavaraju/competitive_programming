/****************************************************
Date: Sept 19th, 2020
Successful submissions : 2
Time expiration : 0
Not Solved : 2
Wrong Answer/ Partial result : 1

link: https://leetcode.com/contest/biweekly-contest-35
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
#include <string_view>

using namespace std;

/*
    Q: 1588. Sum of All Odd Length Subarrays
*/
class Solution1_t
{
private:
    int getSum(vector<int> &sum_arr, int len)
    {
        int ans = 0;

        int count = -1;
        int l = sum_arr.size();
        for (int i = len - 1; i < l; ++i)
        {
            ans += sum_arr[i];

            if (count >= 0)
            {
                ans -= sum_arr[count];
            }

            count++;
        }

        return ans;
    }

public:
    int sumOddLengthSubarrays(vector<int> &arr)
    {
        int l = arr.size();

        vector<int> sum_arr(l, 0);
        int sum = 0;
        for (int i = 0; i < l; ++i)
        {
            sum += arr[i];
            sum_arr[i] = sum;
        }

        int ans = 0;
        for (int i = l; i > 0; i = i - 2)
        {
            ans += getSum(sum_arr, i);
        }

        return ans;
    }
};

/*
    Q: 1589. Maximum Sum Obtained of Any Permutation
*/
class Solution2_t
{
public:
    int maxSumRangeQuery(vector<int> &nums, vector<vector<int>> &requests)
    {

        int l = nums.size();
        vector<int> count(l, 0);
        for (vector<int> req : requests)
        {
            count[req[0]] += 1;
            if (req[1] + 1 < l)
            {
                count[req[1] + 1] -= 1;
            }
        }

        for (int i = 1; i < l; ++i)
        {
            count[i] += count[i - 1];
        }

        sort(nums.begin(), nums.end());
        sort(count.begin(), count.end());

        const int MOD = 1e9 + 7;
        int ans = 0;
        for (int i = l - 1; i >= 0; i--)
        {
            if (count.back() == 0)
            {
                break;
            }

            ans += (nums.back() % MOD) * (count.back() % MOD);

            ans = ans % MOD;

            nums.pop_back();
            count.pop_back();
        }

        return ans;
    }
};

/*
    Q: 1590. Make Sum Divisible by P
*/
class Solution3_t
{
public:
    int minSubarray(vector<int> &nums, int p)
    {
    }
};

/*
    Q: 1591. Strange Printer II
*/
class Solution4_t
{
public:
    bool isPrintable(vector<vector<int>> &targetGrid)
    {
    }
};