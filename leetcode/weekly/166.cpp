/****************************************************
Date: December 8th, 2019
Successful submissions : 2
Time expiration : 0
Not Solved : 1
Wrong Answer/ Partial result : 1

link: https://leetcode.com/contest/weekly-contest-166
****************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

/*
    Q: 1281. Subtract the Product and Sum of Digits of an Integer
*/

class Solution1_t
{
public:
    int subtractProductAndSum(int n)
    {
        int p = 1;
        int s = 0;

        while (n > 0)
        {
            int d = n % 10;
            n = n / 10;

            p *= d;
            s += d;
        }

        return (p - s);
    }
};

/*
    Q: 1282. Group the People Given the Group Size They Belong To
*/

class Solution2_t
{
private:
    struct GroupSize_t
    {
        int s;
        vector<int> g;
    };

public:
    vector<vector<int>> groupThePeople(vector<int> &gs)
    {
        int s = gs.size();

        map<int, GroupSize_t> g;
        for (int i = 0; i < s; i++)
        {
            g[gs[i]].s = gs[i];
            g[gs[i]].g.push_back(i);
        }

        vector<vector<int>> retVal;
        map<int, GroupSize_t>::iterator it;
        for (it = g.begin(); it != g.end(); it++)
        {
            int vs = it->second.s;
            vector<int> c = it->second.g;

            if (vs == c.size())
            {
                retVal.push_back(c);
            }
            else
            { //Divide the collection to group of size vs
                for (int i = 0; i < c.size();)
                {
                    vector<int> temp;

                    for (int j = 0; j < vs; j++)
                    {
                        temp.push_back(c[i++]);
                    }

                    retVal.push_back(temp);
                }
            }
        }

        return retVal;
    }
};

/*
    Q: 1283. Find the Smallest Divisor Given a Threshold
*/

//TODO: Solve. it is wrong for now
class Solution3_t
{
public:
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int s = nums.size();

        int d = 1;
        int sum = threshold;
        while (sum >= threshold)
        {
            sum = 0;
            for (int i = 0; i < s; i++)
            {
                sum += nums[i] / d;

                if ((nums[i] % d) > 0)
                {
                    sum++;
                }

                if (sum >= threshold)
                {
                    d++;
                    break;
                }
            }
        }

        return d;
    }
};

/*
    Q: 1284. Minimum Number of Flips to Convert Binary Matrix to Zero Matrix
*/
class Solution4_t
{
public:
    int minFlips(vector<vector<int>> &mat)
    {
    }
};