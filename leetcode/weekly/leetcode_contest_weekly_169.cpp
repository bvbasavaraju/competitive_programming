/****************************************************
Date: December 29, 2019
Successful submissions : 3
Time expiration : 0
Not Solved : 1
Wrong Answer/ Partial result : 

link: https://leetcode.com/contest/biweekly-contest-169
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
    Q: 1303 Find N Unique Integers Sum up to Zero
*/
class Solution1_t
{
public:
    vector<int> sumZero(int n)
    {
        vector<int> retVal;
        int loopCount = n / 2 + 1;

        if (n % 2 != 0)
        {
            retVal.push_back(0);
        }

        for (int i = 1; i < loopCount; i++)
        {
            retVal.push_back(i);
            retVal.push_back(i * -1);

            if (retVal.size() >= n)
            {
                break;
            }
        }

        return retVal;
    }
};

/*
    Q: 1304. All Elements in Two Binary Search Trees
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution2_t
{
private:
    void GetValues(TreeNode *r, vector<int> &output)
    {
        if (r != NULL)
        {
            printf("%d,", r->val);
            output.push_back(r->val);

            GetValues(r->left, output);
            GetValues(r->right, output);
        }
    }

public:
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        vector<int> retVal;
        GetValues(root1, retVal);
        GetValues(root2, retVal);

        sort(retVal.begin(), retVal.end());

        return retVal;
    }
};

/*
    Q:  1305. Jump Game III
*/
class Solution3_t
{
private:
    map<int, bool> posResult;
    void IsPossible(vector<int> &a, int s, int l, int p, bool &r)
    {
        if ((p != s) && (r != true) && (p >= 0) && (p < l))
        {
            if (a[p] == 0)
            {
                r = true;
                return;
            }

            posResult[p] = r;

            if (posResult.count(p + a[p]) == 0)
            {
                IsPossible(a, s, l, (p + a[p]), r);
            }

            if (posResult.count(p - a[p]) == 0)
            {
                IsPossible(a, s, l, (p - a[p]), r);
            }
        }
    }

public:
    bool canReach(vector<int> &arr, int start)
    {
        bool retVal = false;

        int l = arr.size();
        int zP = -1;
        for (int i = 0; i < l; i++)
        {
            if (arr[i] == 0)
            {
                zP = i;
                break;
            }
        }

        if ((zP < 0) || (start >= l))
        {
            return retVal;
        }

        if (start == zP)
        {
            return true;
        }

        IsPossible(arr, start, l, start + arr[start], retVal);
        IsPossible(arr, start, l, start - arr[start], retVal);

        return retVal;
    }
};

/*
    Q: 1306. Verbal Arithmetic Puzzle
*/
class Solution4_t
{
public:
    bool isSolvable(vector<string> &words, string result)
    {
    }
};