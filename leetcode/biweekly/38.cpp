/****************************************************
Date: Oct 30th, 2020
Successful submissions : 2
Time expiration : 0
Not Solved : 2
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/biweekly-contest-38
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
    Q: 1636. Sort Array by Increasing Frequency
*/
class Solution_1
{
public:
    vector<int> frequencySort(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        for (int &n : nums)
        {
            freq[n]++;
        }

        vector<vector<int>> nums_freq(101);
        for (auto it = freq.begin(); it != freq.end(); ++it)
        {
            nums_freq[it->second].push_back(it->first);
        }

        vector<int> ans;
        for (int i = 1; i < 101; ++i)
        {
            vector<int> &nums_ = nums_freq[i];
            if (nums_.size() == 0)
            {
                continue;
            }

            if (nums_.size() > 1)
            {
                sort(nums_.begin(), nums_.end(), [](const int &n1, const int &n2) -> bool { return (n1 > n2); });
            }

            for (auto temp : nums_)
            {
                for (int j = 0; j < i; ++j)
                {
                    ans.push_back(temp);
                }
            }
        }

        return ans;
    }
};

/*
    Q: 1637. Widest Vertical Area Between Two Points Containing No Points
*/
class Solution2_t
{
public:
    int maxWidthOfVerticalArea(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end(), [](const vector<int> &p1, const vector<int> &p2) -> bool { return (p1[0] < p2[0]); });

        int ans = 0;
        int l = points.size();
        for (int i = 1; i < l; ++i)
        {
            ans = max(ans, points[i][0] - points[i - 1][0]);
        }

        return ans;
    }
};

/*
    Q: 1638. Count Substrings That Differ by One Character - incomplete
*/
class Solution3_t
{
private:
    void calculate(const string &s, const string &t, int sp, int len, int &ans)
    {
        int tl = t.size();

        vector<int> subs_freq(26, 0);
        vector<int> subt_freq(26, 0);

        int j = 0;
        for (j = sp; j < sp + len; ++j)
        {
            subs_freq[s[j] - 'a']++;
            subt_freq[t[j - sp] - 'a']++;
        }

        j = 0;
        while (j < tl)
        {
            int diff_count = 0;
            for (int x = 0; x < 26; ++x)
            {
                if (subs_freq[x] != subt_freq[x])
                {
                    diff_count++;
                }
                if (diff_count > 1)
                {
                    break;
                }
            }

            if (diff_count == 1)
            {
                ans++;
            }

            subt_freq[t[j] - 'a']--;
            j++;
            if (j < tl)
            {
                subt_freq[t[j] - 'a']++;
            }
        }
    }

public:
    int countSubstrings(string s, string t)
    {
        if (s == t)
        {
            return 0;
        }

        int ans = 0;

        int l = min(s.size(), t.size());

        int i = 0;
        for (i = 1; i <= l; ++i)
        {
            calculate(s, t, 0, i, ans);
        }

        if (i < s.size())
        {
            for (; i + l < s.size(); ++i)
            {
                calculate(s, t, i, l, ans);
            }
        }

        for (; i < s.size(); ++i)
        {
            l--;
            calculate(s, t, i, l, ans);
        }

        return ans;
    }
};

/*
    Q: 1639. Number of Ways to Form a Target String Given a Dictionary
*/
class Solution4_t
{
public:
    int numWays(vector<string> &words, string target)
    {
    }
};