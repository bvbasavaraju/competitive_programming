/****************************************************
Date: Sept 20th, 2020
Successful submissions : 3
Time expiration : 0
Not Solved : 1
Wrong Answer/ Partial result : 1
link: https://leetcode.com/contest/weekly-contest-207
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
    Q: 1592. Rearrange Spaces Between Words
*/
class Solution1_t
{
public:
    string reorderSpaces(string text)
    {
        int l = text.size();

        int s_count = 0;
        int w_count = 0;
        for (int i = 0; i < l; ++i)
        {
            if (text[i] == ' ')
            {
                s_count++;
                if ((i > 0) && (text[i - 1] != ' '))
                {
                    w_count++;
                }
            }
        }

        if (text[l - 1] != ' ')
        {
            w_count++;
        }

        if (w_count <= 0 || s_count <= 0)
        {
            return text;
        }

        string e_spaces = "";
        if (w_count > 1)
        {
            for (int i = 0; i < s_count / (w_count - 1); ++i)
            {
                e_spaces += " ";
            }
        }

        string ans = "";
        for (int i = 0; i < l; ++i)
        {
            if (text[i] != ' ')
            {
                ans += text[i];
            }
            else
            {
                if ((ans.size() > 0) && (ans.size() + e_spaces.size() < l))
                {
                    ans += e_spaces;
                }
                for (int k = i; k < l; ++k)
                {
                    if (text[k] == ' ')
                    {
                        i++;
                    }
                    else
                    {
                        break;
                    }
                }
                i--;
            }
        }

        while (ans.size() < l)
        {
            ans += " ";
        }

        return ans;
    }
};

/*
    Q: 1593. Split a String Into the Max Number of Unique Substrings
*/
class Solution2_t
{
private:
    int split(string &s, unordered_set<string> &sub_strs, int p, int sub_count, int &ans)
    {
        if (p >= s.size())
        {
            ans = max(ans, sub_count);
            return -1;
        }

        for (int l = 1; l <= s.size() - p; ++l)
        {
            string sub_str = s.substr(p, l);

            if (sub_strs.find(sub_str) == sub_strs.end())
            {
                sub_strs.insert(sub_str);

                if (split(s, sub_strs, p + l, sub_count + 1, ans) < 0)
                {
                    sub_strs.erase(sub_str);
                    break;
                }

                sub_strs.erase(sub_str);
            }
        }

        ans = max(ans, sub_count);
        return 0;
    }

    unordered_set<string> sub_strs;

public:
    int maxUniqueSplit(string s, int p = 0)
    {
        unordered_set<string> subs;

        int ans = 0;
        split(s, subs, 0, 0, ans);

        return ans;
    }
};

/*
    Q: 1594. Maximum Non Negative Product in a Matrix
*/
class Solution3_t
{
public:
    int maxProductPath(vector<vector<int>> &grid)
    {
        int r = grid.size();
        int c = grid[0].size();

        vector<vector<int>> maxi(r, vector<int>(c, 0));
        vector<vector<int>> mini(r, vector<int>(c, 0));

        maxi[0][0] = mini[0][0] = grid[0][0];
        for (int i = 1; i < r; ++i)
        {
            maxi[i][0] = maxi[i - 1][0] * grid[i][0];
            mini[i][0] = maxi[i][0]; //mini[i-1][0] * grid[i][0];
        }

        for (int i = 1; i < c; ++i)
        {
            maxi[0][i] = maxi[0][i - 1] * grid[0][i];
            mini[0][i] = maxi[0][i]; //mini[0][i-1] * grid[0][i];
        }

        const int MOD = 1e9 + 7;
        for (int i = 1; i < r; ++i)
        {
            for (int j = 1; j < c; ++j)
            {
                long long int maxi_pr = maxi[i - 1][j];
                long long int maxi_pc = maxi[i][j - 1];

                long long int mini_pr = mini[i - 1][j];
                long long int mini_pc = mini[i][j - 1];

                if (grid[i][j] < 0)
                {
                    maxi[i][j] = (min(mini_pr, mini_pc) * (long long int)grid[i][j]) % MOD;
                    mini[i][j] = (max(maxi_pr, maxi_pc) * (long long int)grid[i][j]) % MOD;
                }
                else
                {
                    maxi[i][j] = (max(maxi_pr, maxi_pc) * (long long int)grid[i][j]) % MOD;
                    mini[i][j] = (min(mini_pr, mini_pc) * (long long int)grid[i][j]) % MOD;
                }
            }
        }

        maxi[r - 1][c - 1] = maxi[r - 1][c - 1] % MOD;

        return maxi[r - 1][c - 1] < 0 ? -1 : maxi[r - 1][c - 1];
    }
};

/*
    Q: 1595. Minimum Cost to Connect Two Groups of Points
*/
class Solution4_t
{
public:
    int connectTwoGroups(vector<vector<int>> &cost)
    {
    }
};