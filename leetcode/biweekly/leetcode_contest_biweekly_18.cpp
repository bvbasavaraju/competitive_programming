/****************************************************
Date: Jan 25, 2020
Successful submissions : 3
Time expiration : 
Not Solved : 1
Wrong Answer/ Partial result : 

link: https://leetcode.com/contest/biweekly-contest-18
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
    Q:  Rank Transform of an Array - solved
*/
class Solution1_t
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        int s = arr.size();

        vector<int> as = arr;
        sort(as.begin(), as.end());

        int r = 1;
        map<int, int> ar;
        for (int i = 0; i < s; i++)
        {
            ar[as[i]] = r;
            if ((i < s - 1) && (as[i + 1] > as[i]))
            {
                r++;
            }
        }

        for (int i = 0; i < s; i++)
        {
            int k = arr[i];
            arr[i] = ar[k];
        }

        return arr;
    }
};

/*
    Q:  Break a Palindrome - solved
*/
class Solution2_t
{
public:
    string breakPalindrome(string s)
    {
        int l = s.size();
        bool modified = false;
        for (int i = 0; i < l / 2; ++i)
        {
            if (s[i] != 'a')
            {
                s[i] = 'a';
                modified = true;
                break;
            }
        }

        if (!modified && (l > 1))
        {
            s[l - 1] = 'b';
            modified = true;
        }

        return modified ? s : "";
    }
};

/*
    Q:  Sort the Matrix Diagonally - solved
*/
class Solution3_t
{
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
    {
        int r = mat.size();
        int c = mat[0].size();

        int dl = r + c - 1;
        vector<vector<int>> dNums(dl);
        for (int i = 0; i < r; ++i)
        {
            int k = 0;
            for (int j = c - 1; j >= 0; --j)
            {
                dNums[(k + i) % dl].push_back(mat[i][j]);
                k++;
            }
        }

        for (int i = 0; i < dl; i++)
        {
            sort(dNums[i].begin(), dNums[i].end());
        }

        for (int i = 0; i < r; ++i)
        {
            int k = 0;
            for (int j = c - 1; j >= 0; --j)
            {
                mat[i][j] = dNums[(k + i) % dl][0];
                dNums[(k + i) % dl].erase(dNums[(k + i) % dl].begin());
                k++;
            }
        }

        return mat;
    }
};

/*
    Q:  Reverse Subarray To Maximize Array Value - Not solved
*/
class Solution
{
public:
    int maxValueAfterReverse(vector<int> &nums)
    {
    }
};