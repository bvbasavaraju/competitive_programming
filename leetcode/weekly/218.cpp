/****************************************************
Date: Dec 6th, 2020
Successful submissions : 2
Time expiration : 0
Not Solved : 1
Wrong Answer/ Partial result : 1
link: https://leetcode.com/contest/weekly-contest-218
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
    Q: 1678. Goal Parser Interpretation
*/
class Solution1_t
{
public:
    string interpret(string command)
    {
        int l = command.size();

        int prev = 0;
        string ans = "";
        for (int i = 0; i < l; ++i)
        {
            if (command[i] == 'G')
            {
                ans += "G";
                prev = 0;
            }
            else
            {
                if (command[i] == ')')
                {
                    if (prev == '(')
                    {
                        ans += "o";
                    }
                    else
                    {
                        ans += "al";
                    }
                }
                else
                {
                    prev = command[i];
                }
            }
        }

        return ans;
    }
};

/*
    Q: 1679. Max Number of K-Sum Pairs
*/
class Solution2_t
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;
        for (int n : nums)
        {
            freq[n]++;
        }

        int ans = 0;
        int l = nums.size();
        for (int i = 0; i < l; ++i)
        {
            if (nums[i] >= k)
            {
                continue;
            }

            int req = k - nums[i];

            if ((freq.count(req) > 0) && (freq.count(nums[i]) > 0) && (freq[req] > 0) && (freq[nums[i]] > 0))
            {
                if (req != nums[i])
                {
                    freq[req]--;
                    freq[nums[i]]--;
                    ans++;
                }
                else if (freq[nums[i]] >= 2)
                {
                    freq[req]--;
                    freq[nums[i]]--;
                    ans++;
                }
            }
        }

        return ans;
    }
};
/*
    Q: 1680. Concatenation of Consecutive Binary Numbers
*/
class Solution3_t
{
public:
    int concatenatedBinary(int n)
    {
        const int MOD = 1e7 + 9;
    }
};

/*
    Q: 1681. Minimum Incompatibility - wrong answer
*/
class Solution4_t
{
public:
    int minimumIncompatibility(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());

        unordered_map<int, int> freq;
        for (int n : nums)
        {
            freq[n]++;
        }

        int l = nums.size();
        int sub_set_size = l / k;

        vector<vector<int>> sub_sets;
        for (int i = 0; i < l; ++i)
        {
            if (freq[nums[i]] <= 0)
            {
                continue;
            }

            freq[nums[i]]--;
            vector<int> sub_set;
            sub_set.push_back(nums[i]);
            for (int j = i + 1; j < l; ++j)
            {
                if ((freq[nums[j]] <= 0) || nums[i] == nums[j])
                {
                    continue;
                }

                if (sub_set.size() >= sub_set_size)
                {
                    break;
                }

                freq[nums[j]]--;
                sub_set.push_back(nums[j]);
            }

            if (sub_set.size() != sub_set_size)
            {
                return -1;
            }

            sub_sets.push_back(sub_set);
        }

        int ans = 0;
        for (vector<int> &sub_set : sub_sets)
        {
            ans += sub_set[sub_set_size - 1] - sub_set[0];
        }

        return ans;
    }
};