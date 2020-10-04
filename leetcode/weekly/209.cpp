/****************************************************
Date: Oct 4th, 2020
Successful submissions : 2
Time expiration : 0
Not Solved : 2
Wrong Answer/ Partial result : 0
link: https://leetcode.com/contest/weekly-contest-209
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
    Q: 1608. Special Array With X Elements Greater Than or Equal X
*/
class Solution1_t
{
public:
    int specialArray(vector<int> &nums)
    {
        int l = nums.size();

        vector<int> count(l + 1, 0);
        for (int n : nums)
        {
            for (int i = 0; (i <= n) && (i <= l); ++i)
            {
                count[i]++;
            }
        }

        int ans = -1;
        for (int i = 0; i < l + 1; ++i)
        {
            if (i == count[i])
            {
                ans = i;
            }
        }

        return ans;
    }
};

/*
    Q: 1609. Even Odd Tree
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution2_t
{
private:
    void collectValuesAtLevel(TreeNode *node, int l, bool &ans, vector<vector<int>> &vals)
    {
        if ((node == NULL) || (!ans))
        {
            return;
        }

        if (vals.size() <= l)
        {
            vector<int> temp;
            temp.push_back(node->val);

            vals.push_back(temp);
        }
        else
        {
            vector<int> &ints = vals[l];
            if (l % 2 == 0)
            {
                if ((ints.back() >= node->val) || (node->val % 2 == 0))
                {
                    ans = false;
                    return;
                }
            }
            else
            {
                if ((ints.back() <= node->val) || (node->val % 2 != 0))
                {
                    ans = false;
                    return;
                }
            }

            ints.push_back(node->val);
        }

        if (l % 2 == 0)
        {
            if (node->val % 2 == 0)
            {
                ans = false;
                return;
            }
        }
        else
        {
            if (node->val % 2 != 0)
            {
                ans = false;
                return;
            }
        }

        collectValuesAtLevel(node->left, l + 1, ans, vals);
        collectValuesAtLevel(node->right, l + 1, ans, vals);
    }

public:
    bool isEvenOddTree(TreeNode *root)
    {
        bool ans = true;
        vector<vector<int>> vals;
        collectValuesAtLevel(root, 0, ans, vals);

        return ans;
    }
};

/*
    Q: 1610. Maximum Number of Visible Points
*/
class Solution3_t
{
public:
    int visiblePoints(vector<vector<int>> &points, int angle, vector<int> &location)
    {
    }
};

/*
    Q: 1611. Minimum One Bit Operations to Make Integers Zero
*/
class Solution4_t
{
public:
    int minimumOneBitOperations(int n)
    {
    }
};