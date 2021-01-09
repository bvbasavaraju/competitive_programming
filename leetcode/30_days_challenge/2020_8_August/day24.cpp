/****************************************************
Date: July 24rd

link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/552/week-4-august-22nd-august-28th/3434/
****************************************************/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <limits.h>
#include <set>

using namespace std;

/*
    Q: Sum of Left Leaves

    Find the sum of all left leaves in a given binary tree.

    Example:

         3
        / \
        9  20
            /  \
         15   7

    There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
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

class Solution
{
private:
    void getLeftLeafVal(TreeNode *node, bool is_left_node, int &ans)
    {
        if (node == NULL)
        {
            return;
        }

        if (is_left_node && node->left == NULL && node->right == NULL)
        {
            ans += node->val;
        }

        getLeftLeafVal(node->left, true, ans);
        getLeftLeafVal(node->right, false, ans);
    }

public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        int ans = 0;
        getLeftLeafVal(root, false, ans);

        return ans;
    }
};