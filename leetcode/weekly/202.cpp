/****************************************************
Date: aug 16th, 2020
Successful submissions : 2
Time expiration : 0
Not Solved : 2
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/weekly-contest-202
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

using namespace std;

/*
    Q: 1550. Three Consecutive Odds
*/
class Solution1_t
{
public:
    bool threeConsecutiveOdds(vector<int> &arr)
    {
        bool ans = false;
        int l = arr.size();
        for (int i = 0; i < l - 2; ++i)
        {
            if ((arr[i] & 0x01) && (arr[i + 1] & 0x01) && (arr[i + 2] & 0x01))
            {
                ans = true;
                break;
            }
        }

        return ans;
    }
};

/*
    Q: 1551. Minimum Operations to Make Array Equal
*/
class Solution2_t
{
public:
    int minOperations(int n)
    {
        int l = n / 2;

        int val = 1;
        int ans = 0;
        for (int i = 0; i < l; ++i)
        {
            ans += abs(n - val);
            val += 2;
        }

        return ans;
    }
};

/*
    Q: 1552. Magnetic Force Between Two Balls
*/
class Solution3_t
{
public:
    int maxDistance(vector<int> &position, int m)
    {
    }
};

/*
    Q: 1553. Minimum Number of Days to Eat N Oranges
*/
class Solution4_t
{
public:
    int minDays(int n)
    {
    }
};