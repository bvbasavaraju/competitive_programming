/****************************************************
Date: December 15th, 2019
Successful submissions : 1
Time expiration : 0
Not Solved : 3
Wrong Answer/ Partial result : 1

link: https://leetcode.com/contest/weekly-contest-167
****************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <math.h>

using namespace std;

/*
    Q: 1290. Convert Binary Number in a Linked List to Integer
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution1_t
{
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

public:
    int getDecimalValue(ListNode *head)
    {
        vector<int> b;

        ListNode *t = head;
        while (t != NULL)
        {
            b.push_back(t->val);
            t = t->next;
        }

        int retVal = 0;
        int l = b.size();
        int p = (l - 1);
        for (int i = 0; i < l; i++)
        {
            retVal += b[i] * (pow(2, p));
            p--;
        }

        return retVal;
    }
};

/*
    Q:  1291. Sequential Digits

    Not complete!
*/

class Solution2_t
{
private:
    int getNum(vector<int> n)
    {
        int retVal = 0;
        int p = n.size() - 1;
        for (int i = 0; i < p; i++)
        {
            retVal += n[i] * pow(10, p);
        }

        return retVal;
    }

    void updateToNextSequence(vector<int> &n)
    {
        int start = n[0];
        n[0]++;
        for (int i = 1; i < n.size(); i++)
        {
            n[i] = n[i - 1] + 1;
        }
    }

public:
    vector<int> sequentialDigits(int low, int high)
    {
        stack<int> s;
        int l = low;
        while (l > 0)
        {
            s.push(l % 10);
            l = l / 10;
        }

        vector<int> num;
        while (!s.empty())
        {
            num.push_back(s.top());
            s.pop();
        }

        int lSeq = low;
        bool goToNext = false;
        for (int i = 0; i < (num.size() - 1); i++)
        {
            if ((num[i + 1] - num[i]) > 1)
            {
                goToNext = true;
                break;
            }
            else
            {
                if (num[i + 1] < num[i])
                {
                    num[i + 1] = num[i] + 1;
                }
            }
        }

        if (goToNext)
        {
            updateToNextSequence(num);
        }

        vector<int> retVal;
        while (true)
        {
            int n = getNum(num);
            if (n > high)
            {
                break;
            }

            retVal.push_back(n);
            updateToNextSequence(num);
        }

        return retVal;
    }
};

/*
    Q: 1292. Maximum Side Length of a Square with Sum Less than or Equal to Threshold
*/

class Solution3_t
{
public:
    int maxSideLength(vector<vector<int>> &mat, int threshold)
    {
    }
};

/*
    Q: 1293. Shortest Path in a Grid with Obstacles Elimination

    Not completed
*/

class Solution
{
public:
    int shortestPath(vector<vector<int>> &g, int k)
    {
        int r = g.size();
        int c = g[0].size();
        vector<vector<vector<int>>> r(k - 1, vector<vector<int>>(r, vector<int>(c, 0)));

        for (int x = 0; x < k; x++)
        {
            bool nextK = false;

            int n = x;
            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    // row == 0 && column == 0
                    if ((i == 0) && (j == 0))
                    {
                        if (g[i][j] == 1)
                        {
                            if (n > 0)
                            {
                                n--;
                            }
                            else
                            {
                                nextK = true;
                                break;
                            }
                        }
                    }

                    else if ((i == 0) && (j > 0))
                    {
                        if (g[i][j])
                        {
                            //TODO
                        }
                    }
                }

                if (nextK)
                {
                    break;
                }
            }
        }

        return ((r[k - 1][r - 1][c - 1] == 0) ? -1 : r[k - 1][r - 1][c - 1]);
    }
};