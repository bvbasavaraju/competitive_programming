/****************************************************
Date: Jan 26, 2020
Successful submissions : 2
Time expiration : 0
Not Solved : 1
Wrong Answer/ Partial result : 1

link: https://leetcode.com/contest/biweekly-contest-173
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
    Q:  1332. Remove Palindromic Subsequences - Wrong answer!!
*/

class Solution1_t
{
private:
    bool IsPalindrome(string &s, int mid, int l, int h, int tl, int rc)
    {
        int k = 0;
        bool e = true;
        for (; k <= rc; ++k)
        {
            e = true;

            int l1 = l + k;
            int h1 = h + k;
            for (int i = 0; i < mid; ++i)
            {
                if (s[l1++] != s[h1--])
                {
                    e = false;
                    break;
                }
            }

            if (e)
            {
                break;
            }
        }

        if (e)
        {
            s.erase(l + k, tl);
            return true;
        }

        return false;
    }

public:
    int removePalindromeSub(string s)
    {
        int ans = 0;
        int l = s.size();
        int tl = l;
        while (l > 0)
        {
            int m = l / 2;
            if (IsPalindrome(s, l / 2, 0, l - 1, l, tl - l))
            {
                ans++;
                l = s.size();
                tl = l;
            }
            else
            {
                l--;
            }
        }

        return ans;
    }
};

/*
    Q:  1333. Filter Restaurants by Vegan-Friendly, Price and Distance - solved
*/
class Solution2_t
{
public:
    vector<int> filterRestaurants(vector<vector<int>> &r, int v, int mP, int mD)
    {
        int l = r.size();
        vector<vector<int>> fR;
        for (int i = 0; i < l; ++i)
        {
            if ((r[i][3] <= mP) && (r[i][4] <= mD))
            {
                if (v == 1)
                {
                    if (r[i][2] == 1)
                    {
                        fR.push_back(r[i]);
                    }
                }
                else
                {
                    fR.push_back(r[i]);
                }
            }
        }

        sort(fR.begin(), fR.end(), [](const vector<int> &s, const vector<int> &d) -> bool {
            if (s[1] == d[1])
            {
                return s[0] < d[0];
            }

            return s[1] < d[1];
        });

        vector<int> result;
        for (int i = fR.size() - 1; i >= 0; --i)
        {
            result.push_back(fR[i][0]);
        }

        return result;
    }
};

/*
    Q:  1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance - Solved
*/

class Solution3_t
{
    int INF = 1e5;
    void print(vector<vector<int>> &m, int d)
    {
        printf("--------------------\n");
        for (int i = 0; i < d; ++i)
        {
            for (int j = 0; j < d; ++j)
            {
                if (m[i][j] == INF)
                {
                    printf("%c ", 'x');
                }
                else
                {
                    printf("%d ", m[i][j]);
                }
            }
            printf("\n");
        }
    }

public:
    int findTheCity(int n, vector<vector<int>> &e, int d)
    {
        //Floyd-Warshel Algorithm
        vector<vector<int>> dM(n, vector<int>(n, INF));
        for (int i = 0; i < e.size(); i++)
        {
            dM[e[i][0]][e[i][1]] = e[i][2];
            dM[e[i][1]][e[i][0]] = e[i][2];
        }

        for (int i = 0; i < n; i++)
        {
            //print(dM, n);
            vector<vector<int>> temp = dM;

            for (int j = 0; j < n; ++j)
            {
                if (j == i)
                {
                    continue;
                }

                for (int k = 0; k < n; ++k)
                {
                    if ((k == i) || (k == j))
                    {
                        continue;
                    }
                    dM[j][k] = min(temp[j][k], temp[j][i] + temp[i][k]);
                }
            }
        }

        //print(dM, n);

        int minCount = INF;
        int minCountPos = INF;
        vector<vector<int>> cities(n);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (dM[i][j] <= d)
                {
                    cities[i].push_back(j);
                }
            }

            /*printf("\n");
      for(auto n : cities[i])
      {
        printf("%d, ", n);
      }
      printf("\n");*/

            if (cities[i].size() <= minCount)
            {
                minCountPos = i;
                minCount = cities[i].size();
            }
        }

        return minCountPos;
    }
};

/*
    Q:  1335. Minimum Difficulty of a Job Schedule - Not Solved!
*/
class Solution
{
private:
    int INF = 1e9;
    int GetSum(vector<int> &a, int l, int h)
    {
        int sum = 0;
        for (int i = l; i <= h; i++)
        {
            sum += a[i];
        }

        return sum;
    }

public:
    int minDifficulty(vector<int> &jD, int d)
    {
        map<int, int> sumMap;
        int sum = INF;
        // int mJobsPerDay = abs(jD.size() - d) + 1;
        // for (int i = 0; i < mJobsPerDay; i++)
        // {
        //     int j = 0;
        //     int dC = d;
        //     int tempSum = 0;
        //     while (dC > 0)
        //     {
        //         tempSum += GetSum(jD, j, mJobsPerDay - 1);
        //     }
        // }

        return sum == INF ? -1 : sum;
    }
};