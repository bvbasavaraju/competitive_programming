/****************************************************
Date: Jan 19, 2020
Successful submissions : 2
Time expiration : 0
Not Solved : 2
Wrong Answer/ Partial result : 0

Note: I was on vacation. Been to hometown for Makara Sankranti festival.

link: https://leetcode.com/contest/biweekly-contest-172
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
    Q:  5316. Print Words Vertically - Solved
*/

class Solution1_t
{
public:
    vector<string> printVertically(string s)
    {
        int n = s.size();
        int c = 0;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == ' ')
            {
                count = max(count, c);
                c = 0;
            }
            else
            {
                c++;
            }
        }
        count = max(count, c);

        vector<string> vs(count, "");
        for (int i = 0, j = 0; i < n; i++)
        {
            j = (j % count);
            if (s[i] != ' ')
            {
                vs[j++] += s[i];
            }
            else
            {
                if (j > 0)
                {
                    while (j < count)
                    {
                        vs[j++] += ' ';
                    }
                }
            }
        }

        //remove the trailing spaces
        for (int i = 0; i < count; i++)
        {
            string t = vs[i];
            int j = t.size() - 1;
            if (t[j] == ' ')
            {
                for (; j >= 0; j--)
                {
                    if (t[j] != ' ')
                    {
                        break;
                    }
                }
                j++;

                string r = t.substr(0, j);
                vs[i] = r;
            }
        }

        return vs;
    }
};

/*
    Q:  5315. Maximum 69 Number - solved
*/

class Solution2_t
{
public:
    int maximum69Number(int num)
    {
        string ns = std::to_string(num);

        int l = ns.size();
        for (int i = 0; i < l; i++)
        {
            if (ns[i] == '6')
            {
                ns[i] = '9';
                break;
            }
        }

        return stoi(ns);
    }
};

/*
    Q:  5317. Delete Leaves With a Given Value
*/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution3_t
{
public:
    TreeNode *removeLeafNodes(TreeNode *root, int target)
    {
    }
};

/*
    Q:  5318. Minimum Number of Taps to Open to Water a Garden
*/
class Solution4_t
{
public:
    int minTaps(int n, vector<int> &ranges)
    {
    }
};