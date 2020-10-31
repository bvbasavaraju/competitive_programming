/****************************************************
Date: Nov 1st, 2020
Successful submissions : 1
Time expiration : 0
Not Solved : 1
Wrong Answer/ Partial result : 0
Correct submission After time : 2

link: https://leetcode.com/contest/weekly-contest-213
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
    Q: 1640. Check Array Formation Through Concatenation
*/
class Solution1_t
{
public:
    bool canFormArray(vector<int> &arr, vector<vector<int>> &pieces)
    {
        int pl = pieces.size();
        int al = arr.size();

        if (pl == 1)
        {
            return (pieces[0] == arr);
        }

        unordered_map<int, int> arr_pos_map;
        for (int i = 0; i < al; ++i)
        {
            arr_pos_map[arr[i]] = i;
        }

        for (int i = 0; i < pl; ++i)
        {
            vector<int> &p = pieces[i];
            if (p.size() < 2)
            {
                continue;
            }

            int pos_in_map = -1;
            for (int &n : p)
            {
                if (arr_pos_map.count(n) == 0)
                {
                    return false;
                }

                int pos = arr_pos_map[n];
                if ((pos_in_map == -1) || (pos == (pos_in_map + 1)))
                {
                    pos_in_map = pos;
                }
                else
                {
                    return false;
                }
            }
        }

        return true;
    }
};

/*
    Q: 1641. Count Sorted Vowel Strings - after time
*/
class Solution2_t
{
public:
    int countVowelStrings(int n)
    {
        vector<int> count(5, 1);

        for (int i = 1; i < n; ++i)
        {
            for (int j = 1; j < 5; ++j)
            {
                count[j] = count[j - 1] + count[j];
            }
        }

        int ans = 0;
        for (int n : count)
        {
            ans += n;
        }

        return ans;
    }
};

/*
    Q: 1642. Furthest Building You Can Reach - after time
*/
class Solution3_t
{
public:
    int furthestBuilding(vector<int> &h, int b, int l)
    {
        int hl = h.size();

        priority_queue<int, vector<int>, greater<>> used_bricks;

        int ans = 0;
        for (int i = 1; i < hl; ++i)
        {
            int d = h[i] - h[i - 1];
            if (d <= 0)
            {
                ans = i;
                continue;
            }

            if (b >= d)
            {
                b = b - d;
                ans = i;
                used_bricks.push(d);
                continue;
            }
            else
            {
                if (l == 0)
                {
                    break;
                }
                else
                {
                    l--;
                    ans = i;

                    //now check if this can be replaced with previously used bricks
                    if (!used_bricks.empty() && used_bricks.top() > d)
                    {
                        b += used_bricks.top(); //Previous bricks replaced with ladder
                        used_bricks.pop();      // remove that from the collect bricks
                        b -= d;                 // to move to current position, current diff bricks has to be used.
                    }
                }
            }
        }

        return ans;
    }
};

/*
    Q: 1643. Kth Smallest Instructions
*/
class Solution4_t
{
public:
    string kthSmallestPath(vector<int> &destination, int k)
    {
    }
};