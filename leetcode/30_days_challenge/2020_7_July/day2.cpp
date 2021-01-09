/****************************************************
Date: July 2nd

link: https://leetcode.com/explore/featured/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3377/
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

using namespace std;

/*
    Q: Binary Tree Level Order Traversal II

    Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

    For example:
        Given binary tree [3,9,20,null,null,15,7],
             3
            / \
            9  20
                /  \
            15   7
        return its bottom-up level order traversal as:
        [
            [15,7],
            [9,20],
            [3]
        ]
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
    unordered_map<int, vector<int>> data;
    void updateValuesForLevel(TreeNode *node, int level, int &max_level)
    {
        if (node == nullptr)
        {
            return;
        }

        data[level].push_back(node->val);

        max_level = max(max_level, level);

        updateValuesForLevel(node->left, level + 1, max_level);
        updateValuesForLevel(node->right, level + 1, max_level);
    }

public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        int maxi = INT_MIN;
        updateValuesForLevel(root, 0, maxi);

        vector<vector<int>> ans;
        while (maxi >= 0)
        {
            ans.push_back(data[maxi]);
            maxi--;
        }

        return ans;
    }
};