/****************************************************
Date: Oct 18th, 2020
Successful submissions : 1
Time expiration : 0
Not Solved : 2
Wrong Answer/ Partial result : 1
link: https://leetcode.com/contest/weekly-contest-211
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
    Q: 1624. Largest Substring Between Two Equal Characters
*/
class Solution1_t
{
public:
    int maxLengthBetweenEqualCharacters(string s)
    {
        int l = s.size();

        int i = 0;
        vector<vector<int>> freq(26);
        for (int ch : s)
        {
            freq[ch - 'a'].push_back(i++);
        }

        int ans = -1;
        for (i = 0; i < l; ++i)
        {
            if (freq[s[i] - 'a'].size() > 1)
            {
                ans = max(ans, freq[s[i] - 'a'].back() - i - 1);
            }
        }

        return ans;
    }
};

/*
    Q: 1625. Lexicographically Smallest String After Applying Operations - not correct
*/
class Solution2_t
{
private:
    int getMin(int num, int a)
    {
        int ans = num;
        int count = a * 2;
        while (count >= 0)
        {
            num = (num + a) % 10;
            ans = min(ans, num);
            count--;
        }

        return ans;
    }

    bool isSmall(const string &s1, const string &s2, int l)
    {
        //printf("%s, %s,", s1.c_str(), s2.c_str());
        for (int i = 0; i < l; ++i)
        {
            if (s1[i] > s2[i])
            {
                return false;
            }
            else if (s1[i] < s2[i])
            {
                return true;
            }
        }

        return false;
    }

public:
    string findLexSmallestString(string s, int a, int b)
    {
        int l = s.size();

        bool same_nums = ((b % 2) == 0);
        for (int i = 0; i < l; ++i)
        {
            int n = s[i] - '0';
            if (i % 2 != 0 || !same_nums)
            {
                n = getMin(n, a);
                s[i] = n + '0';
            }
        }

        string ans = s;
        int count = l * 2;
        while (count >= 0)
        {
            string s1 = s.substr(l - b, b) + s.substr(0, l - b);
            s = s1;
            if (isSmall(s, ans, l))
            {
                ans = s;
            }
            count--;
        }

        return ans;
    }
};

/*
    Q: 1626. Best Team With No Conflicts
*/
class Solution3_t
{
public:
    int bestTeamScore(vector<int> &scores, vector<int> &ages)
    {
    }
};

/*
    Q: 1627. Graph Connectivity With Threshold
*/
class Solution4_t
{
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>> &queries)
    {
    }
};