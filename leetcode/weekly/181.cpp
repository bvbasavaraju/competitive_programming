/****************************************************
Date: Mar 22nd, 2020
Successful submissions : 2
Time expiration : 0
Not Solved : 1
Wrong Answer/ Partial result : 1

link: https://leetcode.com/contest/weekly-contest-181
****************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;

/*
    Q:  1389. Create Target Array in the Given Order
*/
class Solution1_t
{
public:
    vector<int> createTargetArray(vector<int> &n, vector<int> &in)
    {
        int l = n.size();

        vector<int> result;
        for (int i = 0; i < l; ++i)
        {
            result.insert(result.begin() + in[i], n[i]);
        }

        return result;
    }
};

/*
    Q:  1390. Four Divisors
*/
class Solution2_t
{
public:
    bool getDivisorsSum(int n, int &result)
    {
        vector<int> divs;
        divs.push_back(1);
        divs.push_back(n);
        for (int i = 2; i <= n / 2; ++i)
        {
            if (n % i == 0)
            {
                divs.push_back(i);

                if (divs.size() > 4)
                {
                    return false;
                }
            }
        }

        if (divs.size() == 4)
        {
            result = divs[0] + divs[1] + divs[2] + divs[3];
        }

        return (divs.size() == 4) ? true : false;
    }

public:
    int sumFourDivisors(vector<int> &n)
    {
        unordered_map<int, int> m;

        int result = 0;
        int l = n.size();
        for (int i = 0; i < l; ++i)
        {
            int sum = 0;
            sum = m[n[i]];
            if ((n[i] > 0) && (sum == 0))
            {
                if (getDivisorsSum(n[i], sum) != false)
                {
                    m[n[i]] = sum;
                }
            }
            else
            {
                sum = m[n[i]];
            }

            result += sum;
        }

        return result;
    }
};

/*
    Q:  1391. Check if There is a Valid Path in a Grid
*/
class Solution3_t
{
private:
    typedef enum
    {
        DIR_UP_TO_DOWN = 0,
        DIR_LEFT_TO_RIGHT = 1
    } Directions_t;

    bool possibleToEndter(int from, int to, Directions_t d)
    {
        bool result = false;
        switch (d)
        {
        case DIR_UP_TO_DOWN:
            if (from == 2 || from == 3 || from == 4)
            {
                if (to == 2 || to == 5 || to == 6)
                {
                    result = true;
                }
            }
            break;

        case DIR_LEFT_TO_RIGHT:
            if (from == 1 || from == 4 || from == 6)
            {
                if (to == 1 || to == 3 || to == 5)
                {
                    result = true;
                }
            }
            break;
        }

        return result;
    }

public:
    bool hasValidPath(vector<vector<int>> &g)
    {
        int r = g.size();
        int c = g[0].size();

        vector<vector<int>> dp(r, vector<int>(c, 0));

        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                if (i == 0 && j == 0)
                {
                    dp[i][j] = 1;
                }
                else if (i == 0)
                {
                    //if(dp[0][j-1])
                    {
                        dp[0][j] = (possibleToEndter(g[0][j - 1], g[0][j], DIR_LEFT_TO_RIGHT) == true) ? 1 : 0;
                    }
                }
                else if (j == 0)
                {
                    //if(dp[i-1][0])
                    {
                        dp[i][0] = (possibleToEndter(g[i - 1][0], g[i][0], DIR_UP_TO_DOWN) == true) ? 1 : 0;
                    }
                }
                else
                {
                    if (dp[i - 1][j])
                    {
                        dp[i][j] = (possibleToEndter(g[i - 1][j], g[i][j], DIR_UP_TO_DOWN) == true) ? 1 : 0;
                    }

                    if ((dp[i][j] == 0) && (dp[i][j - 1]))
                    {
                        dp[i][j] = (possibleToEndter(g[i][j - 1], g[i][j], DIR_LEFT_TO_RIGHT) == true) ? 1 : 0;
                    }
                }

                printf("%d ", dp[i][j]);
            }
            printf("\n");
        }

        return (dp[r - 1][c - 1] == 1);
    }
};

/*
    Q:  1392. Longest Happy Prefix
*/
class Solution4_t
{
public:
    string longestPrefix(string s)
    {
    }
};